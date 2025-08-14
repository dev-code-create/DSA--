#include <bits/stdc++.h>
using namespace std;

string reverseWords_optimal(string s)
{
  // 1. Remove extra spaces
  int n = s.size();
  int i = 0, j = 0;
  while (j < n)
  {
    while (j < n && s[j] == ' ')
      j++; // skip spaces
    while (j < n && s[j] != ' ')
      s[i++] = s[j++]; // keep word chars
    while (j < n && s[j] == ' ')
      j++; // skip spaces
    if (j < n)
      s[i++] = ' '; // add single space
  }
  s.resize(i);

  // 2. Reverse whole string
  reverse(s.begin(), s.end());

  // 3. Reverse each word
  int start = 0;
  for (int end = 0; end <= s.size(); end++)
  {
    if (end == s.size() || s[end] == ' ')
    {
      reverse(s.begin() + start, s.begin() + end);
      start = end + 1;
    }
  }
  return s;
}
