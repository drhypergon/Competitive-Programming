class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int, int> times;
        
        for (int i = 0; i < nums.size(); i++)
        {
            times[nums[i]]++;
        }
        
        for (auto it = times.begin(); it != times.end(); ++it)
        {
            if (times[it->first] == 1 )
            {
                return it->first;
            }
        }
        return -1;
    }
};
