#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
  if (s.length() != t.length())
    return false;

  unordered_map<char, char> mapST, mapTS;

  for (int i = 0; i < s.length(); i++)
  {
    char cs = s[i];
    char ct = t[i];

    // Check if mapping exists and is valid
    if (mapST.count(cs))
    {
      if (mapST[cs] != ct)
        return false;
    }
    else
    {
      mapST[cs] = ct;
    }

    if (mapTS.count(ct))
    {
      if (mapTS[ct] != cs)
        return false;
    }
    else
    {
      mapTS[ct] = cs;
    }
  }

  return true;
}
