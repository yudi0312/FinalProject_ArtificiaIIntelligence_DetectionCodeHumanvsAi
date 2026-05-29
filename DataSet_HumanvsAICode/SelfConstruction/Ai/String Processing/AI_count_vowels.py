"""
Count Vowels

Counts the number of vowels in a string.
"""

def count_vowels(text):
    """
    Return the total number of vowels.
    """
    vowels = {"a", "e", "i", "o", "u"}

    vowel_count = 0

    for character in text.lower():
        if character in vowels:
            vowel_count += 1

    return vowel_count


# Example usage
if __name__ == "__main__":
    print(count_vowels("Hello World"))