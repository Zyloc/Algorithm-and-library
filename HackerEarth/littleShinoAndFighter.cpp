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
#include <queue> 
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
#define MAX 100002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
pair returnPair(pair<lli,lli> p1,pair<lli,lli> p2){
	if (p1.first>p2.first){
		return p1;
	}
	return p2;
}
int main(){
	lli n,q,x,y;
	pair<lli,lli> p1,p2;
	queue<pair<lli,lli> q1,q2;
	lli arr[MAX]={0},ans[MAX]={0};
	cin>>n>>q;
	loop(i,0,n-1){
		cin>>x;
		arr[i] = x;
		q1.push(x);
	}
	while(q1.size()!=1){
		p1 = q1.front();
		q1.pop();
		siz--;
		if (siz!=0){
			p2 = q1.front();
			q1.pop();	
			siz--;
			ans[p1.second]++;
			ans[p2.second]++;
			q1.push(returnPair(p1,p2));
		}
		else{
			q1.push(x);
			break;
		}			
	}	
	loop(i,0,q-1){
		cin>>x;
		cout<<ans[x]<<endl;
	}
    return 0;
}	