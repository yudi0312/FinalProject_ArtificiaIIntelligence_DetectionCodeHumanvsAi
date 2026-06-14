import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("HumanVsAI_CodeDataset.csv")
distribution = df['Generated'].value_counts()

print("Distribution Counts:")
print(distribution)

fig, ax = plt.subplots()
distribution.plot(kind='bar', ax=ax, color=['skyblue', 'salmon'])
ax.set_title('Distribusi Code (AI vs Human)')
ax.set_xlabel('Kategori')
ax.set_ylabel('Jumlah')
plt.xticks(rotation=0)
plt.tight_layout()
plt.show()

human = df[df["Generated"] == "Human"].sample(
    n=350,
    random_state=42
)

ai = df[df["Generated"] == "AI"].sample(
    n=350,
    random_state=42
)

open_dataset = pd.concat([human, ai])

open_dataset = open_dataset.sample(
    frac=1,
    random_state=42
).reset_index(drop=True)

open_dataset.to_csv(
    "OpenDataset.csv",
    index=False
)

print(open_dataset["Generated"].value_counts())
print("\nFile berhasil disimpan: OpenDataset.csv")