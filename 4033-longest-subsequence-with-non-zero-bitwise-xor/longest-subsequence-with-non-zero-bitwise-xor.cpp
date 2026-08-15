class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        cout<<n<<endl;
        int XOR=0;
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
            ans++;
        }
        if(XOR!=0)return ans;
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
            if(XOR){
                ans--;
                break;
            }
        }
        return ans==n?0:ans;
    }
};