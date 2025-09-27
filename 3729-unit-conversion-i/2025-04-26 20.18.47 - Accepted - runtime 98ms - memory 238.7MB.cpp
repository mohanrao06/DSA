class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        const int MOD = 1e9 + 7;
        int n = conversions.size() + 1;
        
        // Build graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& conv : conversions) {
            int src = conv[0], tgt = conv[1], factor = conv[2];
            graph[src].push_back({tgt, factor});
        }
        
        vector<long long> base(n, -1); // initially unknown
        base[0] = 1; // 1 unit of type 0
        
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto& neighbor : graph[node]) {
                int nextNode = neighbor.first;
                int factor = neighbor.second;
                
                if (base[nextNode] == -1) { // not visited
                    base[nextNode] = (base[node] * factor) % MOD;
                    q.push(nextNode);
                }
            }
        }
        
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[i] = (int)(base[i] % MOD);
        }
        return ans;
    }
};