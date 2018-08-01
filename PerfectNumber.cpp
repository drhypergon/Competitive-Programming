class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
        int mid = (int) sqrt(num);
        int sum = 1;
        
        if (num == 1)
        {
            return false;
        }
        for (int i = 2; i <= mid; i++)
        {
            if (num%i == 0)
            {
                sum+= i;
                sum+= num/i;
            }
        }
        
        if (sum == num)
        {
            return true;
        }
        return false;
    }
};
