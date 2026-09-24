class Solution:
    def twoSum(self, li: list[int], target: int) -> list[int]:
        seen={}
        for i in range(len(li)):
            diff=target-li[i]
            if diff in seen:
                return [seen[diff],i]
            seen[li[i]]=i
        return []