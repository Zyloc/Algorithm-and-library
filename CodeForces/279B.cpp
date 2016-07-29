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

int main(){
	lli n,t,x;
	vi(v);
	cin>>n>>t;
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
	}
	lli globalMax = 0,localMax=0,localTime = t,firstPointer = 0,start = 0;
	for(int i=0;i<n;i++){ 
		if (v[i] <= localTime){
			localTime -= v[i];
			localMax++;
		}
		else{
			globalMax = localMax > globalMax ? localMax : globalMax;
			localTime += v[start];
			start++;
			localMax--;
			i--;
		}
	}
	globalMax = localMax > globalMax ? localMax : globalMax;	
	cout<<globalMax<<endl;
    return 0;
}	