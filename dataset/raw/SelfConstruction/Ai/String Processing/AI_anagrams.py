"""
Anagram Checker

Determines whether two strings are anagrams.
"""

def are_anagrams(first_text, second_text):
    """
    Return True if the two strings are anagrams.
    """
    normalized_first = sorted(
        character.lower()
        for character in first_text
        if character.isalnum()
    )

    normalized_second = sorted(
        character.lower()
        for character in second_text
        if character.isalnum()
    )

    return normalized_first == normalized_second


# Example usage
if __name__ == "__main__":
    print(are_anagrams("listen", "silent"))