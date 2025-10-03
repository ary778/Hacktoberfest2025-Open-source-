class Solution {
public:
//@aryan778
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0}; 
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(degree[i] == 1) q.push(i);
        }
        vector<int> res;
        while(!q.empty()) {
            int sz = q.size();
            res.clear(); 
            for(int i=0; i<sz; i++) {
                int node = q.front(); q.pop();
                res.push_back(node);
                for(int nei : adj[node]) {
                    degree[nei]--;
                    if(degree[nei] == 1) q.push(nei);
                }
            }
        }
        return res; 
    }
};
