class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        unordered_map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        int max = INT_MIN;
        int val = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            if (it->second > max)
            {
                max = it->second;
                val = it->first;
            }
        }
        return val;
    }
};
