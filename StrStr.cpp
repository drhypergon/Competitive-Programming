class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        if (haystack.size() < needle.size())
        {
            return -1;
        }
        if (haystack == needle)
        {
            return 0;
        }
        for (int i = 0; i < haystack.size()-needle.size()+1; i++)
        {
            cout << haystack.substr(i, needle.size());
            cout << "\n";
            if (haystack.substr(i, needle.size()) == needle)
            {
                return i;
            }
        }
        return -1;
    }
};
