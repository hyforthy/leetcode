/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
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

