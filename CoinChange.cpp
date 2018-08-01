class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> c(amount+1);
        c[0] = 0;
        for (int i = 1; i < c.size(); i++)
        {
            int min = 100;
            for (int j = 0; j < coins.size(); j++)
            {
                int current;
                if (i-coins[j] >= 0 && c[i-coins[j]] != -1)
                {
                    current = c[i-coins[j]]+1;
                    if (current < min)
                    {
                        min = current;
                    }
                }
            }
            if (min != 100)
            {
                c[i] = min; 
            }
            else
            {
                c[i] = -1;
            }
        }
        return c[amount];
    }
};
