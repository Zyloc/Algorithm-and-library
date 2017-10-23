#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <array>
#include <initializer_list>
#include <random>
#include <regex>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
using namespace std;

int dp[45][45][45][45];
int dat[45][45];

struct mintree
{
    int z[128];

    void update(int pos, int val)
    {
        pos += 64;
        z[pos] = val;
        while (pos >>= 1)
            z[pos] = min(z[pos << 1], z[pos << 1 | 1]);
    }

    int query(int l, int r)
    {
        int ret = INT_MAX;
        l += 64; r += 64;
        while (l <= r)
        {
            if (l & 1) ret = min(ret, z[l++]);
            if (!(r & 1)) ret = min(ret, z[r--]);
            l >>= 1; r >>= 1;
        }
        return ret;
    }
} tree[45];

int D(int l, int r, int u, int d)
{
    if (l == r && u == d) return 0;

    if (dp[l][r][u][d] == 0)
    {
        int x = INT_MAX;
        for (int i = l; i <= r; i++) x = min(x, tree[i].query(u, d));

        for (int i = l; i < r; i++)
        {
            dp[l][r][u][d] = max(dp[l][r][u][d], D(l, i, u, d) + D(i + 1, r, u, d) + x);
        }

        for (int i = u; i < d; i++)
        {
            dp[l][r][u][d] = max(dp[l][r][u][d], D(l, r, u, i) + D(l, r, i + 1, d) + x);
        }
    }

    return dp[l][r][u][d];
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);
        memset(tree, 0x7f, sizeof(tree));

        int n, m;
        scanf("%d%d",&n,&m);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        {
            scanf("%d",&dat[i][j]);
            tree[i].update(j, dat[i][j]);
        }

        memset(dp, 0, sizeof(dp));

        printf("%d\n", D(0, n - 1, 0, m - 1));
    }
}

