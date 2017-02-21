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
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
lli prefix[MAX];
lli n,x;
bool check(lli size){
	for(lli i=size;i<=n;i++){
		if (prefix[i] - prefix[i-size] > x){
			return false;
		}
	}
	return true;
}
int main(){
	bool flag(false);
	scanf("%lld %lld,",&n,&x);
	loop(i,1,n){
		scanf("%lld,",&prefix[i]);
		if (prefix[i] > x){
			flag = true;
		}
		prefix[i] += prefix[i-1];	
	}
	if (flag){
		cout<<-1<<endl;
		return 0;
	}
	lli low(0),high(n),mid;
	while(low < high){
		mid = low + (high-low)/2;
		for(lli i=mid;i<=n;i++){
			if (prefix[i] - prefix[i-mid] > x){
				flag = true;
				break;
			}
		}
		if (!flag){
			low = mid;
		}
		else{
			high = mid - 1;
		}
	}
	cout<<low<<endl;
	return 0;
}	