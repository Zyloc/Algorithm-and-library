/*
 * Satyam Swarnkar (Zyloc), Nit Silchar
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <stack>
#include <iomanip>
using namespace std;
#define loop(i,start,end) for (int i=start;i<end;i++)
#define pool(i,start,end) for(int i=start;i>=end;i--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
 
int main(){
	lli n,a,b,c,max=0;
	cin>>n;
	vi(v);
	loop(i,0,n){
		cin>>a>>b>>c;
		v.pb(a*3+b-c);
	}	
	sort(v.begin(),v.end());
	cout<<v[n-1];
    return 0;
}
Language: C++