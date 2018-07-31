class Solution {
	public int searchInsert(int[] nums, int target)
	{
		int would = nums.length;
        boolean found = false;
		for (int i = 0; i < nums.length; i++)
		{
			if (nums[i] == target)
			{
				return i;
			}
			if (nums[i] > target && found == false)
			{
				would = i;		
                found = true;
		    }
        }
		return would;
    }
}
