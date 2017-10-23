#pragma GCC target("popcnt")
#include <cctype>
#include <cassert>
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace std;

int r[105], b[105];
int parent[105];

int getparent(int t)
{
    return parent[t] == t ? t : parent[t] = getparent(parent[t]);
}
bool merge(int a, int b)
{
    a = getparent(a); b = getparent(b);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    for (int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d: ", tt);

        int n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++) scanf("%d",&r[i]);
        for (int i = 0; i < n; i++) scanf("%d",&b[i]);
        for (int i = 0; i < n; i++) parent[i] = i;

        vector<tuple<int, int, int>> vt;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                vt.emplace_back(min(r[i] ^ b[j], r[j] ^ b[i]), i, j);
            }
        }

        sort(vt.begin(), vt.end());

        long long ans = 0;

        for (auto &e : vt)
        {
            int a, b, c;
            tie(a, b, c) = e;

            if (merge(b, c) == false) continue;
            ans += a;
        }
        printf("%lld\n", ans);
    }
}

