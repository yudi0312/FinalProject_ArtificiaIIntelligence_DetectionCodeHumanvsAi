"""
Hamming Distance

Calculates the number of differing positions
between two strings of equal length.
"""

def hamming_distance(first_text, second_text):
    """
    Return the Hamming distance between two strings.
    """
    if len(first_text) != len(second_text):
        raise ValueError(
            "Strings must have the same length."
        )

    distance = 0

    for first_char, second_char in zip(
        first_text,
        second_text
    ):
        if first_char != second_char:
            distance += 1

    return distance


# Example usage
if __name__ == "__main__":
    print(hamming_distance("karolin", "kathrin"))