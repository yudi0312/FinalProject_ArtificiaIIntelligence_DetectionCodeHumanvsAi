def median_of_medians(collection, k):
    """
    Return the k-th smallest element (0-indexed) using the Median-of-Medians
    algorithm for guaranteed linear-time selection.
    """
    if len(collection) <= 5:
        return sorted(collection)[k]  # Base case: sort tiny lists directly
 
    # Split into groups of 5 and find each group's median
    chunks = [collection[i:i + 5] for i in range(0, len(collection), 5)]
    medians = [sorted(chunk)[len(chunk) // 2] for chunk in chunks]
 
    # Recursively find the median of medians as pivot
    pivot = median_of_medians(medians, len(medians) // 2)
 
    # Partition around pivot
    low = [x for x in collection if x < pivot]
    equal = [x for x in collection if x == pivot]
    high = [x for x in collection if x > pivot]
 
    if k < len(low):
        return median_of_medians(low, k)
    elif k < len(low) + len(equal):
        return pivot
    else:
        return median_of_medians(high, k - len(low) - len(equal))
 
 
if __name__ == "__main__":
    numbers = [3, 6, 8, 10, 1, 2, 1]
    kth = median_of_medians(numbers, 3)  # 4th smallest (0-indexed k=3)
    print(f"[Median of Medians] 4th smallest element: {kth}")             # → 3
