/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
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

