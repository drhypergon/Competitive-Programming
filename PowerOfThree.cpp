class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        return isPower(n);
    }
    
    bool isPower(double n)
    {
        if (n == 1)
        {
            return true;
        }
        if (n < 1)
        {
            return false;
        }
        return isPower(n/3);
    }
};
