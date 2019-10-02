/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size() - 1;
        while (begin <= end) {
            int middle = (end + begin) / 2;
            if (target > nums[middle]) {
                begin = middle + 1;
            } else {
                end = middle - 1;
            }
        }
        return begin;
    }
};

