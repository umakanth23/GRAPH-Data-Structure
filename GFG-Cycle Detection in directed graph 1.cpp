//problem link : https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

/*

    1. They given edges[][], not adj-list , so i have to build that first, 
    2. For this, ensure, we consider edges.size() ( i made mistake here)
    3. Then use DFS for detecting cycle with help of visited[] and recSt[] (*imp)
    4. Make sure, after completion of source vertex s, make recSt[s] = false
    5. that's it, 

*/

class Solution {
  public:
    
    bool DFSRec(vector<vector<int>> &adj, int s, vector<bool>&visited, vector<bool>&recSt)
    {
        
        visited[s] = true;
        recSt[s] = true;
        
        for(auto u: adj[s])
        {
            if(visited[u]==false)
            {
                if(DFSRec(adj,u,visited, recSt) == true)
                {
                    return true;
                }
                
            }
            else
            {
                if(recSt[u]==true)
                {
                    return true;
                }
            }
            
        }
        
        recSt[s] = false;
        
        return false;
        
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        // lets build adjacency list first
        
        vector<vector<int>>adj(V);
        
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
        }
        
        
        
        
        
        
        // using DFS 
        vector<bool>visited(V,false);
        vector<bool>recSt(V,false);
        
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                //call dfcRec
                if(DFSRec(adj, i, visited,recSt) == true)
                {
                    return true;
                }
                
            }
        }
        
        return false;

        
    }
};