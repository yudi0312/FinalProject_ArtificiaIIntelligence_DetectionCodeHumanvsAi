"""
String Switch Case

Converts uppercase letters to lowercase and vice versa.
"""

def switch_case(text):
    """
    Switch the case of each alphabetic character.
    """
    converted_characters = []

    for character in text:
        if character.islower():
            converted_characters.append(character.upper())
        elif character.isupper():
            converted_characters.append(character.lower())
        else:
            converted_characters.append(character)

    return "".join(converted_characters)


# Example usage
if __name__ == "__main__":
    print(switch_case("Hello World!"))