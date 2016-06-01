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
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
 
int main(){
	lli t;
	cin>>t;
	while(t--){
		lli n,max=INT_MIN,x;
		cin>>n;
		vi(v);
		max=n;
		loop(i,1,n-1){
			cin>>x;
			if (x+i>max){
				max=x+i;
			}
		}
		loop(i,1,n-1){
			cin>>x;
			if (x+i>max){
				max=x+i;
			}
		}
		cout<<max<<endl;
	}	
    return 0;
}
Language: C++