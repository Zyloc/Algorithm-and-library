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
int main(){
	zyloc(){
		vi(v);
		lli n,x,cntOdd(0),indexFirst(0),indexLast(0),flag=0;
		cin>>n;
		loop(i,1,n){
			cin>>x;
			if (x%2!=0){
				cntOdd++;
			}
			if (cntOdd==1 and flag==0){
				indexFirst=i;
				flag=1;
			}
			if (x%2 != 0){
				indexLast = i;
			}
		}
		indexLast = n - indexLast +1;
		//cout<<indexLast<<" "<<indexFirst<<endl;
		if (cntOdd%2==0){
			cout<<n<<endl;
		}
		else if(indexLast==0){
			cout<<max(n-indexFirst,n-indexFirst)<<endl;
		}
		else{
			cout<<max(n-indexFirst,n-indexLast)<<endl;
		}
	}
    return 0;
}	