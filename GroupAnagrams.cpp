class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> map;
        
        for (int i = 0; i < strs.size(); i++)
        {
            string val = strs[i];
            string input = strs[i];
            sort(input.begin(), input.end());
            
            map[input].push_back(val);
        }
        
        vector<vector<string>> result;
        
        for (auto it = map.begin(); it != map.end(); it++)
        {
            result.push_back(map[it->first]);
        }
        return result;
    }
};
