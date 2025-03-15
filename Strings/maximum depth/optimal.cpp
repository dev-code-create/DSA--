#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxDepth(string s)
{
  int currentDepth = 0;
  int maxDepth = 0;
  for (char c : s)
  {
    if (c == '(')
    {
      currentDepth++;
      maxDepth = max(maxDepth, currentDepth);
    }
    else if (c == ')')
    {
      currentDepth--;
    }
  }
  return maxDepth;
}
int main()
{
  string s = "((()))";
  cout << maxDepth(s) << endl;
  return 0;
}