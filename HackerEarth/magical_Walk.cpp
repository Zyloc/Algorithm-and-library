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
lli nextIndex(lli n,lli end){
	if (n==end){
		return 0;
	}
	else{
		return n+1;
	}
}
int main(){
	zyloc(){
		lli n,x,money,start,direction,oneRoundCost(0);
		vi(v);
		cin>>n;
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
			oneRoundCost+= x;
		}
		cin>>start>>money>>direction;
		start--;
		money = money%oneRoundCost;
		if (direction == 1){
			debug();
			loop(i,0,2*n){
				if (money<v[nextIndex(start+i,n)%n]){
					cout<<i+1<<endl;
					break;
				}
				money -= v[(start+i)%n];
			}
		}
		else{
			loop(i,0,2*n){
				if (money<v[nextIndex((start-i)%n,n)%n]){
					cout<<i+1<<endl;
					break;
				}
				money -= v[(start-i)%n];
			}	
		}	
	}
	return 0;
}	