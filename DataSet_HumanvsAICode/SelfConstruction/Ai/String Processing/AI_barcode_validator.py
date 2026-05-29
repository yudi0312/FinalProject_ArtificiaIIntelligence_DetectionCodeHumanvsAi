"""
Barcode Validator (EAN-13)

Validates an EAN-13 barcode using its checksum.
"""

def validate_ean13(barcode):
    """
    Return True if the barcode is a valid EAN-13 code.
    """
    if len(barcode) != 13 or not barcode.isdigit():
        return False

    digits = [int(digit) for digit in barcode]

    checksum_total = 0

    for index in range(12):
        if index % 2 == 0:
            checksum_total += digits[index]
        else:
            checksum_total += digits[index] * 3

    expected_check_digit = (10 - (checksum_total % 10)) % 10

    return expected_check_digit == digits[-1]


# Example usage
if __name__ == "__main__":
    print(validate_ean13("4006381333931"))