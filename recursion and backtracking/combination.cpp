#include <vector>

class Solution
{
public:
  std::vector<std::vector<int>> res;
  void backtrack(std::vector<int> &candidates, int target, int index, std::vector<int> &combination)
  {
    // Base case: found valid combination
    if (target == 0)
    {
      res.push_back(combination);
      return;
    }
    // If no more candidates or target is negative
    if (index >= candidates.size() || target < 0)
      return;

    // Include current number
    combination.push_back(candidates[index]);
    backtrack(candidates, target - candidates[index], index, combination); // stay at same index (reuse allowed)
    combination.pop_back();

    // Exclude current number
    backtrack(candidates, target, index + 1, combination);
  }

  std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
  {
    std::vector<int> combination;
    backtrack(candidates, target, 0, combination);
    return res;
  }
};
