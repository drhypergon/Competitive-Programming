
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        int circles = 0;
        stack<int> s;
        vector<int> visited;
        
        for (int i = 0; i < M.size(); i++)
        {
            if (!beenVisited(visited, i))
            {
                s.push(i);
                visited.push_back(i);
                circles++;
                while (!s.empty())
                {
                    int current = s.top();
                    s.pop();
                    
                    for (int j = 0; j < M.size(); j++)
                    {
                        if (!beenVisited(visited, j))
                        {
                            if (M[current][j] == 1)
                            {
                                visited.push_back(j);
                                s.push(j);
                            }
                        }
                    }
                }
            }
        }
        return circles;
    }
    
    bool beenVisited(vector<int> visited, int val)
    {
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] == val)
            {
                return true;
            }
        }
        return false;
    }
};
