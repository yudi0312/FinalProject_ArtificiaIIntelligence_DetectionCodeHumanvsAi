import os
import pandas as pd

BASE_DIR = r"C:\Users\yudi\Documents\SEMESTER 4\Kecerdasan Artifisial dan Machine Learning\Final Project\FinalProject_ArtificiaIIntelligence_DetectionCodeHumanvsAi\DataSet_HumanvsAICode\SelfConstruction"

data = []

counter = 1

# Mapping source AI
AI_SOURCE_MAP = {
    "Sorting": "Gemini",
    "Searching": "Claude",
    "String Processing": "ChatGPT",
    "Dynamic Programming": "Claude",
    "Graph": "Claude",
    "Linked List": "Claude",
    "Stack & Queue": "Claude",
    "Tree": "Claude"
}

for label in ["Human", "Ai"]:

    root_folder = os.path.join(BASE_DIR, label)

    for category in os.listdir(root_folder):

        category_path = os.path.join(root_folder, category)

        if not os.path.isdir(category_path):
            continue

        for file in os.listdir(category_path):

            if not file.endswith(".py"):
                continue

            file_path = os.path.join(category_path, file)

            try:
                with open(file_path, "r", encoding="utf-8") as f:
                    code = f.read()

            except UnicodeDecodeError:
                with open(file_path, "r", encoding="latin-1") as f:
                    code = f.read()

            problem_id = f"ProbSC{counter:03d}"

            generated = "Human" if label == "Human" else "AI"

            if generated == "Human":
                source = "GitHub"
            else:
                source = AI_SOURCE_MAP.get(category, "Unknown")

            data.append({
                "problem_id": problem_id,
                "Sample_Code": code,
                "Generated": generated,
                "Language": "Python",
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

print("=" * 50)
print("Dataset berhasil dibuat!")
print(f"Total data : {len(df)}")
print(f"Output     : {output_file}")
print("=" * 50)

print(df["Generated"].value_counts())