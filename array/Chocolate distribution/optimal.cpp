#include <bits/stdc++.h>
using namespace std;

int optimalChocolateDistribution(vector<int> &arr, int m)
{
  int n = arr.size();

  if (m > n)
    return -1;

  sort(arr.begin(), arr.end());
  int minDiff = INT_MAX;
  for (int i = 0; i + m - 1 < n; i++)
  {
    int diff = arr[i + m - 1] - arr[i];
    minDiff = min(minDiff, diff);
  }

  return minDiff;
}

int main()
{
  vector<int> arr = {8, 5, 4, 3, 11, 4, 6};
  int m = 3;
  cout << optimalChocolateDistribution(arr, m);
}