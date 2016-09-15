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
#define MAX 100002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl
vector<lli> city(MAX);
vector<vector<pair<lli,lli> > > ticket(MAX);
lli ans[MAX];
lli magicBox(lli start,lli strengthOfTicket,lli totalPrice){
	//cout<<start<<" "<<totalPrice<<endl;
	lli x(INT_MAX);
	if (start==1){
		return totalPrice;
	}
	
	if (strengthOfTicket == 0){
		//debug();
		loop(i,0,ticket[start].size()-1){
			//cout<<i<<endl;
			//cout<<city[start]<<" "<<ticket[start][i].first<<" "<<endl;
			ans[start] = min(magicBox(city[start],ticket[start][i].first-1,totalPrice+ticket[start][i].second),ans[start]);
		}	
	}
	else{
		lli y(magicBox(city[start],--strengthOfTicket,totalPrice));
		loop(i,0,ticket[start].size()-1){
			ans[start] = min(magicBox(city[start],ticket[start][i].first-1,totalPrice+ticket[start][i].second),ans[start]);
		}
		return min(ans[start],y);
	}
	return ans[start];
} 
int main(){
	lli n,m,x,y,z,q;
	scanf("%lld %lld",&n,&m);
	//cin>>n>>m;
	loop(i,0,n-2){
		scanf("%lld %lld",&x,&y);
		city[x]=y;
		ans[i]=INT_MAX;
	}
	ans[n-1]=INT_MAX;
	ans[n]=INT_MAX;
	ans[1]=0;
	loop(i,0,m-1){
		scanf("%lld %lld %lld",&x,&y,&z);
		ticket[x].pb(mp(y,z));
	}
	cin>>q;
	loop(i,0,q-1){
		scanf("%lld",&x);
		cout<<magicBox(x,0,0)<<endl;
		
	}
	return 0;
}	