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
#define MAX 100001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl
lli grunde[MAX];
void seive(){
	loop(i,2,MAX-1){
		lli num(i);
		for(lli j=2;j*j<MAX and num!=1;j++){
			while(num%j==0){
				num/=j;
				grunde[i]++;
			}
		}
		if (num!=1){
			grunde[i]++;
		}		
	}
}
int main(){
	seive();
	lli n,x,ans(0);
	cin>>n;
	loop(i,0,n-1){
		cin>>x;
		ans^=grunde[x];
	}
	if (ans == 0){
		cout<<"BOB"<<endl;
	}
	else{
		cout<<"ALICE"<<endl;
	}
	return 0;
}	