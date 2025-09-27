class Solution {
public:
    long long minimumSteps(string s) {
        int i=0;
        
        long long count=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='0'){
                count+=(j-i);
                i++;
            }
        }
        
        return count;
    }
};