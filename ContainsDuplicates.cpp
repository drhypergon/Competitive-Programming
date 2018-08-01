class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_map<int, int> map;
        
        for (int i = 0; i < nums.size(); i++)
        {
            map[nums[i]]++;
        }
        
        for (auto it = map.begin(); it != map.end(); it++)
        {
            if (map[it->first] != 1)
            {
                return true;
            }
        }
        return false;
    }
};
