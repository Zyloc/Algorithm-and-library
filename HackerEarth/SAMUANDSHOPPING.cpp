/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <iomanip>
#include <functional>
#include <limits.h> 
using namespace std;
#define loop(i,start,end) for (int i=start;i<=end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
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
lli a[MAX][3],n;
lli dp[MAX][3];
lli magicBox(lli shopNumber,lli item){
	if (shopNumber>=n)
		return 0;
	if (dp[shopNumber][item]!=-1 and item!=-1){
		return dp[shopNumber][item];
	}
	if (item==0)
		dp[shopNumber][item]=min(a[shopNumber][item]+magicBox(shopNumber+1,item+1),a[shopNumber][item]+magicBox(shopNumber+1,item+2));
	else if(item==1){
		dp[shopNumber][item]=min(a[shopNumber][item]+magicBox(shopNumber+1,item-1),a[shopNumber][item]+magicBox(shopNumber+1,item+1));
	}
	else if(item==2){
		dp[shopNumber][item]=min(a[shopNumber][item]+magicBox(shopNumber+1,item-2),a[shopNumber][item]+magicBox(shopNumber+1,item-1));
	}
	else{
		magicBox(0,0);
		magicBox(0,1);
		magicBox(0,2);	
	}
	return dp[shopNumber][item];
}
int main(){
	zyloc(){
		cin>>n;
		loop(i,0,n){
			loop(j,0,2){
				dp[i][j]=-1;
			}
		}
		loop(i,0,n-1){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		magicBox(0,-1);
		int min=INT_MAX;
		loop(i,0,0){
			loop(j,0,2){
				if(min>dp[i][j]){
					min=dp[i][j];
				}
			}
			cout<<min<<endl;
		}
		
	}	
    return 0;
}
Language: C++