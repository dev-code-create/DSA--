#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicatesBetter(vector<int> &nums)
{
  unordered_map<int, int> freq;
  vector<int> res;

  for (int num : nums)
  {
    freq[num]++;
    if (freq[num] == 2)
      res.push_back(num);
  }

  return res;
}