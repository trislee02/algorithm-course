#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

#define min(a, b) a < b ? a : b
const long long oo = 1e18;

// void swap(vector<int> &a, int pa, int pb)
// {
//   int tmp = a[pa];
//   a[pa] = a[pb];
//   a[pb] = tmp;
// }

// void quicksort(vector<int> &a, vector<int> &cluster, vector<int> &group, int start, int end)
// {
//   if (start >= end)
//     return;
//   int pivot = a[start];
//   int left = start + 1, right = end;
//   while (left < right)
//   {
//     while (left <= end && a[left] >= pivot)
//       ++left;
//     while (right >= 0 && a[right] <= pivot)
//       --right;
//     swap(a, left, right);
//     swap(cluster, left, right);
//     swap(group, left, right);
//   }
//   swap(a, left, right);
//   swap(cluster, left, right);
//   swap(group, left, right);
//   swap(a, right, start);
//   swap(cluster, right, start);
//   swap(group, right, start);

//   quicksort(a, cluster, group, start, right - 1);
//   quicksort(a, cluster, group, right + 1, end);
// }

// // O(n*n)
// int approach1()
// {
//   int k, m, n, c1, c2, i, res = 0;
//   vector<int> a, cluster, group;
//   unordered_set<int> picked;
//   cin >> k >> m >> n;
//   for (i = 0; i < k; ++i)
//   {
//     cin >> c1 >> c2;
//     a.push_back(c1);
//     a.push_back(c2);

//     cluster.push_back(1);
//     cluster.push_back(2);

//     group.push_back(i);
//     group.push_back(i);
//   }

//   quicksort(a, cluster, group, 0, a.size() - 1);

//   i = 0;
//   while (m + n > 0)
//   {
//     if (picked.find(group[i]) == picked.end())
//     {
//       // Which cluster to choose if a group has largest values of both cluster.
//       if (cluster[i] == 1 && n > 0)
//       {
//         res += a[i];
//         --n;
//       }
//       if (cluster[i] == 2 && m > 0)
//       {
//         res += a[i];
//         --m;
//       }
//       picked.insert(group[i]);
//     }
//     ++i;
//   }

//   cout << res;
// }

void solve()
{
  int k, m, n;
  cin >> k >> n >> m;
  vector<pair<int, int>> a(k);

  for (pair<int, int> &pp : a)
  {
    cin >> pp.second >> pp.first;
  }

  sort(a.begin(), a.end(), greater<pair<int, int>>());

  //
  vector<long long> f(n + 1, -oo);
  f[0] = 0;

  for (int i = 0; i < k; ++i)
  {
    for (int j = min(n, i); j >= 0; --j)
      if (f[j] > -oo)
      {
        // choose a[i] to group A
        if (j + 1 <= n)
          f[j + 1] = max(f[j + 1], f[j] + a[i].second);
        // not choose a[i] to group A
        if (i + 1 - j <= m)
          f[j] = max(f[j], f[j] + a[i].first);
      }
  }

  cout << f[n];
}
// Time complexity: O(N^2)
// Space complexity: O(N)

int main()
{
  freopen("input/bai11.in", "r", stdin);
  //    freopen("output/bai11.out", "w",stdout);

  solve();
  // approach1();

  return 0;
}
