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
#define MAX 10002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli n,x0,y0,x1,y1,gcd;
	cin>>n>>x0>>y0;
	set<pair<lli,lli> > st;
	loop(i,0,n-1){
		cin>>x1>>y1;
		if (x1-x0==0){
			st.insert(mp(MAX,MAX));
		}
		else{
			gcd = __gcd((y1-y0),(x1-x0));
			st.insert(mp((y1-y0)/gcd,(x1-x0)/gcd));
			//cout<<slope<<endl;
		}
	}
	cout<<st.size()<<endl;;
    return 0;
}	