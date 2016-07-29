/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h>
#include <list>  
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli n(0);
	cin>>n;
	lli *boss = new lli[n+1];
	loop(i,1,n){
		cin>>boss[i];
	}
	lli *memo = new lli[n+1];
	fill(memo,0);
	lli ans(0);
	loop(i,1,n){
		lli start(i),noOfBoss(0);
		while((boss[start]!=-1)){
			if (memo[start]!=0){
				noOfBoss += (memo[start]);
				break;
			}
			start = boss[start];
			noOfBoss++;
		}
		if (noOfBoss > ans){
			ans = noOfBoss;
		}
		memo[i] = noOfBoss;
	}
	cout<<++ans<<endl;
	delete[] boss;
	delete[] memo;
    return 0;
}	