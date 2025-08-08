#include <bits/stdc++.h>
using namespace std;

int findDuplicateBetter(vector<int> &nums)
{
  unordered_set<int> seen;
  for (int num : nums)
  {
    if (seen.count(num))
      return num;
    seen.insert(num);
  }
  return -1;
}

int main()
{
  vector<int> nums = {1, 3, 4, 2, 2};
  cout << findDuplicateBetter(nums);
}
