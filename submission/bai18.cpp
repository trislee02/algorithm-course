#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int N = 9;
int factorial[N];

int getIndex(vector<int> permutation)
{
  int n = permutation.size();
  vector<bool> remainingValues(n, true);

  int permutationIndex = 0;
  for (int i = 0; i < n; ++i)
  {
    int countLess = 0;
    for (int j = 1; j < permutation[i]; ++j)
      countLess += remainingValues[j];

    permutationIndex += countLess * factorial[n - 1 - i];
    remainingValues[permutation[i]] = false;
  }
  permutationIndex++;
  return permutationIndex;
}

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n);

  for (int &x : a)
    cin >> x;
  // init
  factorial[0] = 1;
  for (int i = 1; i <= n; ++i)
    factorial[i] = factorial[i - 1] * i;

  // bfs
  int target = 1;
  int source = getIndex(a);

  if (source == target)
  {
    cout << 0;
    return;
  }

  vector<vector<int>> permutations(factorial[n] + 1, vector<int>());
  vector<int> dist(factorial[n] + 1, -1);

  queue<int>
      Q;
  Q.push(source);
  dist[source] = 0;
  permutations[source] = a;

  while (Q.size())
  {
    int u = Q.front();
    Q.pop();

    vector<int> &curPermutation = permutations[u];

    // iterate through all neighbors of u
    for (int i = 1; i < n; ++i)
    {
      vector<int> neighborPermutation = curPermutation;
      reverse(neighborPermutation.begin(), neighborPermutation.begin() + i + 1);

      int v = getIndex(neighborPermutation);
      if (dist[v] >= 0)
        continue;

      dist[v] = dist[u] + 1;

      if (v == target)
      {
        cout << dist[v];
        return;
      }
      permutations[v] = neighborPermutation;
      Q.push(v);
    }
  }
}

// Time complexity: O(N! * N)
// Space complexity: O(N! * N)

int main()
{
  freopen("input/bai18.in", "r", stdin);

  solve();

  return 0;
}
