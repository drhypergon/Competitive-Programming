class Solution {
public:
    string longestPalindrome(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        if (s.empty())
        {
            return "";
        }
        for (int xstart = 0; xstart < s.size(); xstart++)
        {
            for (int incr = 0; xstart+incr < s.size(); incr++)
            {
                //cout << xstart;
                if (xstart == 0)
                {
                    dp[incr][xstart+incr] = true;
                }
                else if (xstart == 1)
                {
                    if (s.at(incr) == s.at(xstart+incr))
                    {
                        dp[incr][xstart+incr] = true;
                    }
                    else
                    {
                        dp[incr][xstart+incr] = false;
                    }
                }
                else
                {

                    if (dp[incr+1][xstart+incr-1])
                    {
                        if (s.at(incr) == s.at(xstart+incr))
                        {
                            dp[incr][xstart+incr] = true;
                        }
                        else
                        {
                            dp[incr][xstart+incr] = false;
                        }
                    }
                    else
                    {
                        dp[incr][xstart+incr] = false;
                    }
                }
            }
            //cout << "\n";
        }

            string longest = "";
            //printOut(dp);


            for (int xstart = 0; xstart < s.size(); xstart++)
            {
                for (int incr = 0; xstart+incr < s.size(); incr++)
                {
                    //cout << s.substr(incr, xstart+1);
                    //cout << " ";
                    if (dp[incr][xstart+incr] == true)
                    {
                        if (s.substr(incr, xstart+1).size() > longest.size())
                        {
                            //cout << "changed!";
                            //cout << " ";
                            longest = s.substr(incr, xstart+1);
                        }
                    }
                }
                //cout << "\n";
            }

            return longest;
    }

    void printOut(vector<vector<bool>> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                cout << v[i][j];
                cout << " ";
            }
            cout << "\n";
        }
    }
};
