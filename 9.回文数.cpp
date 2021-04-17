/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */
#include <stack>
using namespace std;
// @lc code=start
class Solution {
 public:
  int right(int x) { return x - (x / 10) * 10; }
  int length(int x) {
    int l = 0;
    while (x != 0) {
      x /= 10;
      l++;
    }
    return l;
  }
  int left(int x, int len) {
    while (--len > 0) {
      x /= 10;
    }
    return x;
  }
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int l = length(x);
    int rg = right(x), lf = left(x, l);
    while (rg == lf && l > 0) {
      int strip_l = 1;
      for (int i = 0; i < l - 1; i++) {
        strip_l *= 10;
      }
      x -= strip_l * lf;
      x /= 10;
      l -= 2;
      rg = right(x), lf = left(x, l);
    }
    if (l <= 1) return true;
    return false;
  }
};
// @lc code=end
