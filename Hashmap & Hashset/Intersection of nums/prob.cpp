#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> intersectionBetter(vector<int> &nums1, vector<int> &nums2)
{
  unordered_set<int> s1(nums1.begin(), nums1.end());
  unordered_set<int> res;

  for (int num : nums2)
  {
    if (s1.count(num))
      res.insert(num);
  }

  return vector<int>(res.begin(), res.end());
}

int main()
{
  vector<int> nums1 = {1, 2, 2, 1};
  vector<int> nums2 = {2, 2};
  vector<int> res = intersectionBetter(nums1, nums2);
  for (int x : res)
    cout << x << " ";
}
