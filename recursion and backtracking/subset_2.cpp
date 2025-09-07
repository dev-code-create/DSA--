#include <vector>
#include <algorithm>

class Solution
{
public:
  std::vector<std::vector<int>> res;
  std::vector<int> subset;

  void backtrack(std::vector<int> &nums, int index)
  {
    res.push_back(subset);

    for (int i = index; i < nums.size(); i++)
    {
      // Skip duplicates at the same recursion level
      if (i > index && nums[i] == nums[i - 1])
        continue;

      subset.push_back(nums[i]);
      backtrack(nums, i + 1);
      subset.pop_back();
    }
  }

  std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
  {
    std::sort(nums.begin(), nums.end()); // sort first to handle duplicates
    backtrack(nums, 0);
    return res;
  }
};
