def two_sum(nums, target):
    hash_map = {}  # Dictionary to store value -> index mapping

    for i, num in enumerate(nums):
        complement = target - num

        # Check if complement is already in the hash map
        if complement in hash_map:
            return [hash_map[complement], i]

        # Store the index of the current number
        hash_map[num] = i

    return None  # Return None if no solution is found

# Example usage with random input
nums = list(map(int, input("Enter the elements of the array: ").split()))
target = int(input("Enter the target value: "))

result = two_sum(nums, target)

if result:
    print(f"Indices: {result[0]}, {result[1]}")
else:
    print("No solution found.")
