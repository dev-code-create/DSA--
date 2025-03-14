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

  vector<pair<char, int>> freqVec(freq.begin(), freq.end());

  sort(freqVec.begin(), freqVec.end(), [](pair<char, int> &a, pair<char, int> &b)
       { return a.second > b.second; });

  string result;
  for (auto &p : freqVec)
  {
    result.append(p.second, p.first); // Repeat character p.second times
  }

  return result;
}
int main()
{
  // using maps
  string s = "tree";
  cout << frequencySort(s) << endl;
  return 0;
}