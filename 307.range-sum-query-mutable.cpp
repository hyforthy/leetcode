/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (27.68%)
 * Total Accepted:    66.9K
 * Total Submissions: 241.3K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * Note:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 
 * 
 */
// class NumArray
// {
//   public:
//     NumArray(vector<int> nums)
//     {
//         if (nums.empty())
//             return;
//         data = nums;
//         int n  = int(sqrt(data.size()));
//         bLen = ceil(double(data.size()) / n);
//         block.resize(bLen);
//         for (int i = 0; i < data.size(); i++)
//         {
//             block[i / bLen] += data[i];
//         }
//     }
/* 分块区域 */
//     void update(int i, int val)
//     {
//         int idx = i / bLen;
//         block[idx] += val - data[i];
//         data[i] = val;
//     }

//     int sumRange(int i, int j)
//     {
//         int sum = 0;
//         int begin = i / bLen, end = j / bLen;
//         if (begin == end)
//         {
//             for (int k = i; k <= j; ++k)
//             {
//                 sum += data[k];
//             }
//             return sum;
//         }
//         for (int k = i; k < (begin + 1) * bLen; ++k)
//         {
//             sum += data[k];
//         }
//         for (int k = begin + 1; k < end; ++k)
//         {
//             sum += block[k];
//         }
//         for (int k = end * bLen; k <= j; ++k)
//         {
//             sum += data[k];
//         }
//         return sum;
//     }

//   private:
//     int bLen;
//     vector<int> data, block;
// };

class NumArray
{
  public:
    NumArray(vector<int> nums)
    {
        
        data.resize(nums.size());
        bit.resize(nums.size() + 1);
        /* 构造树状数组 */
        for (int i = 0; i < nums.size(); i++)
        {
            update(i, nums[i]);
        }
        //data = nums;
    }

    void update(int i, int val)
    {
        int diff = val - data[i];
        for (int j = i + 1; j < bit.size(); j += (j & -j))
        {
            bit[j] += diff;
        }
        data[i] = val;
    }

    int sumRange(int i, int j)
    {
        return getSum(j + 1) - getSum(i);
    }

    int getSum(int i)
    {
        int res = 0;
        for (int j = i; j > 0; j -= (j & -j))
        {
            res += bit[j];
        }
        return res;
    }

  private:
    vector<int> data, bit;
};


// class NumArray {
// public:
//     NumArray(vector<int> nums) {
//         n = nums.size();
//         tree.resize(n * 2);
//         buildTree(nums);
//     }
        /* 线段树 */
//     void buildTree(vector<int>& nums) {
//         for (int i = n; i < n * 2; ++i) {
//             tree[i] = nums[i - n];
//         }
//         for (int i = n - 1; i > 0; --i) {
//             tree[i] = tree[i * 2] + tree[i * 2 + 1];
//         }
//     }

//     void update(int i, int val) {
//         tree[i += n] = val;
//         while (i > 0) {
//             tree[i / 2] = tree[i] + tree[i ^ 1];
//             i /= 2;
//         }
//     }

//     int sumRange(int i, int j) {
//         int sum = 0;
//         for (i += n, j += n; i <= j; i /= 2, j /= 2) {
//             if ((i & 1) == 1) sum += tree[i++];
//             if ((j & 1) == 0) sum += tree[j--];
//         }
//         return sum;
//     }    

// private:
//     int n;
//     vector<int> tree;
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
