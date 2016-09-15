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
bool isPrime(lli n){
	loop(i,2,n-1){
		if (n%i==0){
			//cout<<n<<" "<<i<<endl;
			return false;
		}
	}
	return true;
}
bool nextPrime(lli n,lli m){
	loop(i,n+1,m-1){
		bool flag(false);
		loop(j,2,i-1){
			if (i%j==0){
				flag = true;
				break;
			}
		}
		if (!flag){
			return false;
		}
	}
	return true;
}
int main(){
	lli n,m;
	cin>>n>>m;
	//cout<<isPrime(n)<<endl;
	//cout<<isPrime(m)<<endl;
	if (isPrime(n) and isPrime(m)){
		//debug();
		if (nextPrime(n,m)){
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}	