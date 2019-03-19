#
# @lc app=leetcode id=78 lang=python3
#
# [78] Subsets
#
# https://leetcode.com/problems/subsets/description/
#
# algorithms
# Medium (51.33%)
# Total Accepted:    337.7K
# Total Submissions: 657.6K
# Testcase Example:  '[1,2,3]'
#
# Given a set of distinct integers, nums, return all possible subsets (the
# power set).
# 
# Note: The solution set must not contain duplicate subsets.
# 
# Example:
# 
# 
# Input: nums = [1,2,3]
# Output:
# [
# ⁠ [3],
# [1],
# [2],
# [1,2,3],
# [1,3],
# [2,3],
# [1,2],
# []
# ]
# 
#
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        r = [[]]
        for n in nums:
            for one in range(len(r)):
                r.append(copy.copy(r[one]))
                r[-1].append(n)
                l += 1

        return r
        
        

