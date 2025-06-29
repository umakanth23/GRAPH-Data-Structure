
//Link : https://www.geeksforgeeks.org/problems/topological-sort/1

// Using Queue and kahns algorithm


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
    
        //using bfs and kahns algorithm
        
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        
        //building indegree[] array for 
        vector<int>indegree(V,0);
        
        for(int i=0;i<V;i++)
        {
            for(auto u : adj[i])
            {
                indegree[u]++;
            }
        }
        queue<int>q;
    
        // adding all vertices whose indegree = 0 to queue-q;
        
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        
        vector<int>res;
        
        int cnt = 0;
        while(q.empty()==false)
        {
            
            int u = q.front(); q.pop();
            res.push_back(u);
            
            for(auto x:adj[u])
            {
                //decrease indegre[x] by 1, if it becomes 0, add to q
                if(--indegree[x]==0)
                {
                    q.push(x);
                }
            }
            
        }
        
        return res;
        
    }
};



