"""
Word Occurrence Counter

Counts how many times each word appears in a text.
"""

def count_word_occurrences(text):
    """
    Return a dictionary containing word frequencies.
    """
    word_counts = {}

    words = text.lower().split()

    for word in words:
        word_counts[word] = word_counts.get(word, 0) + 1

    return word_counts


# Example usage
if __name__ == "__main__":
    sample_text = "apple banana apple orange banana apple"
    print(count_word_occurrences(sample_text))