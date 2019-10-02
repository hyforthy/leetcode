/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>::iterator t = nums.begin();

        while (t != nums.end()) {
            if (*t == val)
            t = nums.erase(t);
            else
            t++;
        }
        return nums.size();
        
    }
};

