class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        k=-1
        for i in range(0,len(nums)):
            if i!=nums[i]:
                k=k & i
        return 0 if k==-1 else k