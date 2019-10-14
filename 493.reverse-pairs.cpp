/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 *
 * https://leetcode.com/problems/reverse-pairs/description/
 *
 * algorithms
 * Hard (22.70%)
 * Total Accepted:    21.9K
 * Total Submissions: 96.6K
 * Testcase Example:  '[1,3,2,3,1]'
 *
 * Given an array nums, we call (i, j) an important reverse pair if i < j and
 * nums[i] > 2*nums[j].
 * 
 * You need to return the number of important reverse pairs in the given
 * array.
 * 
 * Example1:
 * 
 * Input: [1,3,2,3,1]
 * Output: 2
 * 
 * 
 * Example2:
 * 
 * Input: [2,4,3,5,1]
 * Output: 3
 * 
 * 
 * Note:
 * 
 * The length of the given array will not exceed 50,000.
 * All the numbers in the input array are in the range of 32-bit integer.
 * 
 * 
 */
// class Solution {
// public:
//     int reversePairs(vector<int>& nums) {
//         int res = 0, n = nums.size();
//         vector<int> v = nums, bit(n + 1);
//         sort(v.begin(), v.end());
//         unordered_map<int, int> m;
//         for (int i = 0; i < n; ++i) m[v[i]] = i + 1;
//         for (int i = n - 1; i >= 0; --i) {
//             res += getSum(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin(), bit);
//             update(m[nums[i]], bit);
//         }
//         return res;
//     }
//     int getSum(int i, vector<int>& bit) {
//         int sum = 0;
//         while (i > 0) {
//             sum += bit[i];
//             i -= (i & -i); // i & -i 求得是2的k次幂，k是i的二进制表示中末尾的连续0的个数。
//         }
//         return sum;
//     }
//     void update(int i, vector<int>& bit) {
//         while (i < bit.size()) {
//             bit[i] += 1;
//             i += (i & -i);
//         }
//     }
// };

// 归并方式求逆序对
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 0) {
            return 0;
        }
        vector<int> tmp(nums.size());
         return merge_sort(nums, 0, nums.size() - 1, tmp);
    }

    int merge_sort(vector<int>& nums, int begin, int end, vector<int> &tmp) {

        if (end - begin == 0) {
            tmp[begin] = nums[begin];
            return 0;
        }

        int mid = begin + (end - begin)/2;

        int count = merge_sort(nums, begin, mid, tmp) + merge_sort(nums, mid + 1, end,tmp);

        int i = begin;
        int j = mid + 1;
        while (i <= mid && j <= end) {
            if (((long long)(tmp[i])) > 2 * ((long long)(tmp[j]))) {
                j++;
            } else {
                count += j - mid - 1;
                i++;
            }
        }

        while (i <= mid) {
            count += j - mid - 1;
            i++;
        }

        i = begin;
        j = mid + 1;
        vector<int> tmp1;
        while (i <= mid && j <= end) {
            if (tmp[i] > tmp[j]) {
                tmp1.push_back(tmp[j]);
                j++;
            } else {
                tmp1.push_back(tmp[i]);
                i++;
            }
        }

        while (i <= mid) {
            tmp1.push_back(tmp[i]);
            i++;
        }
        while (j <= end) {
            tmp1.push_back(tmp[j]);
            j++;
        }

        i = 0;
        while (i <= end - begin) {
            tmp[i + begin] = tmp1[i];
            i++;
        }

        return count;
    }
};

