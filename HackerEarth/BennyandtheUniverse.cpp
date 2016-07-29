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
vi(v);
int counte( int m, int n )
{
	// table[i] will be storing the number of solutions for
	// value i. We need n+1 rows as the table is consturcted
	// in bottom up manner using the base case (n = 0)
	int table[n+1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	table[0] = 1;

	// Pick all coins one by one and update the table[] values
	// after the index greater than or equal to the value of the
	// picked coin
	for(int i=0; i<m; i++)
		for(int j=v[i]; j<=n; j++)
			table[j] += table[j-v[i]];

	return table[n];
}

int main()
{
	lli n,q,x;
	cin>>n>>q;
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	loop(i,0,q-1){
		cin>>x;
		if(counte(n, x)!=0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}	
	}
	
	return 0;
}
	