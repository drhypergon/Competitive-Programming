class Solution {
public:
    vector<vector<int>> arr;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        p(nums, 0, nums.size()-1);
        return arr;
    }
    
    void swap(vector<int> nums, int i, int j)
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    void p(vector<int>&nums, int l, int r)
    {
        if (l >= r)
        {
            arr.push_back(nums);
            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i];
                cout << " ";
            }
            cout << "\n";
            return;
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                int temp = nums[l];
                nums[l] = nums[i];
                nums[i] = temp;
                p(nums, l+1, r);
                temp = nums[l];
                nums[l] = nums[i];
                nums[i] = temp;
            }
        }
    }
};
