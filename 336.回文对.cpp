/*
 * @lc app=leetcode.cn id=336 lang=cpp
 *
 * [336] 回文对
 *
 * https://leetcode-cn.com/problems/palindrome-pairs/description/
 *
 * algorithms
 * Hard (32.88%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    2.5K
 * Total Submissions: 7.7K
 * Testcase Example:  '["abcd","dcba","lls","s","sssll"]'
 *
 * 给定一组唯一的单词， 找出所有不同 的索引对(i, j)，使得列表中的两个单词， words[i] + words[j] ，可拼接成回文串。
 * 
 * 示例 1:
 * 
 * 输入: ["abcd","dcba","lls","s","sssll"]
 * 输出: [[0,1],[1,0],[3,2],[2,4]] 
 * 解释: 可拼接成的回文串为 ["dcbaabcd","abcddcba","slls","llssssll"]
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["bat","tab","cat"]
 * 输出: [[0,1],[1,0]] 
 * 解释: 可拼接成的回文串为 ["battab","tabbat"]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        unordered_map<string, int> dict;
        vector<vector<int>> ans;
        // build dictionary
        for (int i = 0; i < words.size(); i++)
        {
            string key = words[i];
            reverse(key.begin(), key.end());
            dict[key] = i;
        }
        // edge case: if empty string "" exists, find all palindromes to become pairs ("", self)
        if (dict.find("") != dict.end())
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (i == dict[""])
                    continue;
                if (isPalindrome(words[i]))
                    ans.push_back({dict[""], i}); // 1) if self is palindrome, here ans covers concatenate("", self)
            }
        }

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                string left = words[i].substr(0, j);
                string right = words[i].substr(j, words[i].size() - j);

                if (dict.find(left) != dict.end() && isPalindrome(right) && dict[left] != i)
                {
                    ans.push_back({i, dict[left]}); // 2) when j = 0, left = "", right = self, so here covers concatenate(self, "")
                }

                if (dict.find(right) != dict.end() && isPalindrome(left) && dict[right] != i)
                {
                    ans.push_back({dict[right], i});
                }
            }
        }

        return ans;
    }

    bool isPalindrome(string str)
    {
        int i = 0;
        int j = str.size() - 1;

        while (i < j)
        {
            if (str[i++] != str[j--])
                return false;
        }

        return true;
    }
};
// @lc code=end
