## Anggota Tim

| No  | Nama                | NRP        |
|-----|---------------------|------------|
| 1   | Clarissa Aydin R.   | 5027241014 |
| 2   | Putu Yudi Nandanjaya| 5027241080 |
| 3   | Mutiara Diva J.     | 5027241083 |

---

# Final Project: AI-Generated vs Human-Written Code Detection

Proyek ini bertujuan untuk membangun model klasifikasi yang mampu membedakan *source code* yang ditulis oleh manusia (*Human-Written*) dan yang dihasilkan oleh *Artificial Intelligence* (*AI-Generated*). Proyek ini membandingkan pendekatan Machine Learning, Deep Learning, dan Transformer-Based Model untuk menemukan arsitektur terbaik.

## Dataset

Dataset yang digunakan berjumlah **1.000 source code** dengan proporsi seimbang (**50% Human, 50% AI**). Dataset ini merupakan gabungan dari dua sumber:

1. **Open Dataset (700 data):** Dari [Mendeley Dataset](https://data.mendeley.com/datasets/kjh95n54f8/1).
2. **Self-Construction Dataset (300 data):**
* **Human-Written (150 data):** Dikumpulkan secara manual dari repositori GitHub publik (fokus pada struktur data dan algoritma seperti Sorting, Searching, Graph, DP, dll).
* **AI-Generated (150 data):** Dihasilkan menggunakan LLM (ChatGPT, Claude, Gemini) dengan prompt yang mereplikasi data GitHub.

### Distribusi Bahasa Pemrograman

| Bahasa Pemrograman | Jumlah Data |
| --- | --- |
| **Java** | 309 |
| **Python** | 278 |
| **C++** | 273 |
| **C** | 140 |

## Pipeline & Arsitektur Model

Proyek ini mengevaluasi dan membandingkan tiga kategori model:

* **Support Vector Machine (SVM) - Baseline ML:** Menggunakan ekstraksi fitur TF-IDF berbasis token dan *n-gram* untuk menangkap frekuensi kemunculan pola penulisan.
* **Convolutional Neural Network (CNN) - Deep Learning:** Menggunakan *Embedding Layer* dan *Conv1D* untuk mengekstrak hubungan antar token *source code* secara otomatis melalui operasi konvolusi.
* **GraphCodeBERT - Transformer Model:** Model utama yang secara khusus di-*pre-train* untuk *source code*. Model ini tidak hanya melihat urutan token, tetapi juga memanfaatkan *Data Flow Graph* untuk memahami semantik dan hubungan antar variabel.

## Evaluasi & Hipotesis

Semua model dievaluasi menggunakan pembagian data uji yang sama dengan metrik:

* Accuracy
* Precision & Recall
* F1-Score
* Confusion Matrix

**Hipotesis:** GraphCodeBERT diharapkan menghasilkan performa terbaik karena kemampuannya memahami struktur semantik kode, diikuti oleh CNN, dan SVM sebagai *baseline*.

## Repositori & Notebook

**Data & Analisis**

* [Open Dataset (Mendeley)](https://data.mendeley.com/datasets/kjh95n54f8/1)
* [Exploratory Data Analysis (EDA)](https://colab.research.google.com/drive/1wmhWsj5e6S2BKwXgvnJcfF1ftga8xK1M?usp=sharing)
* [Preprocessing Data](https://colab.research.google.com/drive/1r9WoyQfahbbA1wf17CnOCse2QMH4azEM?usp=sharing)

**Training & Modeling**

* [Model SVM](https://colab.research.google.com/drive/1qDQwUdIjAO4DM264CVEfJaUYinpbd4Oz?usp=sharing)
* [Model CNN](https://colab.research.google.com/drive/1XyqnMXDH6q7yWfd6mBhom9VYGMUTIHgf?usp=sharing)
* [Model GraphCodeBERT](https://colab.research.google.com/drive/16pIJzX_4iv_3_5zF0riYkqi9z8DZX9Nd?usp=sharing)
* [Komparasi Model](https://colab.research.google.com/drive/19LfeQFgQFRuz6zKMcb0lPtiN_wcvHnL2?usp=sharing)

**Robustness & Error Analysis**

* [Robustness SVM](https://colab.research.google.com/drive/1u6WhfyZHd7MY1gdVcSFcxwXwj-pxFsKH?usp=sharing) | [Error SVM](https://colab.research.google.com/drive/18gzctXaIsxsR0XVIVEWyzgGiw_c8jZEl?usp=sharing)
* [Robustness CNN](https://colab.research.google.com/drive/1bIwfFJGOjbi_N4u3EfE8WXFxqvYEX6KM?usp=sharing) | [Error CNN](https://colab.research.google.com/drive/1MRRMgyJSzt0y4qA6H4mNq5HBbSx_82x4?usp=sharing)
* [Robustness GraphCodeBERT](https://colab.research.google.com/drive/1_pFck_5pELaqeceprsZRAERiV9o_geBS?usp=sharing) | [Error GraphCodeBERT](https://colab.research.google.com/drive/1Gj9CF2kcfsCB4-SJSobz_Plz_mTzff2O?usp=sharing)
* [Komparasi Robustness Total](https://colab.research.google.com/drive/1LHWCDRkBrzeGVfvczjW2Mp11W_1cJomv?usp=sharing)

## Jurnal Referensi

* [SVM untuk Deteksi Kode AI](https://www.semanticscholar.org/reader/84b96e2cb2619a81e88cd0400b326f89882843c8)
* [Eksplorasi Model CNN](https://www.semanticscholar.org/paper/Exploration-of-Convolutional-Neural-Network-models-Barchi-Parisi/38a0b91e8f34a246998940de5650c8d9cb45ac9f?utm_source=direct_link)
* [GraphCodeBERT: Pre-training Code Representations](https://www.semanticscholar.org/paper/GraphCodeBERT%3A-Pre-training-Code-Representations-Guo-Ren/4083958684292f6fa2f5c7fd4f9be975e80145b6?utm_source=direct_link)
