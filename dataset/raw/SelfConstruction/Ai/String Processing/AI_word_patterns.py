"""
Word Patterns

Checks whether a pattern matches a sequence of words.
"""

def follows_pattern(pattern, sentence):
    """
    Return True if the sentence follows the given pattern.
    """
    words = sentence.split()

    if len(pattern) != len(words):
        return False

    pattern_to_word = {}
    word_to_pattern = {}

    for pattern_char, word in zip(pattern, words):
        if pattern_char in pattern_to_word:
            if pattern_to_word[pattern_char] != word:
                return False
        else:
            pattern_to_word[pattern_char] = word

        if word in word_to_pattern:
            if word_to_pattern[word] != pattern_char:
                return False
        else:
            word_to_pattern[word] = pattern_char

    return True


# Example usage
if __name__ == "__main__":
    print(follows_pattern("abba", "dog cat cat dog"))