/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /*
    string convert(string s, int numRows) {
      int sz = s.size();
      char V[numRows][sz / numRows + 1];
      for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
          V[i][j] = 0;
        }
      }
      int cnt = 0;
      int i = 0, j = 0;
      while (cnt < sz) {
        cout << "Begin" << endl;
        while (i < numRows) {
          V[i][j] = s[cnt];
          cout << i << "*" << j << "*" << cnt << endl;
          i++;
          if (cnt++ == sz)
            goto END;
        }
        cout << i << " " << j << " " << cnt << endl;
        i--;
        j++;
        while (i >= 0) {
          V[i][j] = s[cnt];
          cout << i << "^" << j << "^" << cnt << endl;
          i--;
          j++;
          if (cnt++ == sz)
            goto END;
        }
        cout << "HERE" << endl;
      }
    END:
      for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
          if (V[j][i] != 0)
            cout << V[j][i];
        }
      }
      return 0;
    }
    */
  string convert(string s, int numRows) {
    vector<string> rows(min(numRows, int(s.size())));
    bool down = false;
    int cur = 0;
    if (numRows == 1)
      return s;
    for (auto c : s) {
      rows[cur] += c;
      if (cur == 0 || cur == numRows - 1) {
        down = !down;
      }
      cur = cur + (down ? 1 : -1);
    }
    string ans;
    for (auto r : rows) {
      ans += r;
    }
    return ans;
  }
};
// @lc code=end
