#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int atMostK(const string &s, int k)
{
  int n = s.length();
  int freq[26] = {0};
  int left = 0;
  int count = 0;
  int result = 0;
  for (int right = 0; right < n; right++)
  {
    char c = s[right];
    if (freq[c - 'a'] == 0)
    {
      count++;
    }
    freq[c - 'a']++;

    while (count > k)
    {
      char leftChar = s[left];
      freq[leftChar - 'a']--;
      if (freq[leftChar - 'a'] == 0)
      {
        count--;
      }
      left++;
    }
    result += right - left + 1;
  }
  return result;
}

int substringWithKDistinct(string s, int k)
{
  if (k <= 0)
    return 0;
  return atMostK(s, k) - atMostK(s, k - 1);
}

int main()
{
  string s = "aba";
  int k = 2;
  cout << substringWithKDistinct(s, k) << endl;
  return 0;
}