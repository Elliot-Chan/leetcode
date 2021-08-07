/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <bits/stdc++.h>
using namespace std;
#define INPUT "input.txt"
// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {
    int sz = height.size();
    int maxHeight = 0, minHeight = 0;
    for (int i = 0; i < sz; i++) {
      maxHeight = height[i] > maxHeight ? height[i] : maxHeight;
      minHeight = height[i] < minHeight ? height[i] : minHeight;
    }
    int ans = 0, curSize = 0;
    for (int h = maxHeight; h >= minHeight; h--) {
      int leftCol = 0, rightCol = 0;
      for (int cur = 0; cur < sz; cur++) {
        if (height[cur] >= h) {
          leftCol = cur;
          break;
        }
      }
      for (int cur = sz - 1; cur >= 0; cur--) {
        if (height[cur] >= h) {
          rightCol = cur;
          break;
        }
      }
      if (leftCol != rightCol) {
        curSize = (rightCol - leftCol) * h;
      }
      ans = ans > curSize ? ans : curSize;
    }
    return ans;
  }
};
