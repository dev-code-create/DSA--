#include <bits/stdtr1c++.h>
using namespace std;

vector<int> countDistinctBrute(vector<int> &arr, int k)
{
  vector<int> result;
  int n = arr.size();

  for (int i = 0; i <= n - k; i++)
  {
    set<int> window;
    for (int j = i; j < i + k; j++)
    {
      window.insert(arr[j]);
    }
    result.push_back(window.size());
  }
  return result;
}

int main()
{
  vector<int> arr = {1, 2, 1, 3, 4, 2, 3};
  int k = 4;
  vector<int> result = countDistinctBrute(arr, k);

  cout << "Distinct elements in every window of size " << k << ": ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}