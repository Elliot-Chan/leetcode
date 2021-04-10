/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    // 使得序列中字符的个数始终为奇数
    vector<char> ns;
    char del = '#';
    int n = s.length();
    for (int i = 0; i < n; i++) {
      ns.push_back(del);
      ns.push_back(s[i]);
    }
    ns.push_back(del);
    n = ns.size();
    int max = 0, begin = 0, end = 0;
    for (int i = 0; i < n; i++) {
      int left = i, right = i;
      while (ns[left] == ns[right]) {
        left -= 1;
        right += 1;
        if (left < 0 || right >= n) {
          break;
        }
      }
      left += 1;
      right -= 1;
      // cout << i << " " << left  << " " << right << " " << max << endl;
      if (right - left + 1 > max) {
        begin = left;
        end = right;
        max = right - left + 1;
      }
    }
    // cout << begin << " " << end << endl;
    return s.substr(begin / 2, max / 2);
  }
};
// @lc code=end
