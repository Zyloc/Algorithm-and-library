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
	string s[1000];
	lli n,m;
	cin>>n>>m;
	vector<pair<lli,lli> > v;
	loop(i,0,n-1){
		cin>>s[i];
		loop(j,0,m-1){
			if (s[i][j]=='*'){
				v.pb(mp(i,j));
			}
		}
	}
	lli xMax(INT_MIN),yMax(INT_MIN),cnt(0),rowX(0),colY(0);
	loop(i,0,n-1){
		loop(j,0,m-1){
			if (s[i][j]=='*'){
				cnt++;
			}
		}
		if (cnt>xMax){
			xMax = cnt;
			rowX = i;
		}
		cnt=0;
	}
	cnt=0;
	loop(i,0,m-1){
		loop(j,0,n-1){
			if (s[j][i]=='*'){
				cnt++;
			}
		}
		if (cnt>yMax){
			yMax = cnt;
			colY = i;
		}
		cnt=0;
	}
	if(xMax+yMax-1==v.size()){
		cout<<"YES"<<endl;
		cout<<rowX+1<<" "<<colY+1<<endl;
	}
	else{
		cout<<"NO";
	}
    return 0;
}	