/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli n,k;
	double ans1(0),ans2(0);
	cin>>n>>k;
	priority_queue<double> pq;
	double x;
	for(int i=0;i<n;i++){
		cin>>x;
		ans1+=x;
		pq.push(x);
	}
	lli count(0);
	while(count!=k){
		lli top(ceil(pq.top()/(3*1.0)));
		pq.pop();
		pq.push(top);
		count++;
	}
	while(!pq.empty()){
		ans2+=pq.top();
		pq.pop();
	}
	printf("%.6f %.6f\n", ans1/double(n),ans2/double(n));
	return 0;
}