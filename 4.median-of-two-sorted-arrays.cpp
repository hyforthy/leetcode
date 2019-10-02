/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (25.53%)
 * Total Accepted:    387.2K
 * Total Submissions: 1.5M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size() + nums2.size();
        vector<int> target_index;
        if (len1 % 2 != 0) {
            target_index.push_back(int(len1/2));
        } else {
            target_index.push_back(int(len1/2) - 1);
            target_index.push_back(int(len1/2));
        }

        int pos_travel = 0;
        int num_founded = 0;
        int result = 0;

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();

        while (it1 != nums1.end() || it2 != nums2.end()) {
            int now = 0;
            if (it1 == nums1.end()) {
                now = *it2;
                it2++;
            } else if (it2 == nums2.end()) {
                now = *it1;
                it1++;
            } else if (*it1 > *it2) {
                now = *it2;
                it2++;
            } else {
                now = *it1;
                it1++;
            }

            if (target_index[num_founded] == pos_travel) {
                num_founded++;
                result += now;
            }
            pos_travel++;

            if (num_founded >= target_index.size()) {
                // return result / (num_founded + 0.0);
                break;
            }
        }

        return result / (num_founded + 0.0);
    }
};

