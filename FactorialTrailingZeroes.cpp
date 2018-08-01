class Solution {
public:
    int trailingZeroes(int n) 
    {
        long long factor = 5;
        int zeroes = 0;
        
        while (n/factor > 0)
        {
            zeroes+= n/factor;
            factor = factor*5;
        }
        return zeroes;
    }
};
