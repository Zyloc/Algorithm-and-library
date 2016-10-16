/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
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
	lli n,x,y,q;
	cin>>n;
	vector<lli> parent(n+1);
	loop(i,0,n-2){
		cin>>x>>y;
		parent[y] = x;
	}
	cin>>q;
	loop(i,0,q-1){
		cin>>x>>y;
		lli count(y);
		while(count!=0){
			x = parent[x];
			count--;
		}
		if(x==0){
			cout<<1<<endl;
		}
		else
			cout<<x<<endl;
	}
	return 0;
}	