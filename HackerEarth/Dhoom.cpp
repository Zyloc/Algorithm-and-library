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
#define MOD 100000
#define PI  3.14159265358979323846
#define MAX 100001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	lli current,required,x,n;	
	cin>>current>>required;
	vi(input);
	cin>>n;
	loop(i,0,n-1){
		cin>>x;
		input.pb(x);
	}
	queue<lli> q;
	lli ans[MAX];
	memset(ans,-1,sizeof(ans));
	ans[current] = 0;
	q.push(current);
	while(!q.empty()){
		lli currentMoney(q.front());
		if (currentMoney == required){
			break;
		}	
		q.pop();
		loop(i,0,n-1){
			lli value((currentMoney*input[i])%MOD);
			if (ans[value]==-1){
				q.push(value);
				ans[value] = ans[currentMoney]+1;
			}
		}
	}
	cout<<ans[required]<<endl;
	return 0;
}	