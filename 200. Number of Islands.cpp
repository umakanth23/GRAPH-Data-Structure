
//problem link : https://leetcode.com/problems/number-of-islands/description/
/*using DFS */


class Solution {
public:
    bool isValid(int i, int j, int m, int n, vector<vector<char>>& grid)
    {
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]=='1')
        {
            return true;
        }
        return false;
    }

    void numIslandsRec( int i, int j,int m,int n,vector<vector<char>>& grid)
    {
        
        grid[i][j]='0';
        if(isValid(i+1,j,m,n,grid))
            numIslandsRec(i+1,j,m,n,grid);
        
        if(isValid(i-1,j,m,n,grid))
            numIslandsRec(i-1,j,m,n,grid);
        
        if(isValid(i,j+1,m,n,grid))
            numIslandsRec(i,j+1,m,n,grid);
        
        if(isValid(i,j-1,m,n,grid))
            numIslandsRec(i,j-1,m,n,grid);

    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] =='1')
                {
                    cnt++;
                    numIslandsRec( i, j,m,n,grid);
                }
            }
        }    
        return cnt;
    }
};


