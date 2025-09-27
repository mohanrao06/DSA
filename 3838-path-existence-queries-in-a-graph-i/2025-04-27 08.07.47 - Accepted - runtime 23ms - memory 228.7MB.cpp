class Solution {
public:
    vector<int> parent;
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }
    
    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        // Connect adjacent nodes if their nums difference <= maxDiff
        for (int i = 0; i < n-1; i++) {
            if (nums[i+1] - nums[i] <= maxDiff) {
                unite(i, i+1);
            }
        }
        
        vector<bool> answer;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            answer.push_back(find(u) == find(v));
        }
        
        return answer;
    }
};