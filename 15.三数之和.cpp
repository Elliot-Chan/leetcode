/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <bits/stdc++.h>
using namespace std;
#define INPUT "input.txt"
// @lc code=start
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < sz; i++) {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;
      for (int left = i + 1, right = sz - 1; left < right;) {
        if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          left++;
        } else {
          ans.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1])
            left++;
          while (left < right && nums[right] == nums[right - 1])
            right--;
          left++;
          right--;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
