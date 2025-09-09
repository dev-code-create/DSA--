#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<vector<int>> res;
  vector<int> perm;
  vector<bool> used;

  void backtrack(vector<int> &nums)
  {
    // Base case: when permutation is complete
    if (perm.size() == nums.size())
    {
      res.push_back(perm);
      return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (used[i])
        continue; // skip already used element

      // Choose
      perm.push_back(nums[i]);
      used[i] = true;

      // Explore
      backtrack(nums);

      // Undo choice
      perm.pop_back();
      used[i] = false;
    }
  }

  vector<vector<int>> permute(vector<int> &nums)
  {
    used.assign(nums.size(), false);
    backtrack(nums);
    return res;
  }
};
