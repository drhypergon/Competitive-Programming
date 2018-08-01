class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        stack<pair<int, int>>s;
        int max = 0;
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int currentsize = 0;
                if (grid[i][j] == 1)
                {
                    pair<int, int> p (i, j);
                    s.push(p);
                    grid[i][j] = 2;
                    while (!s.empty())
                    {
                        pair<int, int> current = s.top();
                        s.pop();
                        
                        pair<int, int> up (current.first, current.second-1);
                        pair<int, int> down(current.first, current.second+1);
                        pair<int, int> left(current.first-1, current.second);
                        pair<int, int> right(current.first+1, current.second);
                        
                        if (isValid(up, grid) && grid[up.first][up.second] == 1)
                        {
                            grid[up.first][up.second] = 2;
                            s.push(up);
                        }
                        if (isValid(down, grid) && grid[down.first][down.second] == 1)
                        {
                            grid[down.first][down.second] = 2;
                            s.push(down);
                        }
                        if (isValid(left, grid) && grid[left.first][left.second] == 1)
                        {
                            grid[left.first][left.second] = 2;
                            s.push(left);
                        }
                        if (isValid(right, grid) && grid[right.first][right.second] == 1)
                        {
                            grid[right.first][right.second] = 2;
                            s.push(right);
                        }
                        currentsize++;
                    }
                }
                if (currentsize > max)
                {
                    max = currentsize;
                }
            }
        }
        return max;
        
    }
    
    bool isValid(pair<int, int> p, vector<vector<int>>& grid)
    {
        if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    
};
