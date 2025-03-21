#include <bits/stdc++.h>
using namespace std;

// Function to reverse each word in the string
string reverseWords(string s)
{
  int start = 0;
  int n = s.length();

  for (int end = 0; end <= n; end++)
  {
    // If we reach a space or the end of the string
    if (end == n || s[end] == ' ')
    {
      // Reverse the word from start to end-1
      reverse(s.begin() + start, s.begin() + end);
      // Move start to the next word
      start = end + 1;
    }
  }

  return s;
}

int main()
{
  string s;
  cout << "Enter a string: ";
  getline(cin, s);

  string result = reverseWords(s);
  cout << "Reversed words: " << result << endl;

  return 0;
}
