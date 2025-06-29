

//link : 
/*
    1. Using topological sorting kahn's algorithm
    2. topological sort is only used for Directed acyclic graph (DAG)
    3. if topological does work for this, then it doesn't cycle
    4. if doesn't work, that means, it has cycle.
*/


class Solution {

  public:
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
            
        
        //BFS Solution    
        // lets build adjacency list first
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
        
        int cnt = 0;
        while(q.empty()==false)
        {
            
            int u = q.front(); q.pop();
            cnt++;
            
            for(auto x:adj[u])
            {
                //decrease indegre[x] by 1, if it becomes 0, add to q
                if(--indegree[x]==0)
                {
                    q.push(x);
                }
            }
            
        }
        
        return !(cnt==V);
        
        
    }
};