#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {4, 5, 6, 7, 9};
  int minimum = INT_MAX;
  int maximum = INT_MIN;

  for (int i = 0; i < arr.size(); i++)
  {
    minimum = min(minimum, arr[i]);
    maximum = max(maximum, arr[i]);
  }

  cout << "minimum: " << minimum << endl;
  cout << "maximum: " << maximum << endl;

  return 0;
}