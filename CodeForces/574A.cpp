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
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 

int main(){
	lli n,m,x;
	cin>>n>>m;
	lli start=0;
	queue<lli> q1,q2,q3,q4;
	loop(i,1,m){
		if (i<=n*2){
			if (i%2==0){
				q4.push(i);
			}
			else{
				q1.push(i);
			}
		}
		else{
			if (i%2==0){
				q3.push(i);
			}
			else{
				q2.push(i);
			}
		}
	}
	while(!q1.empty() || !q2.empty() || !q3.empty() || !q4.empty()  ){
		if (!q2.empty()){
			cout<<q2.front()<<" ";
			q2.pop();
		}
		if (!q1.empty()){
			cout<<q1.front()<<" ";
			q1.pop();
		}
		if (!q3.empty()){
			cout<<q3.front()<<" ";
			q3.pop();
		}
		if (!q4.empty()){
			cout<<q4.front()<<" ";
			q4.pop();
		}
	}
	return 0;
}