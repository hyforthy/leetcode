/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (39.74%)
 * Total Accepted:    28.8K
 * Total Submissions: 72.6K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given a binary tree, write a function to get the maximum width of the given
 * tree. The width of a tree is the maximum width among all levels. The binary
 * tree has the same structure as a full binary tree, but some nodes are null.
 * 
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and right most non-null nodes in the level, where the null nodes
 * between the end-nodes are also counted into the length calculation.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * ⁠          1
 * ⁠        /   \
 * ⁠       3     2
 * ⁠      / \     \  
 * ⁠     5   3     9 
 * 
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4
 * (5,3,null,9).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        /  
 * ⁠       3    
 * ⁠      / \       
 * ⁠     5   3     
 * 
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2
 * (5,3).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2 
 * ⁠      /        
 * ⁠     5      
 * 
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length
 * 2 (3,2).
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /     \  
 * ⁠     5       9 
 * ⁠    /         \
 * ⁠   6           7
 * Output: 8
 * Explanation:The maximum width existing in the fourth level with the length 8
 * (6,null,null,null,null,null,null,7).
 * 
 * 
 * 
 * 
 * Note: Answer will in the range of 32-bit signed integer.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int result = 0;
        vector<int> mostLeftIdx;
        dfs(root, 1, 0, mostLeftIdx, result);
        return result;
    }
    void dfs(TreeNode *node, int deep, int idx, vector<int> &mostLeftIdx, int &res)
    {
        if (!node)
            return;
        if (deep > mostLeftIdx.size())
            mostLeftIdx.push_back(idx);
        res = max(res, idx - mostLeftIdx[deep-1] + 1);
        dfs(node->left, deep + 1, (idx - mostLeftIdx[deep-1]) * 2, mostLeftIdx, res);
        dfs(node->right, deep + 1, (idx - mostLeftIdx[deep-1]) * 2 + 1, mostLeftIdx, res);
    }

    // int widthOfBinaryTree(TreeNode *root)
    // {
    //     if (!root)
    //         return 0;

    //     int result = 1;
    //     int leftMost = 0, rightMost = 0;

    //     queue<pair<TreeNode *, int>> q;
    //     q.push({root, 0});

    //     while (!q.empty())
    //     {
    //         int size = q.size();

    //         for (int i = 0; i < size; i++)
    //         {
    //             TreeNode *node = q.front().first;
    //             int index = q.front().second;
    //             q.pop();
    //             if (i == 0)
    //                 leftMost = index;
    //             if (i == size - 1)
    //                 rightMost = index;
    //             if (node->left)
    //             {
    //                 q.push({node->left, (index-leftMost) * 2});
    //             }
    //             if (node->right)
    //             {
    //                 q.push({node->right, (index-leftMost) * 2 + 1});
    //             }
    //         }
    //         result = max(result, rightMost - leftMost + 1);
    //     }
    //     return result;
    // }
};
