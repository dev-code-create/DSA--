#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<string> res;

  void backtrack(string current, int open, int close, int n)
  {
    // Base case: if length == 2*n, it's valid
    if (current.size() == 2 * n)
    {
      res.push_back(current);
      return;
    }

    // Option 1: add "(" if available
    if (open < n)
    {
      backtrack(current + "(", open + 1, close, n);
    }

    // Option 2: add ")" if it won’t break validity
    if (close < open)
    {
      backtrack(current + ")", open, close + 1, n);
    }
  }

  vector<string> generateParenthesis(int n)
  {
    backtrack("", 0, 0, n);
    return res;
  }
};
