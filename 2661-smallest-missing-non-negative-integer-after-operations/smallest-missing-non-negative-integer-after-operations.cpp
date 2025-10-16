class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num<0){
                num=(num)%value+value;

            }
            num=num%value;
            mp[num]++;

        }
        int ans=0;
        int req=0;
        while(1){
            if(mp[req]>0){
                mp[req]--;
                ans++;
            }else{
                break;

            }
            req=(req+1)%value;
        }
        return ans;

    }
};