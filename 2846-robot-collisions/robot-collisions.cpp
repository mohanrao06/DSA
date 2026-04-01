class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        // position, health, direction, original index
        vector<tuple<int,int,char,int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({positions[i], healths[i], directions[i], i});
        }

        // ✅ SORT by position
        sort(arr.begin(), arr.end());

        stack<int> st;

        for(int i = 0; i < n; i++){
            auto &[pos, health, dir, idx] = arr[i];

            if(dir == 'R'){
                st.push(i);
            } 
            else {
                while(!st.empty() && get<2>(arr[st.top()]) == 'R' && get<1>(arr[st.top()]) < health){
                    st.pop();
                    health -= 1;
                }

                if(!st.empty() && get<2>(arr[st.top()]) == 'R' && get<1>(arr[st.top()]) == health){
                    st.pop();
                }
                else if(!st.empty() && get<2>(arr[st.top()]) == 'R' && get<1>(arr[st.top()]) > health){
                    get<1>(arr[st.top()]) -= 1;
                }
                else {
                    st.push(i);
                }
            }
        }

        // collect survivors
        vector<pair<int,int>> temp; // {original index, health}

        while(!st.empty()){
            int i = st.top(); st.pop();
            temp.push_back({get<3>(arr[i]), get<1>(arr[i])});
        }

        // ✅ restore original order
        sort(temp.begin(), temp.end());

        vector<int> ans;
        for(auto &it : temp){
            ans.push_back(it.second);
        }

        return ans;
    }
};