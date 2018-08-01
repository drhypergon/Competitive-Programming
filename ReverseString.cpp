class Solution {
public:
    string reverseString(string s) 
    {
        string res = s;
        int len = s.size();
        
        for (int i = 0; i < len; i++)
        {
            res[i] = s[len-i-1];
        }
        return res;
    }
};
