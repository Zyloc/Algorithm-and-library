/*
 * I felt , I felled and I failed :(
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
#define MAX 51
using namespace std;

lli dp[MAX][MAX][MAX][MAX];

lli ans(int i1, int i2, int j1, int j2){
    if(i1==i2) return 0;
    if(j1==j2) return 0;
    
    long val = dp[i1][i2][j1][j2];
    val += ans(i1+1, i2, j1, j2);
    val += ans(i1, i2-1, j1, j2);
    val += ans(i1, i2, j1+1, j2);
    val += ans(i1, i2, j1, j2-1);
    return val;
}

lli solve(int i1, int i2, int j1, int j2){
    if(i1==i2) return 0;
    if(j1==j2) return 0;
    if(dp[i1][i2][j1][j2] != null) return dp[i1][i2][j1][j2];
    long ans = 0;
    if(s1.charAt(i2-1)==s2.charAt(j2-1)){
        return dp[i1][i2][j1][j2] = 
        Math.max(
            1+solve(i1, i2-1, j1, j2-1),
            Math.max(
                Math.max(solve(i1+1, i2, j1, j2), solve(i1, i2-1, j1, j2)),
                Math.max(solve(i1, i2, j1+1, j2), solve(i1, i2, j1, j2-1))
                )
            );
    }
    
    return dp[i1][i2][j1][j2] = Math.max(
        Math.max(solve(i1+1, i2, j1, j2), solve(i1, i2-1, j1, j2)),
        Math.max(solve(i1, i2, j1+1, j2), solve(i1, i2, j1, j2-1))
        );
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}
