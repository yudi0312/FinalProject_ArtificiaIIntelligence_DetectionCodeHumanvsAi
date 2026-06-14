"""
Frequency Finder

Finds the frequency of each character in a string.
"""

def character_frequency(text):
    """
    Return a dictionary containing character frequencies.
    """
    frequencies = {}

    for character in text:
        frequencies[character] = (
            frequencies.get(character, 0) + 1
        )

    return frequencies


# Example usage
if __name__ == "__main__":
    print(character_frequency("banana"))