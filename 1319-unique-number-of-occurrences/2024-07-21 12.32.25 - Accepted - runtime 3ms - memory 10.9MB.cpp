class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            int cnt=1;
            while(i+1<arr.size()&&arr[i]==arr[i+1]){
                cnt++;
                i++;
            }
            v.push_back(cnt);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++){
            if(v[i]==v[i-1]){
                return false;
            }
        }
        return true;
        
    }
};