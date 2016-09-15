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
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 
lli getMinimum(lli n,lli m){
	lli x(n/m),last(x+1);
	return (((x*(x-1)*(m-n%m))/2)+((last*(last-1)*(n%m))/2));
}
lli getMaximum(lli n,lli m){
	n-=(m-1);
	return (n*(n-1))/2;
}
int main(){
	lli n,m;
	cin>>n>>m;
	cout<<getMinimum(n,m)<<" "<<getMaximum(n,m)<<endl;
	return 0;
}	