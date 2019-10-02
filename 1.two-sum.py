#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#
# https://leetcode.com/problems/two-sum/description/
#
# algorithms
# Easy (41.89%)
# Total Accepted:    1.5M
# Total Submissions: 3.6M
# Testcase Example:  '[2,7,11,15]\n9'
#
# Given an array of integers, return indices of the two numbers such that they
# add up to a specific target.
#
# You may assume that each input would have exactly one solution, and you may
# not use the same element twice.
#
# Example:
#
#
# Given nums = [2, 7, 11, 15], target = 9,
#
# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].
#
#
#
#
#


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        r = []
        nums_dict = {}
        for id, value in enumerate(nums):
            if value in nums_dict:
                nums_dict[value].append(id)
            else:
                nums_dict[value] = [id]
        for value in nums_dict:
            diff = target - value

            if diff != value and diff in nums_dict:
                r.append(nums_dict[value][0])
                r.append(nums_dict[diff][0])
                return r

            if diff == value and len(nums_dict[value]) > 1:
                r.append(nums_dict[value][0])
                r.append(nums_dict[value][1])
                return r
        return []
