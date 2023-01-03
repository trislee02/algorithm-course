#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

#define min(a, b) a < b ? a : b
typedef long long ll;

// //
// int approach1()
// {
//   int n, t, tmp, lowest, high, numHigh;
//   cin >> n >> t;
//   lowest = INT_MAX;
//   high = -INT_MAX;
//   for (int i = 0; i < n, ++i)
//   {
//     cin >> tmp;
//     if (tmp < lowest)
//       lowest = tmp;
//     if (tmp > high)
//     {
//       high = tmp;
//       numHigh = 1;
//     }
//     if (tmp == high)
//       ++numHigh;
//   }

//   if (high == lowest)
//     numHigh = 0;

//   while (t > 0)
//   {
//     if (numHigh == 0)
//     {
//       --lowest;
//       numHigh = n - 1;
//     }
//     else
//       --numHigh;
//     --t;
//   }
//   cout << lowest;
// }
const int S = 17;
const long long oo = 1e18 + 111;

class RMQContainer
{
  vector<int> f;
  vector<vector<long long>> rmq;

public:
  RMQContainer(vector<int> &_f)
  {
    int n = _f.size();
    rmq.assign(n, vector<long long>(17, oo));

    for (int i = 0; i < n; ++i)
      rmq[i][0] = _f[i];
    for (int j = 1; j < S; ++j)
    {
      for (int i = 0; i + (1 << j) - 1 < n; ++i)
      {
        rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  long long getMin(int l, int r)
  {
    if (l > r)
      return oo;
    int m = log2(r - l + 1);
    return min(rmq[l][m], rmq[r - (1 << m) + 1][m]);
  }
};

long long getSum(int l, int r, vector<long long> &prefixSum)
{
  if (l > r)
    return 0;
  long long result = 0;
  if (l == 0)
    result = prefixSum[r];
  else
    result = prefixSum[r] - prefixSum[l - 1];
  return result;
}
bool checkReachableDepth(vector<int> &a, long long T, long long d, vector<long long> &prefixSum, RMQContainer &rmqLeft, RMQContainer &rmqRight)
{
  // for each position i, find the min cost to dig to depth d at that position
  int n = a.size();
  for (int i = 0; i < n; ++i)
  {
    // find the last unchanged position to the left of i
    int lastLeftUnchangedPos = -1;
    {
      /* if j is last unchanged position to the left of i
        <=> a[j] <= depth + (i - j)
        <=> a[j] + j <= depth + i

        fLeft[k] = a[k] + k
        <=> min(fLeft[j -> i - 1]) <= depth + i
      */
      int l = 0, r = i - 1;
      while (l <= r)
      {
        int mid = (l + r) >> 1;
        if (rmqLeft.getMin(mid, i - 1) <= d + i)
        {
          lastLeftUnchangedPos = mid;
          l = mid + 1;
        }
        else
          r = mid - 1;
      }
    }

    // find the first unchanged position to the right of i
    int firstRightUnchangedPos = n;
    {
      /* if j is first unchanged position to the right of i
   <=> a[j] <= depth + (j - i)
   <=> a[j] - j <= depth - i

   fRight[k] = a[k] - k
   <=> min(fRight[i + 1 -> j]) <= depth - i
 */
      int l = i + 1, r = n - 1;
      while (l <= r)
      {
        int mid = (l + r) >> 1;
        if (rmqRight.getMin(i + 1, mid) <= d - i)
        {
          firstRightUnchangedPos = mid;
          r = mid - 1;
        }
        else
          l = mid + 1;
      }
    }

    // calculate the cost if we dig to depth d at position i
    /*
    i => a[i] - d
    left part:
      i - 1 => a[i - 1] - (d + 1)
      i - 2 => a[i - 2] - (d + 2)
      ...
      lastLeftUnchangedPos + 1 => a[lastLeftUnchangedPos + 1] - (d + i - (lastLeftUnchangedPos + 1))
      nLEft = i - lastLeftUnchangedPos - 1
      = sum(a[lastLeftUnchangedPos + 1 => i - 1]) - d * nLeft - nLeft(nLeft + 1)/2

    right part:
      i + 1 => a[i + 1] - (d + 1)
      i + 2 => a[i + 2] - (d + 2)
      ...
      firstRightUnchangedPos - 1 => a[firstRightUnchangedPos - 1] - (d + (firstRightUnchangedPos - 1) - i)
      nRight = firstRightUnchangedPos - 1 - i
      = sum(a[i + 1 -> firstRightUnchangedPos - 1]) - d * nRight - nRight(nRight + 1)/2
    */
    long long curMinCost = 1LL * a[i] - d;
    int nLeft = i - lastLeftUnchangedPos - 1;
    curMinCost += getSum(lastLeftUnchangedPos + 1, i - 1, prefixSum) - d * nLeft - (1LL * nLeft * (nLeft + 1)) / 2;

    int nRight = firstRightUnchangedPos - 1 - i;
    curMinCost += getSum(i + 1, firstRightUnchangedPos - 1, prefixSum) - d * nRight - (1LL * nRight * (nRight + 1)) / 2;

    if (curMinCost <= T)
      return true;
  }
  return false;
}
void solve()
{
  int n;
  long long T;
  cin >> n >> T;
  vector<int> a(n);

  for (int &x : a)
    cin >> x;

  vector<int> fLeft(n), fRight(n);
  for (int i = 0; i < n; ++i)
  {
    fLeft[i] = a[i] + i;
    fRight[i] = a[i] - i;
  }

  vector<long long> prefixSum(n);
  prefixSum[0] = a[0];
  for (int i = 1; i < n; ++i)
    prefixSum[i] = prefixSum[i - 1] + a[i];

  RMQContainer rmqLeft(fLeft),
      rmqRight(fRight);

  //
  long long sumA = 0;
  for (int x : a)
    sumA += x;

  // sum(A) - d * n >= T
  // <=> sum(A) - T >= d * n
  // <=> d <= (sum(A) - T)/n

  long long result = *min_element(a.begin(), a.end());
  ; // actually this value is not correct, it will be updated in the binary search

  long long l = -T, r = floor((1.0 * sumA - T) / n);

  while (l <= r)
  {
    long long mid = (l + r) >> 1;
    if (checkReachableDepth(a, T, mid, prefixSum, rmqLeft, rmqRight))
    {
      result = mid;
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  cout << result;
}

int main()
{
  freopen("input/bai19.in", "r", stdin);
  //  freopen("output/bai16.out", "w",stdout);

  // approach1();
  solve();

  return 0;
}
