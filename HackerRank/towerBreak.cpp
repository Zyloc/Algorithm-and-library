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
lli grundy[MAX];
void precompute(){
	grundy[0]=0;
	grundy[1]=0;
	for(lli i=2;i<MAX;i++){
		lli num(i);
		for(lli j=2;j*j<=i and num!=1;j++){
			while(num%j==0){
				grundy[i]++;
				num/=j;
			}
		}
		if (num>1){
			grundy[i]++;
		}
	}
}
int main(){
	precompute();
	loop(i,0,20){
		cout<<grundy[i]<<" ";
	}
	zyloc(){
		lli n,x,ans(0);
		cin>>n;
		loop(i,0,n-1){
			cin>>x;
			ans ^=grundy[x]; 
		}
		cout<<(ans==0?"2":"1")<<endl;
	}
	return 0;
}	