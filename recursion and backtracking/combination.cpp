class Solution
{
public:
  vector<vector<int>> res;
  vector<int> combination;

  void backtrack(vector<int> &candidates, int target, int index)
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
    backtrack(candidates, target - candidates[index], index); // stay at same index (reuse allowed)
    combination.pop_back();

    // Exclude current number
    backtrack(candidates, target, index + 1);
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target)
  {
    backtrack(candidates, target, 0);
    return res;
  }
};
