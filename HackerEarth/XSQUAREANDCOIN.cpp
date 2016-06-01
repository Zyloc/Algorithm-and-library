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
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
 
int main(){
	zyloc(){
		lli n,k,maxi=INT_MIN,x;
		cin>>n>>k;
		vi(v);
		loop(i,0,n-1){
			cin>>x;
			v.pb(x);
		}
		lli sum=0;
		loop(i,0,n-1){
			if (v[i]<=k){
				sum+=v[i];
			}
			else{
				if (sum>maxi){
					maxi=sum;
				}
				sum=0;
			}
		}
		if (sum>maxi){
				maxi=sum;
		}
		cout<<maxi<<endl;
	}	
    return 0;
}
Language: C++