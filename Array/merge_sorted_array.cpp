// Problem Statement
// https://leetcode.com/problems/merge-sorted-array/

// Solution for O(m+n) Time Complexity

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        stack<int> st;
        int i = 0, j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                st.push(nums1[i]);
                i++;
            }
            else
            {
                st.push(nums2[j]);
                j++;
            }
        }
        while (i < m)
        {
            st.push(nums1[i]);
            i++;
        }

        while (j < n)
        {
            st.push(nums2[j]);
            j++;
        }
        for (int i = m + n - 1; i >= 0; i--)
        {
            nums1[i] = st.top();
            st.pop();
        }
    }
};