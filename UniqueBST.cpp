class Solution {
public:
    int numTrees(int n) 
    {

            long long combination = 1;
            for (int i = n+1; i <= 2*n; i++)
            {
                combination = combination*i;
                combination/=(i-n);
            }
            combination/=(n+1);
            return combination;
    }
};
