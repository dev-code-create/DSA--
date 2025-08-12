#include <bits/stdc++.h>
using namespace std;

void moveZeroesOptimal(vector<int> &nums)
{
  int lastNonZeroIndex = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != 0)
    {
      swap(nums[i], nums[lastNonZeroIndex]);
      lastNonZeroIndex++;
    }
  }
}

int main()
{
  vector<int> nums = {0, 1, 0, 3, 12};
  moveZeroesOptimal(nums);
  for (int x : nums)
    cout << x << " ";
}
