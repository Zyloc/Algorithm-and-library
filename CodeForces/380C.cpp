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
	lli n,x,y;
	string s;
	cin>>s;
	stack<char> st;
	lli ans[MAX]={0};
	loop(i,0,s.length()-1){
		if (s[i]=='('){
			st.push(s[i]);
			if (i>0)
				ans[i] = ans[i-1];
		}
		else{
			if (!st.empty() and st.top()=='('){
				ans[i] = ans[i-1] + 1;
				st.pop();
			}
			else{
				ans[i] = ans[i-1];
			}
		}
	}
	cin>>n;
	loop(i,0,n-1){
		cin>>x>>y;
		x--;
		y--;
		cout<<2*(ans[y]-ans[x])<<endl;
	}
	return 0;
}	