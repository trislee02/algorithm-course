#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>
using namespace std;

long long _try(long long factor, long long m, int n)
{
  if (factor == 0)
  {
    if (m > 0 && m % n == 0)
    {
      return m;
    }
    return -1; // FIXED: unsigned int -> long long to hold value -1
  }
  else
  {
    long long x = _try(factor / 10, m, n);
    if (x == -1)
    {
      return _try(factor / 10, factor + m, n);
    }
    return x;
  }
}

// O(n)
void approach1()
{
  int n;
  long long m = 0;
  cin >> n;
  cout << _try(100000000, m, n);
}

int main()
{
  freopen("input/bai17.in", "r", stdin);
  //  freopen("output/bai17.out", "w",stdout);

  approach1();

  return 0;
}
