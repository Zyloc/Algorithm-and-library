/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
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
	lli n,x,k,ans(0);
	cin>>n>>k;
	vi(v);
	queue<pair<lli,lli> > q1,q2;
	loop(i,0,n-1){
		cin>>x;
		v.pb(x);
		q1.push(mp(x,i+1));
	}
	loop(i,0,k-1){
		lli maxFound(INT_MIN),indexAns(0),traverse(0),upto(q1.size());
		while(q2.size()!=k and upto>traverse){
			traverse++;
			q2.push(q1.front());
			if(q1.front().first > maxFound){
				indexAns = q1.front().second;
				maxFound = q1.front().first; 
			}
			q1.pop();
		}
		while(!q2.empty()){
			lli element(q2.front().first),index(q2.front().second);
			if(index != indexAns){
				element = max(element-1,(lli)0);
				q1.push(mp(element,index));
			}
			q2.pop();
		}
		cout<<indexAns<<" ";	
	}
	return 0;
}	