/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 0)
            return 0;
        
        vector<int>::iterator t = nums.begin();
        int pre = *t;
        int r = 1;

        for (t = t + 1; t != nums.end();) {
            if (*t == pre) {
                t = nums.erase(t);
            } else {
                pre = *t;
                t++;
                r++;
            }
        }
        return r;
    }
};

