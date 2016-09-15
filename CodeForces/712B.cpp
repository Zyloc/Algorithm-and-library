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
	string s;
	cin>>s;
	lli x(0),y(0);
	loop(i,0,s.length()-1){
		if (s[i]=='L'){
			x--;
		}
		else if(s[i]=='R'){
			x++;
		}
		else if (s[i]=='U'){
			y++;
		}
		else if(s[i]=='D'){
			y--;
		}
	}
	//cout<<x<<" "<<y;
	if (abs(x)%2==0 and abs(y)%2==0){
		cout<<abs(x)/2+abs(y)/2<<endl;
	}
	else if ((abs(x)+abs(y))%2==0){
		lli ans(0);
		ans+= abs(x)/2;
		ans+= abs(y)/2;
		ans += 1;
		cout<<ans<<endl;
	}
	else{
		cout<<-1<<endl;
	}
	return 0;
}	