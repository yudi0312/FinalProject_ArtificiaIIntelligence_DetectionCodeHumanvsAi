import os
import pandas as pd

BASE_DIR = r"C:\Users\yudi\Documents\SEMESTER 4\Kecerdasan Artifisial dan Machine Learning\FinalProject_ArtificiaIIntelligence_DetectionCodeHumanvsAi\DataSet_HumanvsAICode\SelfConstruction"

data = []

counter = 1


def get_language(filename):

    ext = os.path.splitext(filename)[1].lower()

    if ext == ".py":
        return "Python"

    elif ext == ".java":
        return "Java"

    elif ext in [".cpp", ".cc", ".cxx"]:
        return "C++"

    elif ext == ".c":
        return "C"

    return "Unknown"


def get_ai_source(category, language):

    if category == "Sorting":
        return "Gemini"

    elif category == "Searching":
        return "Claude"

    elif category == "String Processing":
        return "ChatGPT"

    elif category == "Dynamic Programming":
        return "Claude"

    elif category == "Graph":
        return "Gemini"

    elif category == "Linked List":
        return "Claude"

    elif category == "Stack & Queue":
        return "ChatGPT"

    elif category == "Tree":

        if language == "Java":
            return "Gemini"

        elif language == "C++":
            return "ChatGPT"

    return "Unknown"


for label in ["Human", "Ai"]:

    root_folder = os.path.join(BASE_DIR, label)

    for category in os.listdir(root_folder):

        category_path = os.path.join(root_folder, category)

        if not os.path.isdir(category_path):
            continue

        for file in os.listdir(category_path):

            if not file.endswith(
                (
                    ".py",
                    ".java",
                    ".cpp",
                    ".cc",
                    ".cxx",
                    ".c"
                )
            ):
                continue

            file_path = os.path.join(
                category_path,
                file
            )

            try:

                with open(
                    file_path,
                    "r",
                    encoding="utf-8"
                ) as f:

                    code = f.read()

            except UnicodeDecodeError:

                with open(
                    file_path,
                    "r",
                    encoding="latin-1"
                ) as f:

                    code = f.read()

            language = get_language(file)

            problem_id = f"ProbSC{counter:03d}"

            generated = (
                "Human"
                if label == "Human"
                else "AI"
            )

            if generated == "Human":

                source = "GitHub"

            else:

                source = get_ai_source(
                    category,
                    language
                )

            data.append({

                "problem_id": problem_id,
                "Sample_Code": code,
                "Generated": generated,
                "Language": language,
                "Source": source

            })

            counter += 1


df = pd.DataFrame(data)

output_file = "self_construction_dataset.csv"

df.to_csv(
    output_file,
    index=False,
    encoding="utf-8-sig"
)

print("=" * 60)
print("Dataset berhasil dibuat")
print("=" * 60)

print()

print("Total Data:")
print(len(df))

print()

print("Generated Distribution:")
print(
    df["Generated"].value_counts()
)

print()

print("Language Distribution:")
print(
    df["Language"].value_counts()
)

print()

print("Source Distribution:")
print(
    df["Source"].value_counts()
)

print()

print(
    f"Saved to: {output_file}"
)