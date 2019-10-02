/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (32.98%)
 * Likes:    1055
 * Dislikes: 1507
 * Total Accepted:    499.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int nl = needle.size();
        if (nl <= 0)
            return 0;
        
        int hl = haystack.size();
        if (hl <= 0)
            return -1;

        if (hl < nl)
            return -1;
        

        for (int i = 0; i <= hl - nl; i++) {
            int t = i;
            int j = 0;
            for (; j < nl; j++, t++) {
                if (needle[j] != haystack[t])
                    break;
            }
            if (j >= nl)
                return i;
        }
        return -1;
    }
};

