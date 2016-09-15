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
bool isValid(lli a,lli b,lli c){
	if (a+b>c){
		if (b+c>a){
			if (c+a>b){
				return true;
			}
		}
	}
	return false;
}
lli minimumNOofSteps(lli x,lli y){
	lli a(x),b(x),ans(0),c(x);
	while(!(a==y and b==y and c==y)){
		if (a!=y){
			a=y;
			while(!isValid(a,b,c)){
				a++;
			}
			ans++;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;	
		if (a==y and b==y and c==y){
			break;
		}
		if (b!=y){
			b=y;
			while(!isValid(a,b,c)){
				b++;
			}
			ans++;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
		if (a==y and b==y and c==y){
			break;
		}
		if(c!=y){
			c=y;
			while(!isValid(a,b,c)){
				c++;
			}
			ans++;
		}
		cout<<a<<" "<<b<<" "<<c<<endl;
		if (a==y and b==y and c==y){
			break;
		}

	}
	return ans;
}
lli nextpossible(lli a,lli x){
	lli b(x),c(x);
	if (a==x){
		return -1;
	}
	a++;
	while(!isValid(a,b,c)){
		a++;
	}
	return a;
}
int main(){
	lli x,y,a,ans(0),incre(1);
	cin>>x>>y;
	minimumNOofSteps(x,x/3);
	return 0;
}	