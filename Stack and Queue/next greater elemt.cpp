#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int> &nums)
{
  int n = nums.size();
  vector<int> res(n, -1); // Initialize the result with -1 for each element
  stack<int> st;          // Stack to store indices

  // Loop from 0 to 2*n - 1 to simulate the circular array
  for (int i = 0; i < 2 * n; i++)
  {
    // Current index in circular fashion
    int currIndex = i % n;

    // While stack is not empty and current element is greater than element at stack top index
    while (!st.empty() && nums[currIndex] > nums[st.top()])
    {
      // Current element is the next greater for the element at st.top()
      res[st.top()] = nums[currIndex];
      st.pop();
    }

    // In the first pass, push index into stack
    if (i < n)
    {
      st.push(i);
    }
  }

  return res;
}

int main()
{
  // Example test case: circular array
  vector<int> nums = {1, 2, 1};
  vector<int> result = nextGreaterElements(nums);

  // Output the result
  cout << "Next Greater Elements: ";
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}
