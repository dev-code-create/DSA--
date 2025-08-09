#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  unordered_set<char> window;
  int left = 0, right = 0, maxLen = 0;
  int n = s.length();

  while (right < n)
  {
    if (window.find(s[right]) == window.end())
    {
      window.insert(s[right]);
      maxLen = max(maxLen, right - left + 1);
      right++;
    }
    else
    {
      window.erase(s[left]);
      left++;
    }
  }
  return maxLen;
}

int main()
{
  string s = "abcabcbb";
  cout << lengthOfLongestSubstring(s) << endl; // Output: 3
}
