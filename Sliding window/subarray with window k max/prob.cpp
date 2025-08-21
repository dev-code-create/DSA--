#include <bits/stdc++.h>
using namespace std;

int maxSum_slidingWindow(vector<int> &arr, int k)
{
  int n = arr.size();
  if (n < k)
    return -1; // invalid caseee

  int windowSum = 0;
  for (int i = 0; i < k; i++)
  {
    windowSum += arr[i];
  }

  int maxSum = windowSum;

  for (int i = k; i < n; i++)
  {
    windowSum += arr[i] - arr[i - k]; // slide the window
    maxSum = max(maxSum, windowSum);
  }

  return maxSum;
}

int main()
{
  vector<int> arr = {2, 1, 5, 1, 3, 2};
  int k = 3;
  cout << maxSum_slidingWindow(arr, k) << endl; // Output: 9
}
