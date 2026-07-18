class Solution {
public:
    int GCD(int x,int y){
        return y==0?x:GCD(y,x%y);
    }
    int findGCD(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        return GCD(mini,maxi);
    }
};