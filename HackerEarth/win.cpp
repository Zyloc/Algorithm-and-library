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
#define MAX 1001
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
double dp[MAX][MAX];
void magicBox(){
	for(lli i =0;i<MAX;i++){
		for(lli j=0;j<MAX;j++){
			if (j==0){
				dp[i][j] = double(1);
			}
			else if (i == 0){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = double(i)/double(i+j) + (double(j)/double(i+j))*(double(j-1)/double(i+j-1))*dp[i][j-2];
			}
		}
	}
}
int main(){
	magicBox();
	zyloc(){
		lli a,b;
		cin>>a>>b;
		printf("%.6f\n",dp[a][b]);
	}
	return 0;
}	