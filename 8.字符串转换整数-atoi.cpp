/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

#include <climits>
#include <string>
using namespace std;
// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
 public:
  int tp(char c) {
    if (c == ' ')
      return 0;
    else if (c <= '9' && c >= '0')
      return 1;
    else if (c == '+' || c == '-')
      return 2;
    else
      return 3;
  }
  int myAtoi(string s) {
    // space digit +or- else
    long ans = 0;
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "num", "sign", "end"}},
        {"end", {"end", "end", "end", "end"}},
        {"num", {"end", "num", "end", "end"}},
        {"sign", {"end", "num", "end", "end"}},
    };
    string state = "start";
    bool minus = false;
    for (auto c : s) {
      state = table[state][tp(c)];
      if (state == "num") {
        ans = ans * 10 + (c - '0');
        if (ans > INT_MAX || ans < INT_MIN) {
          return minus ? INT_MIN : INT_MAX;
        }
      } else if (state == "sign") {
        minus = (c == '-' ? true : false);
      } else if (state == "end") {
        return minus ? 0 - ans : ans;
      }
    }
    if (state == "num") {
      return minus ? 0 - ans : ans;
    } else
      return 0;
  }
};
// @lc code=end
