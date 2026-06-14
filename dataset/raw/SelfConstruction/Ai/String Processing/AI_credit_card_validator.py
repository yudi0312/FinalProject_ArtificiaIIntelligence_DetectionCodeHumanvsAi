"""
Credit Card Validator

Validates a credit card number using the Luhn algorithm.
"""

def validate_credit_card(card_number):
    """
    Return True if the card number passes the Luhn check.
    """
    cleaned_number = card_number.replace(" ", "")

    if not cleaned_number.isdigit():
        return False

    digits = [int(digit) for digit in cleaned_number]

    checksum = 0
    should_double = False

    for digit in reversed(digits):
        if should_double:
            digit *= 2

            if digit > 9:
                digit -= 9

        checksum += digit
        should_double = not should_double

    return checksum % 10 == 0


# Example usage
if __name__ == "__main__":
    print(validate_credit_card("4532015112830366"))