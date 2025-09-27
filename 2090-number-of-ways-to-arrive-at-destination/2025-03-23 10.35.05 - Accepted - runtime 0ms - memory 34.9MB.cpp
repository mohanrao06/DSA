class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
    for (auto& it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    // Min-Heap (Dijkstra's Algorithm)
   priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<long long> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    
    int MOD = 1e9 + 7;
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});  // {distance, node}

    while (!pq.empty()) {
        auto [dis, node] = pq.top();
        pq.pop();

        for (auto& [adjnode, adjwt] : adj[node]) {
            long long newDist = dis + adjwt;

            // If a shorter path is found
            if (newDist < dist[adjnode]) {
                dist[adjnode] = newDist;
                pq.push({newDist, adjnode});
                ways[adjnode] = ways[node];  
            }
            // If another shortest path is found
            else if (newDist == dist[adjnode]) {
                ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
            }
        }
    }

    return ways[n - 1];
    }

};