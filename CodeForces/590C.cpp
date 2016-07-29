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
	lli n,m,count1=0;
	cin>>n>>m;
	if (2*min(n,m)<=max(n,m)){
		cout<<min(n,m)<<endl;
	}
	else {
		while(min(n,m)>=1 and max(n,m)>=2){
			if (n>m){
				swap(n,m);
			}
			n-=1;
			m-=2;
			count1++;

		}

		cout<<count1<<endl;
	}
    return 0;
}