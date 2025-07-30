#include <bits/stdtr1c++.h>
using namespace std;

vector<int> countDistinctOptimal(vector<int> &arr, int k)
{
  unordered_map<int, int> freq;
  vector<int> result;
  int n = arr.size();

  for (int i = 0; i < k; i++)
  {
    freq[arr[i]++];
  }
  result.push_back(freq.size());

  for (int i = k; i < n; i++)
  {
    freq[arr[i - k]]--;
    if (freq[arr[i - k]] == 0)
    {
      freq.erase(arr[i - k]);
    }

    freq[arr[i]]++;
    result.push_back(freq.size());
  }
  return result;
}