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
	lli n;
	lli a,b,c;
	cin>>n;
	lli ans[n+5];
	fill(ans,0);
	if (n%3==0){
		for(lli i=1;i<=n;i=i+3){
			cout<<"?"<<" "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>a;
			cout<<"?"<<" "<<i+1<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>b;
			cout<<"?"<<" "<<i<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>c;
			ans[i] = (a-b+c)/2;
			ans[i+1] = (a+b-c)/2;
			ans[i+2] = (c-a+b)/2;
		}
		cout<<"!"<<" ";
		loop(i,1,n){
			cout<<ans[i]<<" ";
		}
		fflush(stdout);
	}
	else if (n%3==1){
		for(lli i=1;i<=(n/3)*3;i=i+3){
			cout<<"?"<<" "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>a;
			cout<<"?"<<" "<<i+1<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>b;
			cout<<"?"<<" "<<i<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>c;
			ans[i] = (a-b+c)/2;
			ans[i+1] = (a+b-c)/2;
			ans[i+2] = (c-a+b)/2;
		}
		cout<<"?"<<" "<<n-1<<" "<<n<<endl;
		fflush(stdout);
		cin>>a;
		ans[n] = a-ans[n-1];
		cout<<"!"<<" ";
		loop(i,1,n){
			cout<<ans[i]<<" ";
		}
		fflush(stdout);
	}
	else{
		for(lli i=1;i<=(n/3)*3;i=i+3){
			cout<<"?"<<" "<<i<<" "<<i+1<<endl;
			fflush(stdout);
			cin>>a;
			cout<<"?"<<" "<<i+1<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>b;
			cout<<"?"<<" "<<i<<" "<<i+2<<endl;
			fflush(stdout);
			cin>>c;
			ans[i] = (a-b+c)/2;
			ans[i+1] = (a+b-c)/2;
			ans[i+2] = (c-a+b)/2;
		}
		cout<<"?"<<" "<<n-1<<" "<<n-2<<endl;
		fflush(stdout);
		cin>>a;
		ans[n-1] = a-ans[n-2];
		cout<<"?"<<" "<<n-1<<" "<<n<<endl;
		fflush(stdout);
		cin>>a;
		ans[n] = a-ans[n-1];
		cout<<"!"<<" ";
		loop(i,1,n){
			cout<<ans[i]<<" ";
		}
		fflush(stdout);
	} 
	return 0;
}	