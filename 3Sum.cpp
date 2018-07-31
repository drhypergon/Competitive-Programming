class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> v;
        if (nums.size() < 3)
        {
            return v;
        }
        std::sort(nums.begin(), nums.end());

        int target, front, back;

        int i = 0;
        int dup;


        while (i < nums.size()-2)
        {
            target = -nums[i];
            front = i+1;
            back = nums.size()-1;

            while (front < back)
            {
                if (nums[front] + nums[back] < target)
                {
                    front++;
                }
                else if (nums[front] + nums[back] > target)
                {
                    back--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[front], nums[back]};
                    v.push_back(temp);
                    dup = nums[front];
                    front++;
                    while (nums[front] == dup)
                    {
                        front++;
                    }
                    dup = nums[back];
                    back--;
                    while (nums[back] == dup)
                    {
                        back--;
                    }

                }
            }

            dup = nums[i];
            i++;
            while (nums[i] == dup)
            {
                i++;
            }
        }
        return v;


    }
};
