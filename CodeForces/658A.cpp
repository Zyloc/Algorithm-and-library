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
lli max(lli a,lli b){
	return a>b?a:b;
}
int main(){
	lli n,c,x,sum=0,limak_score=0,rade_score=0;
	vector<int> points,tme;
	cin>>n>>c;
	loop(i,0,n-1){
		cin>>x;
		points.pb(x);
	}
	loop(i,0,n-1){
		cin>>x;
		tme.pb(x);
	}	
	loop(i,0,n-1){
		if(i>0){
			limak_score+=max(0,points[i]-(tme[i]+sum)*c);
			sum+=tme[i];
		}
		else{
			limak_score=max(0,points[0]-tme[0]*c);
			sum=tme[0];
		}
	}
	pool(i,n-1,0){
		if(i==n-1){
			rade_score=max(0,points[i]-tme[i]*c);
			sum=tme[i];
		}
		else{
			rade_score+=max(0,(points[i]-(tme[i]+sum)*c));
			sum+=tme[i];
		}
	}
	if(limak_score>rade_score){
		cout<<"Limak"<<endl;
	}
	else if(rade_score>limak_score){
		cout<<"Radewoosh"<<endl;
	}
	else{
		cout<<"Tie"<<endl;
	}
    return 0;
}