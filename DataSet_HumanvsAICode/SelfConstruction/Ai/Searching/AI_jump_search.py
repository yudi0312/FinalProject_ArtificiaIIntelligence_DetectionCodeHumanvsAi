import math
 
def jump_search(sorted_collection, target):
    """Search a sorted list by jumping in blocks then scanning linearly."""
    length = len(sorted_collection)
    step = int(math.sqrt(length))  # Optimal block/jump size
    previous = 0
 
    # Jump forward until we overshoot the target or reach the end
    while sorted_collection[min(step, length) - 1] < target:
        previous = step
        step += int(math.sqrt(length))
        if previous >= length:
            return -1  # Target not found
 
    # Linear scan within the identified block
    for index in range(previous, min(step, length)):
        if sorted_collection[index] == target:
            return index
 
    return -1  # Target not found
 
 
if __name__ == "__main__":
    sorted_numbers = [0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 55]
    result = jump_search(sorted_numbers, 28)
    print(f"[Jump Search] Target 28 found at index: {result}")     # → 7
