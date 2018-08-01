class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        unordered_map<char, vector<char>> mapping1;
        unordered_map<char, vector<char>> mapping2;
        
        for (int i = 0; i < t.size(); i++)
        {
            if (mapping1.find(t[i]) == mapping1.end())
            {
                mapping1[t[i]].push_back(s[i]);
            }
            if (mapping1.find(t[i]) != mapping1.end() && mapping1[t[i]][0] != s[i])
            {
                mapping1[t[i]].push_back(s[i]);
            }
            
            if (mapping2.find(s[i]) == mapping2.end())
            {
                mapping2[s[i]].push_back(t[i]);
            }
            if (mapping2.find(s[i]) != mapping2.end() && mapping2[s[i]][0] != t[i])
            {
                mapping2[s[i]].push_back(t[i]);
            }
        }
        
        for (auto it = mapping1.begin(); it != mapping1.end(); it++)
        {
            if (mapping1[it->first].size() > 1)
            {
                return false;
            }
        }
        
        for (auto it = mapping2.begin(); it != mapping2.end(); it++)
        {
            if (mapping2[it->first].size() > 1)
            {
                return false;
            }
        }
        return true;
    }
};
