/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution
{
public:
string countAndSay(int n) {
        if (n <= 0)
            return "";
        if (n == 1)
            return "1";
        string str = countAndSay(n - 1);
        
        int str_n = str.size();
        int count = 1; 
        string r = "";
        int i = 0;
        for(; i < str_n - 1; i++)
        {
            if(str[i] == str[i+1])
            {
                count++;
            }
            else
            {
                r = r + to_string(count) + str[i];
                count = 1;
            }
        }
        r = r + to_string(count) + str[i];
        return r;
    }
};
