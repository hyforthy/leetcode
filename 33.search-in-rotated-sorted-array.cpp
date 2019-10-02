/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (32.69%)
 * Total Accepted:    379.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return its
 * index, otherwise return -1.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 0
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,5,6,7,0,1,2], target = 3
 * Output: -1
 * 
 */
class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        vector<int>::iterator it = nums.begin();
        if (nums.empty())
            return -1;
        int prev = *it;

        int middle = 1;
        for (it = it + 1; it != nums.end(); it++)
        {
            if (*it > prev)
            {
                middle += 1;
                prev = *it;
            }
            else
            {
                break;
            }
        }

        int r = b_search(nums, 0, middle - 1, target);
        if (r >= 0)
            return r;
        r = b_search(nums, middle, nums.size() - 1, target);
        return r;
    }

  private:
    int b_search(vector<int> &nums, int begin, int end, int target)
    {
        while (begin <= end)
        {
            int middle = (begin + end) / 2;
            if (target > nums[middle])
            {
                begin = middle + 1;
            }
            else if (target < nums[middle])
            {
                end = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};
