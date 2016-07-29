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
#define MAX 10000;
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli unsigned long long int 
#define debug() cout<<"######"<<endl 

bool cmp(lli first,lli second){
	if (first>second){
		return true;
	}
	return false;
}
int main(){
	lli n,x;
	cin>>n;
	vi(v);
	vi(v2);
	vi(v3);
	loop(i,0,n-1){
		x = rand()%1000;
		v.pb(x);
		v2.pb(x);
	}
	sort(v2.begin(),v2.end()-1,cmp);
	loop(i,0,n-2){
		v3.pb(v2[i]);
	}
	sort(v3.begin(),v3.end());
	cout<<n<<endl;
	loop(i,0,n-1){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	loop(i,0,n-2){
		cout<<v2[i]<<" ";
	}
	cout<<endl;
	loop(i,0,n-3){
		cout<<v3[i]<<" ";
	}
	cout<<endl;
    return 0;
}	