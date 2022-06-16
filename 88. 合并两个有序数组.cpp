class Solution {
public:
    /**
     *
     * allocate a new array, merge two arrays into this new array, then copy to nums1
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> merged = vector<int>(0, 0);
        int i = 0, j = 0;
        while (i != m || j != n) {
            if (i != m && j != n) {
                if (nums1[i] > nums2[j]) 
                    merged.push_back(nums2[j++]);
                else 
                    merged.push_back(nums1[i++]);
            }
            else if (i == m) {
                merged.push_back(nums2[j++]);
            }
            else {
                merged.push_back(nums1[i++]);
            }
        }
        for (int i = 0; i < m + n; i++)
            nums1[i] = merged[i];
    }
};