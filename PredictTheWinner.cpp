class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) 
    {
        vector<vector<pair<int,int> > > dp(nums.size(), vector<pair<int,int> >(nums.size()));
        
        for (int xstart = 0; xstart < nums.size(); xstart++)
        {
            for (int incr = 0; xstart+incr < nums.size(); incr++)
            {
                int xcoord = xstart + incr;
                int ycoord = incr;
                
                if (xcoord == ycoord)
                {
                    pair<int, int> p (nums[xcoord], 0);
                    dp[ycoord][xcoord] = p;
                }
                else if (xcoord == ycoord+1)
                {
                    int xval = max(nums[xcoord], nums[ycoord]);
                    int yval = min(nums[xcoord], nums[ycoord]);
                    pair<int, int> p (xval, yval);
                    dp[ycoord][xcoord] = p;
                }
                else
                {
                    
                    
                    int val1 = dp[ycoord+1][xcoord].second + nums[ycoord];
                    int val2 = dp[ycoord][xcoord-1].second + nums[xcoord];
                    
                    if (val1 > val2)
                    {
                        pair<int,int> p (val1, dp[ycoord+1][xcoord].first);
                        dp[ycoord][xcoord] = p;
                    }
                    else
                    {
                        pair<int, int> p (val2, dp[ycoord][xcoord-1].first);
                        dp[ycoord][xcoord] = p;
                    }
                    
                }
            }
        }
        printGrid(dp);
        return (dp[0][nums.size()-1].first >= dp[0][nums.size()-1].second);
    }
    
    void printGrid (vector<vector<pair<int,int>>> dp)
    {
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp.size(); j++)
            {
                cout << "(";
                cout << dp[i][j].first;
                cout << ",";
                cout << dp[i][j].second;
                cout << ")";
                cout << "    ";
            }
            cout << "\n";
        }
    }
};
