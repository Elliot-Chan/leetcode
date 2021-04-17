/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        enum State { Begin, Char, Any, Single, End, None };
        // char
        unordered_map<State, vector<State>> table = {
            {State::Begin,
             {State::None, State::Char, State::Any, State::Single, State::None,
              State::None}},
            {State::Char,
             {State::None, State::Char, State::Any, State::Single, State::None,
              State::None}},
            {State::Any,
             {State::None, State::Begin, State::Any, State::Single, State::None,
              State::None}},
            {State::Single,
             {State::None, State::Char, State::End, State::Single, State::None,
              State::None}},
        };
        auto state = State::Begin, curState = State::Begin;
        int sz = s.length();
        char last_char = 0;
        int i = 0;
        for (auto r : p) {
            if (r == '.')
                curState = State::Single;
            else if (r == '*')
                curState = State::Any;
            else {
                last_char = r;
                curState = State::Char;
            }
            for (; i < sz; i++) {
                state = table[state][curState];
                char c = sz[i];
                switch (state) {
                case State::Char:
                    if (c == last_char)
                        continue;
                    else
                        return false;
                    break;
                case State::Any:
                    break;
                case State::Single:
                    continue;
                    break;

                default:
                    break;
                }
            }
        }
        测试一下
        return false;
    }
};
// @lc code=end
