/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
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

