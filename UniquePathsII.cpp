class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        vector < vector < int > > result(obstacleGrid.size(), vector< int >(obstacleGrid[0].size(), 0 ));
        
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[0].size(); j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    result[i][j] = 0;
                }
                else if (i != 0 && j != 0)
                {
                    result[i][j] = result[i-1][j] + result[i][j-1]; 
                }
                else if (i != 0 && j == 0)
                {
                    result[i][j] = result[i-1][j];
                }
                else if (i == 0 && j != 0)
                {
                    result[i][j] = result[i][j-1];
                }
                else
                {
                    result[i][j] = 1;
                }
            }
        }
        return result[result.size()-1][result[0].size()-1];
    }
};
