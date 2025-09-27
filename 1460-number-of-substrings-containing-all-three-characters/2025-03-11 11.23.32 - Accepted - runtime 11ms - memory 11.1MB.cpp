class Solution {
public:
    int numberOfSubstrings(string s) {
    int left=0;
    int right=0;
    vector<int> freq(3,0);
    int num=0;
    while(right<s.size()){
        freq[s[right]-'a']++;
        while(freq[0] && freq[1] && freq[2]){
            num+=s.size()-right;
            freq[s[left]-'a']--;
            left++;
        }
        right++;
    }
    return num;
}
    
};