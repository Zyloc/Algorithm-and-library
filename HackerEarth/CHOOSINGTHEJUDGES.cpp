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
#define MAX 10002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
lli arr[MAX];
lli n;
lli dp[MAX];
lli magicBox(int index){
	if(index>=n){
		return 0;
	}
	if(dp[index]!=-1){
		return dp[index];
	}
	dp[index]=max(arr[index]+magicBox(index+2),magicBox(index+1));
	return dp[index];
}
int main(){
	int l=0;
	zyloc(){
		cin>>n;
		l++;
		loop(i,0,n){
			dp[i]=-1;
		}
		loop(i,0,n-1){
			cin>>arr[i];
		}
		cout<<"Case "<<l<<": "<<magicBox(0)<<endl;
	}		
    return 0;
}
Language: C++