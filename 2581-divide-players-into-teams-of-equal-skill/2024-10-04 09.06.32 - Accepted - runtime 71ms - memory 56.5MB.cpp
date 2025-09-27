class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long ans=0;
        int i=0;
        int j=skill.size()-1;
        sort(skill.begin(),skill.end());
        int sum=skill[i]+skill[j];
        while(i<j){
            
            if(skill[i]+skill[j]==sum){
                ans+=skill[i]*skill[j];
                i++;
                j--;
            }else{
                return -1;
            }
            

        }
        return ans;

    }
};