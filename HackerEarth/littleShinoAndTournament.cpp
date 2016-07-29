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
#define MAX 100003
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
int main(){
	pair <lli,lli> strength[MAX];
	lli n,q,x;
	cin>>n>>q;
	strength[0].first = 0;
	strength[0].second = 0;
	loop(i,1,n){
		cin>>x;
		strength[i].first = x;
		strength[i].second = 0;
	}
	lli level(1),times=log2(n)+1,counter(1),lastIndex(0);
	
	loop(j,1,times){
		counter = 1;
		loop(i,1,n){
			if (strength[i].second == j-1){
				if (counter%2 == 0){
					counter = 1;
					if (strength[lastIndex].first > strength[i].first ){
						strength[lastIndex].second++;
					}
					else{
						strength[i].second++;	
					}
				}
				else{	
					lastIndex = i; 
					counter++;
				}
			}
				
		}	
	}

	loop(i,1,q){
		cin>>x;
		cout<<strength[x].second+1<<endl;
	}
    return 0;
}	