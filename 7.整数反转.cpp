/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <climits>
class Solution {
public:
  int reverse(int x) {
    bool minus = (x > 0 ? false : true);
    long y = minus ? 0 - long(x) : x;
    long ans = 0;
    while (y != 0) {
      long r = y - y / 10 * 10;
      ans = ans * 10 + r;
      y /= 10;
    }
    ans = minus == true ? 0 - ans : ans;
    if (ans > INT_MAX || ans < INT_MIN + 1)
      return 0;
    else
      return int(ans);
  }
};
// @lc code=end
