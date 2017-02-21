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
	lli time,stone,coin,x,powerOfCoins(0);
	cin>>time>>stone>>coin;
	loop(i,0,stone-1){
		cin>>x;
		powerOfCoins+=x;
	}
	vi(cost);
	loop(i,1,stone*time){
		cin>>x;
		cost.pb(x);
	}
	sort(cost.begin(),cost.end());
	lli countCoin(0);
	loop(i,0,cost.size()-1){
		if (coin > 0){
			if (coin-cost[i] >= 0){
				coin-=cost[i];
				countCoin++;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	cout<<countCoin+powerOfCoins<<endl;
	return 0;
}	