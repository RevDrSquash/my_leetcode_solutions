// https://leetcode.com/problems/merge-sorted-array/

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int a = m-1, b = n-1;
        for(int idx = m + n - 1; idx >= 0; idx--)
        {
            if(a >= 0 && (b < 0 || nums1[a] > nums2[b]))
            {
                nums1[idx] = nums1[a];
                a--;
            }
            else
            {
                nums1[idx] = nums2[b];
                b--;
            }
        }
    }
};
