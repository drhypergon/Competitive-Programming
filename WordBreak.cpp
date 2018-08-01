class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector < vector < bool > > dp(s.size(), vector< bool >(s.size(), false));
        
        for (int xstart = 0; xstart < s.size(); xstart++)
        {
            for (int incr = 0; xstart + incr < s.size(); incr++)
            {
                //cout << s.substr(incr, xstart+1);
                if (inBank(s.substr(incr, xstart+1), wordDict))
                {
                    dp[incr][xstart+incr] = true;
                }
                else if (incr == 0)
                {
                    dp[incr][xstart+incr] = partitionable(xstart, incr, dp);
                }
                //cout << " ";
            }
            //cout << "\n";
        }
        
        
        /*
        for (int i = 0; i < dp.size(); i++)
        {
            for (int j = 0; j < dp[0].size(); j++)
            {
                cout << dp[i][j];
                cout << " ";
            }
            cout << "\n";
        }
        */
        
        return dp[0][s.size()-1];
    }
    
    bool inBank(string s, vector<string> wordDict)
    {
        for (int i = 0; i < wordDict.size(); i++)
        {
            if (wordDict[i] == s)
            {
                return true;
            }
        }
        return false;
    }
    
    bool partitionable(int xstart, int incr, vector<vector<bool>> dp)
    {
        int start = incr;
        int end = xstart + incr;
        
        for (int i = start; i <= end; i++)
        {
            if (dp[start][start+i] && dp[start+i+1][end])
            {
                return true;
            }
        }
        return false;
    }
};
