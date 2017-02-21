/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define zyloc() lli t;cin>>t;while(t--)
#define pb(n) push_back(n)
#define lli long long int 
#define debug() cout<<"######"<<endl 
const lli MAX = 1000002;
const lli MOD = 1000000007;
class FibonacciDiv2{
public:
	int find(int N){
		int first(0),second(1);
		while(second < N){
			int next(first+second);
			first = second;
			second = next;
		}
		return min(N-first,second-N);
	} 
};
