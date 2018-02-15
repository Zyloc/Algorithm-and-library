#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

const int MOD = 1e9+7;
const int MOD_PHI = 77760;
const int MOD_PR[4] = {3, 11, 13, 37};
const int MOD_PW[4] = {3, 1, 1, 1};
const int MOD_PART[4] = {27, 11, 13, 37};
#define lli long long int
lli fast_expo(lli base, lli expo,lli MODE){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MODE;
		}
		base=(base*base)%MODE;
		expo/=2;
	}
	return res%MODE;
}
int64 binpow(int64 a, int b, int MOD) {
  int64 res = 1;
  while (b)
    if (b & 1) {
      res = res * a % MOD;
      b--;
    } else {
      a = a * a % MOD;
      b >>= 1;
    }
  return res;
}

int gcd(int a, int b) {
  return a == 0 ? b : gcd(b % a, a);
}

int calc_pw(int n, int pr) {
  int res = 0;
  n /= pr;
  while (n) {
    res += n;
    n /= pr;
  }

  return res;
}

struct c_calculator {
  int MOD, prime, phi;
  int64 fact_mod[110];

  c_calculator(int MOD, int prime): MOD(MOD), prime(prime) {
    phi = 0;
    for (int i = 1; i < MOD; i++)
      if (gcd(i, MOD) == 1)
        phi++;

    fact_mod[0] = 1;
    for (int i = 1; i <= 2 * MOD; i++) {
      fact_mod[i] = fact_mod[i - 1];
      if (gcd(i, MOD) == 1)
        fact_mod[i] = fact_mod[i] * i % MOD;
    }
  }

  pair<int64, int> fact(int n) {
    int pw = calc_pw(n, prime);
    int64 r = 1;
    while (n) {
      r = r * fact_mod[n % (2 * MOD)] % MOD;
      n /= prime;
    }

    return mp(r, pw);
  }

  int64 rev(int64 a) {
    return binpow(a, phi - 1, MOD);
  }

  pair<int, int> c(int n, int k) {
    pair<int64, int> x = fact(n);
    pair<int64, int> y = fact(k);
    pair<int64, int> z = fact(n - k);
    return mp(int(x.fs * rev(y.fs) * rev(z.fs) % MOD), x.sc - y.sc - z.sc);
  }
};

vector<c_calculator> a;
map<vector<pair<int, int> >, int> to;

pair<int64, int64> mrg(pair<int64, int64> a, pair<int64, int64> b, c_calculator& c) {
  //a.fs + x * a.sc == b.fs (mod b.sc)
  b.fs = ((b.fs - a.fs) % b.sc + b.sc) % b.sc;
  int64 x = b.fs * c.rev(a.sc) % b.sc;
  return mp(a.fs + x * a.sc, a.sc * b.sc);
}

inline int solve(int n, int k) {
  a[2].c(n, k);
  vector<pair<int, int> > b(4);
  int64 mult = 1;
  forn(i, 4) {
    b[i] = a[i].c(n, k);
    mult = mult * binpow(MOD_PR[i], b[i].sc, MOD) % MOD;
    if (b[i].sc >= MOD_PW[i])
      b[i].fs = 0;
    else
      forn(j, b[i].sc)
        b[i].fs = b[i].fs * MOD_PR[i] % MOD_PART[i];
  }

  pair<int64, int64> f(b[0].fs, MOD_PART[0]);
  for (int i = 1; i < 4; i++) {
    f = mrg(f, mp(b[i].fs, MOD_PART[i]), a[i]);
  }

  return int(f.fs % MOD);
}

int c[5100][5100];

int main() {
  forn(i, 4)
    a.pb(c_calculator(MOD_PART[i], MOD_PR[i]));

  /*int tt;
  cin >> tt;
  
  forn(ii, tt) {
    int n, k;
    scanf("%d%d", &n, &k);
//    n = INF;
//    k = ii;
    if (n - k < k)
      k = n - k;

    
    printf("%d\n", res);
  }*/
    map<pair<int, int>, int> cache;
  int n,p,ans(0);
  cin>>n>>p;
  for(int i(1);i<=p;i++){
	  	int res,k=i;
	    if (cache.count(mp(n, k)))
	      res = cache[mp(n, k)];
	    else {
	      res = solve(n, k);
	      cache[mp(n, k)] = res;
	    }
	    long long int temp = (res*fast_expo(i,p,MOD))%MOD; 
	   	ans = (ans+temp)%MOD;
	    
  }
  cout<<ans<<endl;
  return 0;
}