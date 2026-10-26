class Solution:
    def maxArea(self, height: list[int]) -> int:
        l=0
        n=len(height)
        r=n-1
        ans=0
        while l<r:
            area=r-l
            water=area*min(height[l],height[r])
            ans=max(ans,water)

            if height[l]<height[r]:
                l+=1
            else:
                r-=1
        return ans
