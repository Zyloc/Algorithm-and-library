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
	lli n,k;
	cin>>n>>k;
	if (k<n/2){
		cout<<-1;
		return 0;
	}
	if (n==1 and k==0){
		cout<<1;
		return 0;
	}
	if (n==1){
		cout<<-1;
		return 0;
	}
	else{
		if (k==n/2){
			loop(i,1,n){
				cout<<i<<" ";
			}
		}
		else{
			lli remaining(k-(n/2)+1);
			cout<<remaining<<" "<<2*remaining<<" ";
			for(lli j=2*remaining+1;j<=	(2*remaining+n-2);j++){
				cout<<j<<" ";
			}
		}
	}
	return 0;
}	