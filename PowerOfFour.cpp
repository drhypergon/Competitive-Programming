class Solution {
public:
    bool isPowerOfFour(int num) 
    {    
        return isPower(num);
    }
    
    double isPower(double num)
    {
        if (num == 1)
        {
            return true;
        }
        if (num < 1)
        {
            return false;
        }
        return isPower(num/4);
    }
};
