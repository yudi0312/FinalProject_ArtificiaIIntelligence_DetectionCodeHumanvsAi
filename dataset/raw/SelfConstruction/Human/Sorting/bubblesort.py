# Python program for implementation of Bubble Sort

# Function to do bubble sort
def bubble_sort(nums): 	# time complexity => O(n^2)

	# traverse from back
	for i in range(len(nums) - 1, 0, -1):
		# consider only elements upto i since beyond i everything willl be sorted
		for j in range(i):
			if nums[j + 1] < nums[j]:
				nums[j + 1], nums[j] = nums[j], nums[j + 1]	 # swap the numbers 
