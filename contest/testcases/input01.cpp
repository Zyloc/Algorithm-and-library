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
#define lli long long int 
#define debug() cout<<"######"<<endl 
bool cmp(lli first,lli second){
	if (first > second){
		return false;
	}
	return true;
}
int main(){
	lli x;
	cin>>x;
	cout<<x<<endl;
	vi(v);
	loop(i,0,10000-1){
		cin>>x;
		cout<<x<<" ";
		v.pb(x);
	}
	sort(v.begin(),v.end(),cmp);
	vi(v2);
    cout<<endl;
    loop(i,0,10000-2){
		if (i!=999){
			cout<<v[i]<<" ";
			v2.pb(v[i]);
		}
	}
	cout<<endl;
	sort(v2.begin(),v2.end());
	loop(i,0,10000-3){
		if (i!=856){
			cout<<v2[i]<<" ";
		}
	}
    return 0;
}	