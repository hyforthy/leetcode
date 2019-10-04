/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (41.88%)
 * Likes:    908
 * Dislikes: 7141
 * Total Accepted:    318.8K
 * Total Submissions: 761.2K
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is the sequence of integers with the first five
 * terms as following:
 * 
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * 
 * Given an integer n where 1 ≤ n ≤ 30, generate the n^th term of the
 * count-and-say sequence.
 * 
 * Note: Each term of the sequence of integers will be represented as a
 * string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: "1"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 4
 * Output: "1211"
 * 
 */
// class Solution
// {
// public:
// string countAndSay(int n) {
//         if (n <= 0)
//             return "";
//         if (n == 1)
//             return "1";
//         string str = countAndSay(n - 1);
        
//         int str_n = str.size();
//         int count = 1; 
//         string r = "";
//         int i = 0;
//         for(; i + 1 < str_n; i++)
//         {
//             if(str[i] == str[i+1])
//             {
//                 count++;
//             }
//             else
//             {
//                 r = r + to_string(count) + str[i];
//                 count = 1;
//             }
//         }
//         r = r + to_string(count) + str[i];
//         return r;
//     }
// };

class Solution
{
public:
string countAndSay(int n)
{
    string curr_str;

	// The initial case, when n = 1
	curr_str += '1';

	// The iterative case, when n > 1
	for (int i = 0; i < n - 1; i++)
	{
		string buffer;

		// Handle the current string
		int index = 0;
		for (int index = 0; index < curr_str.size(); ++index)
		{
			// Count the occurance of each digit
			int cnt = 1; // At least one occurance
			
			while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) 
			{
				index++;
				cnt++;
			}

			buffer.push_back(cnt + '0');
			buffer.push_back(curr_str[index]);
		}

		// Update the current string
		curr_str = buffer;
	}

	return curr_str;
}
};

