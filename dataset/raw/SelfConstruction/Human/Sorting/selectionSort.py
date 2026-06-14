# Python program for implementation of Selection Sort

# Function to do selection sort
def selection_sort(nums):  # time complexity => O(n^2)

	# treverse upto second last element only as the last element automatically sorts
	for i in range(len(nums) - 1):
		min_value = i	# can use built-in min() function to find min value instead of looping
		for j in range(i + 1, len(nums)):
			if nums[j] < nums[min_value]:    # to find the index of the lowest number in nums[i...n-1]
				min_value = j
		nums[i], nums[min_value] = nums[min_value], nums[i]		# swap the min value and value at index i 

