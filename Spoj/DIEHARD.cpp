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
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 

int main(){
	zyloc(){
		lli h,a;
		cin>>h>>a;
		int count1=1;
		int dp[1004][1004];
		fill(dp,-1);
		h+=3;
		a+=2;
		while(h>0 and a>0){
			if (h>5 and a>10){
				count1+=2;
				h-=2;
				a-=8;
			}
			else if(h>20 and a>=0){
				count1+=2;
				h-=17;
				a+=7;
			}
			else{
				break;
			}
		}
		cout<<count1<<endl;
	}	
    return 0;
}