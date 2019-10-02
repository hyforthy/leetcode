/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
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

