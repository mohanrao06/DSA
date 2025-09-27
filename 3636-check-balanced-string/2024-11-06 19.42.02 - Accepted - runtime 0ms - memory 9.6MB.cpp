class Solution {
public:
int sum(vector<int> ans){
    int sum=0;
    for(int i=0;i<ans.size();i++){
        sum+=ans[i];
    }
    return sum;
}
    bool isBalanced(string num) {
        vector<int> ans1;
        vector<int> ans2;
        int a,b;
        for(int i=0;i<num.length();i++){
            if(i%2==0){
                ans1.push_back(num[i]-'0');
            }
            else{
                ans2.push_back(num[i]-'0');
            }
        }
        a=sum(ans1);
        b=sum(ans2);
        if(a==b)
        return 1;
        else{
            return 0;
        }

    }
};