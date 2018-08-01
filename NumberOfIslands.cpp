class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        stack<pair<int, int>> points;
        int islands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    pair<int, int> start(i, j);
                    points.push(start);
                    grid[i][j] = '2';
                    islands++;
                    while (!points.empty())
                    {
                        pair<int, int> current = points.top();
                        points.pop();
                        
                        pair<int,int> up(current.first, current.second-1);
                        pair<int,int> down(current.first, current.second+1);
                        pair<int,int> left(current.first-1, current.second);
                        pair<int,int> right(current.first+1, current.second);
                        
                        if (isValid(up, grid))
                        {
                            points.push(up);
                            grid[up.first][up.second] = '2';
                        }
                        if (isValid(down, grid))
                        {
                            points.push(down);
                            grid[down.first][down.second] = '2';
                        }
                        if (isValid(left, grid))
                        {
                            points.push(left);
                            grid[left.first][left.second] = '2';
                        }
                        if (isValid(right, grid))
                        {
                            points.push(right);
                            grid[right.first][right.second] = '2';
                        }
                    }
                }
            }
        }
        return islands;
    }
    
    bool isValid(pair<int,int> p, vector<vector<char>>& grid)
    {
        if (p.first >= 0 && p.first < grid.size() && p.second >= 0 && p.second < grid[0].size())
        {
            if (grid[p.first][p.second] == '1')
            {
                return true;
            }
        }
        return false;
    }
    

};
