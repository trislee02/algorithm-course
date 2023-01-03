#include <iostream>
#include <vector>
#include <string>
using namespace std;

// O( min(n,m) )
int approach1()
{
  string s, p;
  cin >> s >> p;
  int sIdx = 0, pIdx = 0;
  bool isValid = true;
  while (isValid && (sIdx < s.length() || pIdx < p.length()))
  {
    if (pIdx == p.length() || sIdx == s.length())
    {
      isValid = false;
      break;
    }
    else if (p[pIdx] == '*')
    {
      if (s[sIdx] != p[pIdx - 1])
        ++pIdx;
      else
        ++sIdx;
    }
    else if (p[pIdx] == '.')
    {
      ++sIdx;
      ++pIdx;
    }
    else
    {
      if (p[pIdx] != s[sIdx])
        isValid = false;
      else
      {
        ++sIdx;
        ++pIdx;
      }
    }
  }
  if (isValid)
    cout << "True";
  else
    cout << "False";
}

void solve()
{
  string s, p;
  cin >> s >> p;

  int m = p.size(), n = s.size();

  // f[i][j] = true if s[1 -> j] can be created from p[1 -> i]
  vector<vector<int>> f(m + 1, vector<int>(n + 1, false));
  p = " " + p;
  s = " " + s;

  f[0][0] = true;
  for (int i = 0; i <= m; ++i)
  {
    for (int j = 0; j <= n; ++j)
      if (f[i][j] == true)
      {
        // p[i + 1] = s[j + 1] = a lowercase character
        if (i + 1 <= m && j + 1 <= n && (isalpha(p[i + 1]) || p[i + 1] == '.') && isalpha(s[j + 1]))
        {
          f[i + 1][j + 1] = true;
        }
        // p[i + 2] == '*' (this means p[i + 1] != '*')
        if (i + 2 <= m && p[i + 2] == '*')
        {
          f[i + 2][j] = true;

          // iterate through each position k > j && s[j + 1] = s[j + 2] = ... = s[k] = p[i + 1]
          for (int k = j + 1; k <= n; ++k)
          {
            if (s[k] != p[i + 1])
              break;
            f[i + 2][k] = true;
          }
        }
      }
  }
  cout << (f[m][n] ? "true" : "false");
}
int main()
{
  freopen("input/bai9.in", "r", stdin);
  //    freopen("output/bai9.out", "w",stdout);

  // approach1();

  solve();

  return 0;
}
