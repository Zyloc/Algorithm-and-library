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
	lli n,x;
	cin>>n;
	lli a[4]={0};
	loop(i,1,n){
		cin>>x;
		if (i%3==1){
			a[1]+=x;
		}
		else if(i%3==2){
			a[2]+=x;
		}
		else{
			a[3]+=x;
		}
	}	
	cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
    return 0;
}
Language: C++