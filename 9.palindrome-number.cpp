/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
bool isPalindrome(int x) {
        if (x < 0)
            return false;
        

        vector<int> elements;

        while (x) {
            int mod = x % 10;
            elements.push_back(mod);
            x = x / 10;
        }

        int i = 0, j = elements.size() - 1;
        while (i < j) {
            if (elements[i] != elements[j])
                break;
            i++;
            j--;
        }

        if (i < j)
            return false;
        return true;
    }
};

