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
bool cmp(pair<string,lli> p1,pair<string,lli> p2){
	if (p1.second>p2.second){
		return true;
	}
	else if (p1.second == p2.second){
		return p1.first<p2.first;
	}
	return false;
}
int main(){
	lli n,k,x;
	cin>>n>>k;
	vector<pair<string,lli> > v;
	string s;
	loop(i,0,n-1){
		cin>>s>>x;
		v.pb(mp(s,x));
	}
	sort(v.begin(),v.end(),cmp);
	loop(i,0,k-1){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;
}	