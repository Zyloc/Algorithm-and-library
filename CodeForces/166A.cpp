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

bool cmp(pair<lli,lli> p1,pair<lli,lli> p2){
	if (p1.first > p2.first){
		return true;
	}
	else if (p1.first == p2.first){
		if (p1.second <= p2.second ){
			return true;
		}
	}
	return false;
}
int main(){
	vector<pair<lli,lli> > v;
	lli n,pos,x,y;
	cin>>n>>pos;
	pos--;
	loop(i,0,n-1){
		cin>>x>>y;
		v.pb(mp(x,y));
	}
	sort(v.begin(),v.end(),cmp);
	lli counter=0;
	/*loop(i,0,n-1){
		cout<<v[i].first<<" "<<v[i].second<<endl;
	}
	return 0;*/
	loop(i,pos,n-1){
		if (v[pos].first == v[i].first and v[pos].second == v[i].second){
			counter++;
		}
		else{
			//cout<<v[pos].first;
			break;
		}
	}
	//cout<<counter<<endl;
	pool(i,pos-1,0){
		if (v[pos].first == v[i].first and v[pos].second == v[i].second){
			counter++;
		}
		else{
			break;
		}		
	}
	cout<<counter<<endl;	
    return 0;
}	