"""
Palindrome Checker

Checks whether a given string reads the same forward and backward.
"""

def is_palindrome(text):
    """
    Return True if the input text is a palindrome.
    """
    normalized_text = "".join(
        character.lower()
        for character in text
        if character.isalnum()
    )

    return normalized_text == normalized_text[::-1]


# Example usage
if __name__ == "__main__":
    sample_text = "A man, a plan, a canal: Panama"
    print(is_palindrome(sample_text))