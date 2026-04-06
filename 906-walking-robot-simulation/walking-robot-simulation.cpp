class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int n=commands.size();
        unordered_set<string> mp;
        for(int i=0;i<obstacles.size();i++){
            string temp=to_string(obstacles[i][0])+"_"+to_string(obstacles[i][1]);
            mp.insert(temp);
        }
        int x=0;
        int y=0;
        pair<int,int> direction={0,1};
        int ans=0;
        for(int i=0;i<n;i++){
            if(commands[i]==-2){
                direction={-direction.second,direction.first};
            }else if(commands[i]==-1){
                direction={direction.second,-direction.first};
            }
            else{
                for(int j=0;j<commands[i];j++){
                    int nx=x+direction.first;
                    int ny=y+direction.second;
                    string temp=to_string(nx)+"_"+to_string(ny);
                    if(mp.find(temp)!=mp.end())break;
                    x=nx;
                    y=ny;

                }
            }

            ans=max(ans,x*x+y*y);
        }
        return ans;
    }
};