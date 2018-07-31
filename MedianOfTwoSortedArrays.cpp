class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int size = nums1.size() + nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        vector<int> v;

        while (idx1 < nums1.size() && idx2 < nums2.size())
        {
            if (nums1[idx1] < nums2[idx2])
            {
                v.push_back(nums1[idx1]);
                idx1++;
            }
            else
            {
                v.push_back(nums2[idx2]);
                idx2++;
            }
        }

        while (idx1 < nums1.size())
        {
            v.push_back(nums1[idx1]);
            idx1++;
        }

        while (idx2 < nums2.size())
        {
            v.push_back(nums2[idx2]);
            idx2++;
        }

        if (size%2 == 0)
        {
            int meme = size/2;
            cout << v[meme-1];
            cout << v[meme];
            return (double) (v[meme-1] + v[meme])/2;
        }
        else
        {
            return v[size/2];
        }
    }
};
