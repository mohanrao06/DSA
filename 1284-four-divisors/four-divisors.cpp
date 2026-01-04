class Solution {
public:
    int fun(int n){
        int cnt=0;
        vector<int> div;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
                cnt++;
                if(n/i!=i){
                    div.push_back(n/i);
                    cnt++;
                }
            }
        }
        int sum=0;
        if(div.size()==4){
            for(int i=0;i<div.size();i++){
                sum+=div[i];
            }

        }
        return sum;
    }
    int sumFourDivisors(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=fun(nums[i]);
        }
        return total;
    }
};