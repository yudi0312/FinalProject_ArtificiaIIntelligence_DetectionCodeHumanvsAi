"""
Camel Case To Snake Case Converter
"""

def camel_to_snake(camel_case_text):
    """
    Convert camelCase or PascalCase into snake_case.
    """
    snake_case_characters = []

    for index, character in enumerate(camel_case_text):
        if character.isupper() and index > 0:
            snake_case_characters.append("_")

        snake_case_characters.append(character.lower())

    return "".join(snake_case_characters)


# Example usage
if __name__ == "__main__":
    print(camel_to_snake("CamelCaseExample"))