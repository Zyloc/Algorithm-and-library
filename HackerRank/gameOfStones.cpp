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
#define MAX 101
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
bool ans[MAX];
void precompute(){
	ans[0]= 0;
	ans[1]= 0;
	ans[2]= 1;
	ans[3]= 1;
	ans[4]= 1;
	ans[5]= 1;
	for(lli i=6;i<MAX;i++){
		if (!(ans[i-2] & ans[i-3] & ans[i-5])){
			ans[i]=1;
		}
		else{
			ans[i]=0;
		}
	} 
}
int main(){
	precompute();
	zyloc(){
		lli n;
		cin>>n;
		cout<<(ans[n]>0?"First":"Second")<<endl;
	}
	return 0;
}	