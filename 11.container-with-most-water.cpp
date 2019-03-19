/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (42.98%)
 * Total Accepted:    330.3K
 * Total Submissions: 767.7K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * Given n non-negative integers a1, a2, ..., an , where each represents a
 * point at coordinate (i, ai). n vertical lines are drawn such that the two
 * endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together
 * with x-axis forms a container, such that the container contains the most
 * water.
 * 
 * Note: You may not slant the container and n is at least 2.
 * 
 * 
 * 
 * 
 * 
 * The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In
 * this case, the max area of water (blue section) the container can contain is
 * 49. 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * 
 */
class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        if (height.size() <= 1)
        {
            return 0;
        }

        int begin = 0, end = height.size() - 1;
        int max = 0;

        while (begin < end)
        {
            int now = 0;
            if (height[begin] > height[end])
            {
                now = (end - begin) * height[end];
                end -= 1;
            }
            else
            {
                now = (end - begin) * height[begin];
                begin += 1;
            }

            if (now > max)
            {
                max = now;
            }
        }
        return max;
    }
};
