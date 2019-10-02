/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 *
 * algorithms
 * Easy (53.39%)
 * Likes:    1469
 * Dislikes: 2909
 * Total Accepted:    497.5K
 * Total Submissions: 931.8K
 * Testcase Example:  '"III"'
 *
 * Roman numerals are represented by seven different symbols: I, V, X, L, C, D
 * and M.
 * 
 * 
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * For example, two is written as II in Roman numeral, just two one's added
 * together. Twelve is written as, XII, which is simply X + II. The number
 * twenty seven is written as XXVII, which is XX + V + II.
 * 
 * Roman numerals are usually written largest to smallest from left to right.
 * However, the numeral for four is not IIII. Instead, the number four is
 * written as IV. Because the one is before the five we subtract it making
 * four. The same principle applies to the number nine, which is written as IX.
 * There are six instances where subtraction is used:
 * 
 * 
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 * 
 * 
 * Given a roman numeral, convert it to an integer. Input is guaranteed to be
 * within the range from 1 to 3999.
 * 
 * Example 1:
 * 
 * 
 * Input: "III"
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: "IV"
 * Output: 4
 * 
 * Example 3:
 * 
 * 
 * Input: "IX"
 * Output: 9
 * 
 * Example 4:
 * 
 * 
 * Input: "LVIII"
 * Output: 58
 * Explanation: L = 50, V= 5, III = 3.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "MCMXCIV"
 * Output: 1994
 * Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 * 
 */
class Solution {
public:
    Solution() {
        this->m["I"] = 1;
        this->m["V"] = 5;
        this->m["X"] = 10;
        this->m["L"] = 50;
        this->m["C"] = 100;
        this->m["D"] = 500;
        this->m["M"] = 1000;
        this->m["IV"] = 4;
        this->m["IX"] = 9;
        this->m["XL"] = 40;
        this->m["XC"] = 90;
        this->m["CD"] = 400;
        this->m["CM"] = 900;
    }
    int romanToInt(string s) {
        int n = s.size();
        
        int r = 0;
        int i = 0;
        while (i < n) {
            if (n - i >= 2) {
                string two = s.substr(i, 2);
                if (this->m.find(two) != this->m.end()) {
                    r += this->m[two];
                    i += 2;
                    continue;
                }
            }
            r += this->m[s.substr(i, 1)];
            i++;
        }
        return r;
    }
private:
    map<string, int> m;
};

