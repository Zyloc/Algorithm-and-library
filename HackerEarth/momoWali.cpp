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
#define MAX 100002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl
lli fact[MAX],inverse[MAX];
lli der[MAX];
lli fast_expo(lli base, lli expo){
	lli res=1;
	while(expo>0){
		if(expo%2==1){
			res=(res*base)%MOD;
		}
		base=(base*base)%MOD;
		expo/=2;
	}
	return res%MOD;
}
lli countDer()
{
	der[0] = 1;
	der[1] = 0;
	der[2] = 1;
	for (lli i=3; i<=MAX-2; ++i)
		der[i] = ((i-1)%MOD*(der[i-1]%MOD + der[i-2]%MOD))%MOD;

	return 0;
}
void precompute(){
	countDer();
	fact[0] = 1;
	loop(i,1,MAX-2){
		fact[i] = (i%MOD*fact[i-1]%MOD)%MOD;
		inverse[i] = fast_expo(fact[i],MOD-2)%MOD;
	}
}
int main(){
	precompute();
	zyloc(){
		lli n;
		cin>>n;
		lli p(der[n]),q(fact[n]);
		lli z = (((q-p+MOD)%MOD)*inverse[q])%MOD;
		cout<<z<<endl;	
	}
	return 0;
}	