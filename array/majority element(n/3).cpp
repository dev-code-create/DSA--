#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
  int n = nums.size();
  int count1 = 0, count2 = 0;
  int cand1 = INT_MIN, cand2 = INT_MIN;

  // Step 1: Find potential candidates
  for (int num : nums)
  {
    if (num == cand1)
      count1++;
    else if (num == cand2)
      count2++;
    else if (count1 == 0)
    {
      cand1 = num;
      count1 = 1;
    }
    else if (count2 == 0)
    {
      cand2 = num;
      count2 = 1;
    }
    else
    {
      count1--;
      count2--;
    }
  }

  // Step 2: Verify candidates
  count1 = count2 = 0;
  for (int num : nums)
  {
    if (num == cand1)
      count1++;
    else if (num == cand2)
      count2++;
  }

  vector<int> ans;
  if (count1 > n / 3)
    ans.push_back(cand1);
  if (count2 > n / 3)
    ans.push_back(cand2);

  return ans;
}

int main()
{
  vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
  vector<int> res = majorityElement(nums);
  for (int x : res)
    cout << x << " ";
}
