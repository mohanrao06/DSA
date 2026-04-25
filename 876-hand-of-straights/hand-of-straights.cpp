class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        if(hand.size() % groupSize != 0) return false;
        int n=hand.size();
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        while(!mp.empty()){
            int x=mp.begin()->first;
            
            for(int i=0;i<groupSize;i++){
                if(mp.find(x)==mp.end())return false;
                else{
                    mp[x]--;
                    if(mp[x]<1){
                        mp.erase(x);
                    }
                    x=x+1;
                }
            }
        }
        return true;
    }
};