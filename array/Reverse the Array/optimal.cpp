#include <bits/stdc++.h>
using namespace std;

void ReverseArray(vector<int> &arr)
{
  int L = 0, R = arr.size() - 1;
  while (L < R)
  {
    swap(arr[L], arr[R]);
    L++;
    R--;
  }
}

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  ReverseArray(arr);

  for (int i : arr)
  {
    cout << i << endl;
  }

  return 0;
}
