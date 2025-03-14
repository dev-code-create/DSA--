#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string frequencySort(string s)
{
  unordered_map<char, int> freq;
  for (char ch : s)
  {
    freq[ch]++;
  }
  int n = s.size();

  vector<string> bucket(n + 1, "");

  for (auto &p : freq)
  {
    bucket[p.second] += string(p.second, p.first);
  }

  string result;
  for (int i = n; i > 0; i--)
  {
    if (!bucket[i].empty())
    {
      result += bucket[i];
    }
  }

  return result;
}
int main()
{
  string s = "tree";
  cout << "Sorted by frequency: " << frequencySort(s) << endl;
  return 0;
}