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
#define MAX 1000000005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli n,k,x,sum(0);
	cin>>n>>k;
	vi(v);
	map<lli,lli> mp;
	loop(i,0,n-1){
		cin>>x;
		mp[x]++;
		v.pb(x);
		sum+=x;
	}
	sort(v.begin(),v.end());
	lli li(sum),lu(0);
	loop(i,0,k-1){
		if (li>lu){
			lli dif(li-lu),give(lower_bound(v.begin(),v.end(),dif)-v.begin());
			//cout<<give<<endl;
			if (give>=n){
				give--;
			}
			li -= v[give];
			lu += v[give]; 
		}
	}
	cout<<lu<<endl;
	return 0;
}	