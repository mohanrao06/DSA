class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(heights);
       sort(ans.begin(),ans.end());
        int count=0;
        int i=0,j=0;
        while(i<n && j<n){
            if(heights[i]!=ans[j]){
                count++;

            }
            i++;
            j++;
        }
        return count;
        
    }
};