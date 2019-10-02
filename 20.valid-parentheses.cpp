/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * algorithms
 * Easy (37.32%)
 * Likes:    3405
 * Dislikes: 162
 * Total Accepted:    710K
 * Total Submissions: 1.9M
 * Testcase Example:  '"()"'
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and
 * ']', determine if the input string is valid.
 * 
 * An input string is valid if:
 * 
 * 
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * 
 * 
 * Note that an empty string is also considered valid.
 * 
 * Example 1:
 * 
 * 
 * Input: "()"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "()[]{}"
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "(]"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "([)]"
 * Output: false
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "{[]}"
 * Output: true
 * 
 * 
 */
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        for (int i = 0; i < n; i++) {
            if (s[i] == '(' or s[i] == '[' or s[i] == '{')
                st.push(s[i]);
            else {
                if (st.empty())
                    return false;
                
                char top = st.top();
                st.pop();
                if (top != m[s[i]])
                    return false;
            }
        }
        if (!st.empty()) 
            return false;
        return true;
    }
};

