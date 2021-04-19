// @before-stub-for-debug-begin
#include "commoncppproblem13.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution {
  public:
    int romanToInt(string s) {
        int sz = s.length();
        unordered_map<char, int> table = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        int ans = 0;
        int i;
        for (i = 0; i < sz - 1; i++) {
            char s_chNext = s[i + 1];
            switch (s[i]) {
            case 'I':
                if (s_chNext == 'V') {
                    ans += 4;
                    i++;
                } else if (s_chNext == 'X') {
                    ans += 9;
                    i++;
                } else {
                    ans += 1;
                }
                break;
            case 'X':
                if (s_chNext == 'L') {
                    ans += 40;
                    i++;
                } else if (s_chNext == 'C') {
                    ans += 90;
                    i++;
                } else {
                    ans += 10;
                }
                break;
            case 'C':
                if (s_chNext == 'D') {
                    ans += 400;
                    i++;
                } else if (s_chNext == 'M') {
                    ans += 900;
                    i++;
                } else {
                    ans += 100;
                }
                break;
            default:
                ans += table[s[i]];
                break;
            }
        }
        if (i != sz)
            ans += table[s[i]];
        cout << ans << endl;
        return ans;
    }
};
// @lc code=end
