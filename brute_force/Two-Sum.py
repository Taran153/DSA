class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
         n = len(nums)
         for i in range(n - 1):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    return [i, j]
         return []  # No solution found
#The time complexity of this brute-force approach is 𝑂(𝑛^2) due to the nested loops.
#The space complexity is 𝑂(1) because it uses a constant amount of extra space.