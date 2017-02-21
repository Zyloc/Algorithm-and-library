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
	zyloc(){	
		lli m,n,a,b,zero(0);
		cin>>m>>n>>a>>b;
		bool maxMoney[n+1];
		loop(i,0,n){
			maxMoney[i] = false;
		}
		if (a>b){
			swap(a,b);
		}
		loop(i,a,n){
			if (i==a){
				maxMoney[i] = true;
			}
			else if (i==b){
				maxMoney[i] = true;
			}
			else{
				if (maxMoney[i-a] or maxMoney[max(zero,i-b)]){
					maxMoney[i] = true;
				}
			}
		}
		lli ans(INT_MAX);
		pool(i,n,a){
			if (maxMoney[i]){
				lli noOfBags;
				noOfBags = m/i;
				if (m%i!=0){
					noOfBags++;
				}
				cout<<noOfBags<<endl;
				break;
			}
		}
	}
	return 0;
}	