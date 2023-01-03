#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int N = 21;
long long factorial[N];

// O(N^2)
long long getIndex(vector<int> permutation)
{
  int n = permutation.size();
  vector<bool> remainingValues(n + 1, true);

  long long permutationIndex = 0;
  for (int i = 0; i < n; ++i)
  {
    long long countLess = 0;
    for (int j = 1; j < permutation[i]; ++j)
      countLess += remainingValues[j];

    permutationIndex += countLess * factorial[n - 1 - i];
    remainingValues[permutation[i]] = false;
  }
  permutationIndex++;
  return permutationIndex;
}

// O(N^2)
vector<int> getPermutation(long long index, int n)
{
  vector<bool> remainingValues(n + 1, true);
  vector<int> result;

  for (int i = 0; i < n; ++i)
  {
    // find the first remaining value x so that | number of possible remaining permutations with the first value <= x is greater than or equal to y
    long long countPossiblePermutations = 0;
    for (int x = 1; x <= n; ++x)
      if (remainingValues[x])
      {
        long long curCount = countPossiblePermutations + factorial[n - 1 - i];

        if (curCount >= index)
        {
          index -= countPossiblePermutations;
          result.push_back(x);
          remainingValues[x] = false;
          break;
        }

        countPossiblePermutations = curCount;
      }
  }

  return result;
}
void solve()
{
  // input
  string line;
  getline(cin, line);

  stringstream ss(line);

  vector<int> a;
  string token;
  while (ss >> token)
  {
    a.push_back(stoi(token));
  }

  //
  int n = a.size();

  long long y;
  cin >> y;

  // init

  factorial[0] = 1;
  for (int i = 1; i <= n; ++i)
    factorial[i] = factorial[i - 1] * i;

  // calculate result
  cout << getIndex(a) << "\n";
  //
  vector<int> result = getPermutation(y, n);
  for (int x : result)
    cout << x << " ";
}

// Time complexity: O(N^2)
// Space complexity: O(N)

int main()
{
  freopen("input/bai20.in", "r", stdin);

  solve();

  return 0;
}
