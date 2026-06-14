"""
Bitap String Match

Performs exact string matching using the Bitap algorithm.
"""

def bitap_search(text, pattern):
    """
    Return the starting index of the first match.
    Return -1 if the pattern is not found.
    """
    pattern_length = len(pattern)

    if pattern_length == 0:
        return 0

    if pattern_length > 63:
        raise ValueError(
            "Pattern length must be 63 characters or fewer."
        )

    character_masks = {}

    for character in set(text + pattern):
        character_masks[character] = ~0

    for index, character in enumerate(pattern):
        character_masks[character] &= ~(1 << index)

    current_state = ~1

    for index, character in enumerate(text):
        current_state |= character_masks.get(character, ~0)
        current_state <<= 1

        if (current_state & (1 << pattern_length)) == 0:
            return index - pattern_length + 1

    return -1


# Example usage
if __name__ == "__main__":
    print(bitap_search("hello world", "world"))