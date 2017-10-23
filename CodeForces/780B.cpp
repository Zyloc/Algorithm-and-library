/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const double MAX(1e9+1);
double tme(MAX);
vector<double> person,velocity;
lli n;
double x;
bool check(double mid){
	double left(0),right(MAX);
	for(int i=0;i<n;i++){
		double l(person[i]-velocity[i]*mid),r(person[i]+velocity[i]*mid);
		left = max(left,l);
		right = min(right,r);
	}
	return left<=right;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(int i(0);i<n;i++){
		cin>>x;
		person.push_back(x);
	}
	for(int i(0);i<n;i++){
		cin>>x;
		velocity.push_back(x);
	}
	double start(0),end(MAX),ans(MAX);
	for(int i(0);i<200;i++){
		double mid((start+end)/2);
		if(check(mid)){
			ans = min(ans,mid);
			end = mid;
		}
		else{
			start = mid;
		}
	}
	cout<<setprecision(14)<<fixed<<ans<<endl;
	return 0;
}	