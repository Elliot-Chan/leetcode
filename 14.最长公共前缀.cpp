// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem14.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (39.34%)
 * Likes:    1569
 * Dislikes: 0
 * Total Accepted:    500.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 *
 * 如果不存在公共前缀，返回空字符串 ""。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：strs = ["flower","flow","flight"]
 * 输出："fl"
 *
 *
 * 示例 2：
 *
 *
 * 输入：strs = ["dog","racecar","car"]
 * 输出：""
 * 解释：输入不存在公共前缀。
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * 0
 * strs[i] 仅由小写英文字母组成
 *
 *
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    string LCM(string s1, string s2) {
        uint ui_minLen = min(s1.size(), s2.size());
        for (int i = 0; i < ui_minLen; i++) {
            if (s1[i] != s2[i]) {
                return s1.substr(0, i);
            }
        }
        return s1.substr(0, ui_minLen);
    }
    string LCM(vector<string> strs, uint begin, uint end) {
        if (begin == end)
            return strs[begin];
        uint mid = (begin + end) / 2;
        string L = LCM(strs, begin, mid);
        string R = LCM(strs, mid + 1, end);
        return LCM(L, R);
    }
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0)
            return "";
        else {
            return LCM(strs, 0, strs.size() - 1);
        }
    }
};
// @lc code=end
