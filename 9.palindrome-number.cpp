/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (45.06%)
 * Likes:    1646
 * Dislikes: 1387
 * Total Accepted:    689.4K
 * Total Submissions: 1.5M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 * 
 * Example 1:
 * 
 * 
 * Input: 121
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 * 
 * 
 * Follow up:
 * 
 * Coud you solve it without converting the integer to a string?
 * 
 */
// method one
/////
// class Solution {
// public:
// bool isPalindrome(int x) {
//         if (x < 0)
//             return false;
        

//         vector<int> elements;

//         while (x) {
//             int mod = x % 10;
//             elements.push_back(mod);
//             x = x / 10;
//         }

//         int i = 0, j = elements.size() - 1;
//         while (i < j) {
//             if (elements[i] != elements[j])
//                 break;
//             i++;
//             j--;
//         }

//         if (i < j)
//             return false;
//         return true;
//     }
// };

class Solution {
public:
bool isPalindrome(int x) {
        if (x < 0)
            return false;

        long long r = 0;
        long long reserve = x;

        while (x) {
            r = r * 10 + (x % 10);
            x = x / 10;
        }

        if (r == reserve) {
            return true;
        }
        return false;
    }
};

