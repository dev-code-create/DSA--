#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutiveOptimal(vector<int> &nums)
{
  unordered_set<int> numSet(nums.begin(), nums.end());
  int maxLen = 0;

  for (int num : numSet)
  {
    // Start of a sequence
    if (numSet.find(num - 1) == numSet.end())
    {
      int currNum = num;
      int currLen = 1;

      while (numSet.find(currNum + 1) != numSet.end())
      {
        currNum++;
        currLen++;
      }

      maxLen = max(maxLen, currLen);
    }
  }

  return maxLen;
}
