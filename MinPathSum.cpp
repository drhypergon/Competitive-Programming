class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {        
        vector < vector < int > > paths(grid.size(), vector< int >(grid[0].size(), INT_MAX));
        paths[0][0] = grid[0][0];
        
        for (int i = 0; i < paths.size(); i++)
        {
            for (int j = 0; j < paths[0].size(); j++)
            {
                if ((i-1) < 0)
                {
                    paths[i][j] = grid[i][j] + paths[i][j-1];
                }
                else if ((j-1) < 0)
                {
                    paths[i][j] = grid[i][j] + paths[i-1][j];
                }
                else
                {
                    paths[i][j] = grid[i][j] + std::min(paths[i-1][j], paths[i][j-1]);
                }
            }
        }
        return paths[paths.size()-1][paths[0].size()-1];
    }
    
    /*
    int pathSum(int i , int j, vector<vector<int>>&grid)
    {
        if (i == 0 && j == 0)
        {
            return grid[0][0];
        }
        if (i < 0 || j < 0)
        {
            return INT_MAX;
        }
        return grid[i][j] + std::min(pathSum(i-1, j, grid), pathSum(i, j-1, grid));
    }
    */
};
