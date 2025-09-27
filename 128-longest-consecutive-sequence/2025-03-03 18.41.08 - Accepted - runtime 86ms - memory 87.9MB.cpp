class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if (nums.empty()) return 0;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }

        int max_cnt=1;
        
        for(auto it: st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int x=it;
                while(st.find(x+1) != st.end()){
                    x=x+1;
                    cnt=cnt+1;
                }
                max_cnt=max(cnt,max_cnt);
            }
        }
        
        

        
        return max_cnt;
    }
};