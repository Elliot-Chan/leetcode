#include <iostream>
#include <unordered_map>
#include <vector>

namespace dataStruct {
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
} // namespace dataStruct

using namespace std;
namespace Solution {
void foo() { cout << "Success!" << endl; }
// Mark:[1. 两数之和](https://leetcode-cn.com/problems/two-sum/)
vector<int> twoSum(vector<int> &nums, int target) {
  unordered_map<int, int> hashtable;
  int sz = nums.size();
  ;
  for (int i = 0; i < sz; i++) {
    if (hashtable.count(target - nums[i])) {
      return {i, hashtable[target - nums[i]]};
    } else
      hashtable[nums[i]] = i;
  }
  return {};
}
// Mark:[2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

dataStruct::ListNode *addTwoNumbers(dataStruct::ListNode *l1,
                                    dataStruct::ListNode *l2) {
  int carry = 0;
  typedef dataStruct::ListNode ListNode;
  ListNode *ans = new ListNode;
  auto head = ans;
  while (l1 != nullptr && l2 != nullptr) {
    head->val = l1->val + l2->val + carry;
    carry = head->val / 10;
    head->val = head->val - 10 * carry;
    l1 = l1->next;
    l2 = l2->next;
    if (l1 != nullptr && l2 != nullptr) {
      head->next = new ListNode(0);
      head = head->next;
    }
  }
  if (l1 == nullptr && l2 != nullptr) {
    head->next = new ListNode(0);
    head = head->next;
    while (l2 != nullptr) {
      head->val = l2->val + carry;
      l2 = l2->next;
      carry = head->val / 10;
      head->val = head->val - 10 * carry;
      if (l2 != nullptr) {
        head->next = new ListNode(0);
        head = head->next;
        head->next = nullptr;
      }
    }
  }
  if (l1 != nullptr && l2 == nullptr) {
    head->next = new ListNode(0);
    head = head->next;
    while (l1 != nullptr) {
      head->val = l1->val + carry;
      l1 = l1->next;
      carry = head->val / 10;
      head->val = head->val - 10 * carry;
      if (l1 != nullptr) {
        head->next = new ListNode(0);
        head = head->next;
        head->next = nullptr;
      }
    }
  }
  if (carry != 0) {
    head->next = new ListNode(carry);
  }
  return ans;
}
// Mark: [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/)
int lengthOfLongestSubstring(string s) {
  unordered_map<int, int> hashtable;
  int ans = 0;
  int M = 0, checkpoint = 0;
  auto sz = s.length();
  if (sz == 0)
    return 0;
  for (int i = 0; i < sz; i++) {
    char c = s[i];
    if (hashtable[c] != 0) {
      hashtable.clear();
      ans = M > ans ? M : ans;
      checkpoint++;
      i = checkpoint;
      c = s[i];
      hashtable[c] = 1;
      M = 1;
    } else {
      hashtable[c] = 1;
      M += 1;
      ans = M > ans ? M : ans;
    }
  }
  return ans;
}
// Mark: [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {}
} // namespace Solution