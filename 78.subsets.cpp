/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (51.33%)
 * Total Accepted:    337.7K
 * Total Submissions: 657.6K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution
{
  public:
    // vector<vector<int> > subsets(vector<int>& nums) {
    //     vector<vector<int> > r(1);
    //     for (int i = 0; i < nums.size(); i++) {
    //       int l = r.size();
    //     	for(int j = 0; j < l; j++) {
    //     		r.push_back(r[j]);
    //     		r.back().push_back(nums[i]);
    //     	}
    //     }
    //     return r;

    // }

    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > r;
        do_subsets(nums, 0, nums.size() - 1, r);
        return r;
    }

    void do_subsets(vector<int> &nums, int begin, int end, vector<vector<int> > &r)
    {
        if (begin > end)
        {
            vector<int> t;
            r.push_back(t);
            return;
        }

        do_subsets(nums, begin + 1, end, r);

        int l = r.size();
        for (int i = 0; i < l; i++)
        {
            r.push_back(r[i]);
            r.back().push_back(nums[begin]);
        }
    }
};

