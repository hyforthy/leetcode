/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.19%)
 * Likes:    1635
 * Dislikes: 1483
 * Total Accepted:    552.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n <= 0)
            return "";
        
        int i = 0;
        for (;; i++) {
            char t;
            int j;
            for (j = 0; j < n; j++) {
                if (i >= strs[j].size())
                    break;
                if (j == 0)
                    t = strs[j][i];
                else if (t != strs[j][i]) {
                    break;
                }
            }

            if (j < n) {
                break;
            }
        }

        return strs[0].substr(0, i);
    }
};

