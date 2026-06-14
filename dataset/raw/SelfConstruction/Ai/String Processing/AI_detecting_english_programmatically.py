"""
Detecting English Programmatically

Uses a simple English word list to estimate whether
a text is written in English.
"""

COMMON_ENGLISH_WORDS = {
    "the", "be", "to", "of", "and",
    "a", "in", "that", "have", "i",
    "is", "it", "for", "not", "on",
    "with", "he", "as", "you", "do"
}


def is_probably_english(text, threshold=0.3):
    """
    Return True if the text appears to be English.
    """
    words = [
        word.lower().strip(".,!?;:")
        for word in text.split()
    ]

    if not words:
        return False

    matched_words = sum(
        1 for word in words
        if word in COMMON_ENGLISH_WORDS
    )

    ratio = matched_words / len(words)

    return ratio >= threshold


# Example usage
if __name__ == "__main__":
    sample_text = "This is a simple example of English text."
    print(is_probably_english(sample_text))