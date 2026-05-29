# Python program for implementation of Merge Sort

# Function to do merge sort
def merge_sort(nums):

	if len(nums) > 1:
		mid = len(nums) // 2
		left = nums[:mid]
		right = nums[mid:]
		# recursve call on each half
		merge_sort(left)
		merge_sort(right)

		# iterators for traversing two halves
		i, j = 0, 0
		# iterators for the main list
		k = 0

		while i < len(left) and j < len(right):
			if left[i] < right[j]:
				nums[k] = left[i]
				i += 1
			else:
				nums[k] = right[j]
				j += 1
			k += 1

		# for all remaining values
		while i < len(left):
			nums[k] = left[i]
			i += 1
			k += 1
		while j < len(right):
			nums[k] = right[j]
			j += 1
			k += 1
