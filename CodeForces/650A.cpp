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

lli combination( lli n, lli k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    lli result = n;
    for( lli i = 2; i <= k; ++i ) {
        result = ((result)*(n-i+1));
        result /= i;
    }
    return result;
}

int main(){
	lli n,x,y;
	cin>>n;
	map<lli,lli> xhash,yhash;
	map<pair<lli,lli>,lli> frq;
	set<pair<lli,lli> > st;
	loop(i,0,n-1){
		cin>>x>>y;
		frq[mp(x,y)]++;
		xhash[x]++;
		yhash[y]++;
	}
	map<lli,lli>::iterator it;
	lli ans=0;
	for(it=xhash.begin();it!=xhash.end();it++){
		if (it->second != 1){
			ans += combination(it->second,2);
		}
	}
	//cout<<st.size()<<" "<<ans<<" ";
	for(it=yhash.begin();it!=yhash.end();it++){
		if (it->second != 1){
			ans += combination(it->second,2);
		}
	}
	for(auto it=frq.begin();it!=frq.end();it++){
		ans -= combination(it->second,2);
	}
	cout<<ans<<endl;
    return 0;
}	