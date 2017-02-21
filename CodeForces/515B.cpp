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
	lli n,m,b,g,x;
	cin>>n>>m;
	bool boy[n],girl[m];
	memset(boy,false,sizeof(boy)/sizeof(bool));
	memset(girl,false,sizeof(girl)/sizeof(bool));
	cin>>b;
	loop(i,0,b-1){
		cin>>x;
		boy[x]=true;
	}
	cin>>g;
	loop(i,0,g-1){
		cin>>x;
		girl[x]=true;
	}
	loop(i,0,2*(n*m)){
		if (boy[i%n] || girl[i%m]){
			boy[i%n]=true;
			girl[i%m]=true;
		}
	}
	loop(i,0,n-1){
		if (!boy[i]){
			cout<<"No";
			//cout<<i<<" ";
			return 0;
		}
	}
	loop(i,0,m-1){
		if (!girl[i]){
			//cout<<i<<" ";
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}	
