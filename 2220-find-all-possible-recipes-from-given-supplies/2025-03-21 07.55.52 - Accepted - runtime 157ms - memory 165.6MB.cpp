class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_map<string,vector<string>> graph;
        unordered_map<string,int>indegree;
        for(int i=0;i<recipes.size();i++){
            for(auto it:ingredients[i]){
                graph[it].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for(auto s:supplies){
            q.push(s);
        }

        set<string> made;
        while(!q.empty()){
            string curr=q.front();
            q.pop();
            for(auto next:graph[curr]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                    made.insert(next);
                }


            }        
        }
        vector<string> res;
        for(auto it:made){
            if(made.count(it)){
                res.push_back(it);
            }
        }
        return res;
    }
};