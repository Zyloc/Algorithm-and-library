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
#include <list>  
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
#define MAX 104
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli a,b,c,d,e,sum(0),x;
	lli ans[MAX]={0};
	cin>>a>>b>>c>>d>>e;
	ans[a]++;
	ans[b]++;
	ans[c]++;
	ans[d]++;
	ans[e]++;
	if ((a+b+c+d+e)%5 == 0){
		x = (a+b+c+d+e)/5;
		cout<<(x>0?x:-1)<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
	return 0;
}	