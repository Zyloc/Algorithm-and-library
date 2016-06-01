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
 
int main(){
	zyloc(){
		lli n;
		cin>>n;
		lli days=2,x=1,temp=n;
		n-=2;
		while(n>0){
			if (n>=2*(x+1)){
				days+=2;
				x+=1;
				n=n-2*x;
			}
			else if(n>=(x+1)){
				x+=1;
				days+=1;
				n-=x;
			}
			else if(n>=2*x){
				days+=2;
				n=n-2*x;
			}
			else if(n>=x){
				days+=1;
				n-=x;
			}
			else if(n>=2*(x-1)){
				x-=1;
				days+=2;
				n=n-x;
			}	
			else{
				days+=1;
				x-=1;
				n-=x;
			}
		}
		if (temp!=1){
			cout<<days<<endl;
		}
		else{
			cout<<"1"<<endl;
		}
	}	
    return 0;
}
Language: C++