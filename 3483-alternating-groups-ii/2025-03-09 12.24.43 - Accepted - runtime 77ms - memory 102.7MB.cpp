class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
       int win=1;
       int ans=0;
       int n=colors.size();
       for(int i=1;i<=n-1+k-1;i++){
            if(colors[i%n]!=colors[(i-1+n)%n]){
                win++;
            }
            else{
                win=1;
            }
            if(win>=k)ans++;
       }
       return ans;
    }
};