/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include <climits>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int sz1 = nums1.size();
        int sz2 = nums2.size();
        if (sz1 > sz2)
            return findMedianSortedArrays(nums2, nums1);
        int left = 0, right = sz1;
        int lmax = 0, rmin = 0;
        while (left <= right) {
            int i = (left + right) / 2;
            int j = (sz1 + sz2 + 1) / 2 - i;
            int n1m1 = i == 0 ? INT_MIN : nums1[i - 1];
            int n1 = i == sz1 ? INT_MAX : nums1[i];
            int n2m1 = j == 0 ? INT_MIN : nums2[j - 1];
            int n2 = j == sz2 ? INT_MAX : nums2[j];
            if (n1m1 <= n2) {
                lmax = max(n1m1, n2m1);
                rmin = min(n1, n2);
                left = i + 1;
            } else {
                right = i - 1;
            }
        }
        return (sz1 + sz2) % 2 == 0 ? (lmax + rmin) / 2.0 : lmax;
    }
};
// @lc code=end