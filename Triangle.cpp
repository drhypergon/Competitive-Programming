class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        vector<vector<int>> dp;
        
        for (int i = 0; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if (i != 0 && j > 0 && j < triangle[i].size()-1)
                {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
                else if (i != 0 && j == 0)
                {
                    triangle[i][j] += triangle[i-1][0];
                }
                else if (i != 0 && j == triangle[i].size()-1)
                {
                    triangle[i][j] += triangle[i-1][triangle[i-1].size()-1];
                }
            }
        }
        
        printOut(triangle);
        return *min_element(triangle[triangle.size()-1].begin(), triangle[triangle.size()-1].end());
    }
    
    void printOut(vector<vector<int>> triangle)
    {
        for (int i = 0; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                cout << triangle[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    }
    
};
