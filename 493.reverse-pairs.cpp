/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (22.70%)
 * Total Accepted:    21.9K
 * Total Submissions: 96.6K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 * 
 * You need to return the number of important reverse pairs in the given
 * array.
 * 
 * Example1:
 * 
 * Input: [1,3,2,3,1]
 * Output: 2
 * 
 * 
 * Example2:
 * 
 * Input: [2,4,3,5,1]
 * Output: 3
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * 
 * 
 */
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> v = nums, bit(n + 1);
        sort(v.begin(), v.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
        for (int i = n - 1; i >= 0; --i) {
            res += getSum(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin(), bit);
            update(m[nums[i]], bit);
        }
        return res;
    }
    int getSum(int i, vector<int>& bit) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
    void update(int i, vector<int>& bit) {
        while (i < bit.size()) {
            bit[i] += 1;
            i += (i & -i);
        }
    }
};

