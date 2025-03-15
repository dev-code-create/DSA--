#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
  unordered_map<char, int> romanValues = {
      {'I', 1},
      {'V', 5},
      {'X', 10},
      {'L', 50},
      {'C', 100},
      {'D', 500},
      {'M', 1000}};
  int result = 0;
  for (int i = 0; i < s.size() - 1; i++)
  {
    if (romanValues[s[i]] < romanValues[s[i + 1]])
    {
      result -= romanValues[s[i]];
    }
    else
    {
      result += romanValues[s[i]];
    }
  }
  result += romanValues[s.back()];
  return result;
}
int main()
{
  string s = "X";
  cout << romanToInt(s) << endl;
  return 0;
}