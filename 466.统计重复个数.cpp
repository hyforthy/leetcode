/*
 * @lc app=leetcode.cn id=466 lang=cpp
 *
 * [466] 统计重复个数
 *
 * https://leetcode-cn.com/problems/count-the-repetitions/description/
 *
 * algorithms
 * Hard (30.04%)
 * Likes:    26
 * Dislikes: 0
 * Total Accepted:    877
 * Total Submissions: 2.9K
 * Testcase Example:  '"acb"\n4\n"ab"\n2'
 *
 * 定义由 n 个连接的字符串 s 组成字符串 S，即 S = [s,n]。例如，["abc", 3]=“abcabcabc”。
 * 
 * 另一方面，如果我们可以从 s2 中删除某些字符使其变为 s1，我们称字符串 s1 可以从字符串 s2 获得。例如，“abc” 可以根据我们的定义从
 * “abdbec” 获得，但不能从 “acbbe” 获得。
 * 
 * 现在给出两个非空字符串 S1 和 S2（每个最多 100 个字符长）和两个整数 0 ≤ N1 ≤ 10^6 和 1 ≤ N2 ≤
 * 10^6。现在考虑字符串 S1 和 S2，其中S1=[s1,n1]和S2=[s2,n2]。找出可以使[S2,M]从 S1 获得的最大整数 M。
 * 
 * 示例：
 * 
 * 输入：
 * s1 ="acb",n1 = 4
 * s2 ="ab",n2 = 2
 * 
 * 返回：
 * 2
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)

    {

        if (n1 == 0)

            return 0;

        int indexr[s2.size() + 1] = {0}; // index at start of each s1 block

        int countr[s2.size() + 1] = {0}; // count of repititions till the present s1 block

        int index = 0, count = 0;

        for (int i = 0; i < n1; i++)
        {

            for (int j = 0; j < s1.size(); j++)
            {

                if (s1[j] == s2[index])

                    ++index;

                if (index == s2.size())
                {

                    index = 0;

                    ++count;
                }
            }

            countr[i] = count;

            indexr[i] = index;

            for (int k = 0; k < i; k++)
            {

                if (indexr[k] == index)
                {

                    int prev_count = countr[k];
                    int pattern_count = (n1 - 1 - k) / (i - k) * (countr[i] - countr[k]);
                    int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];

                    return (prev_count + pattern_count + remain_count) / n2;
                }
            }
        }

        return countr[n1 - 1] / n2;
    }
};
// @lc code=end
