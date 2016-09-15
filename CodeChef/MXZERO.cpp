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
#define MAX 100005
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	zyloc(){
		lli n,x;
		cin>>n;
		lli hash[2]={0};
		loop(i,0,n-1){
			cin>>x;
			hash[x]++;
		}
		if (hash[1]%2==0){
			cout<<hash[0]<<endl;
		}
		else if (hash[1]%2!=0){
			cout<<hash[1]<<endl;
		}	
	}
	return 0;
}	