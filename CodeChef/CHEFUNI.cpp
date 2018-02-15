/*
 * Satyam Swarnkar(Zyloc) , NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli x,y,z,a,b,c;
lli solve2(lli p,lli q,lli r,lli costSoFar){
	lli ans(costSoFar);
	if(x == p and y == q and z == r){
		return costSoFar;
	}
	if(p!=x and q!=y and r!= z){
		lli n(min((x-p)/2,min((y-q)/2,(z-r)/2)));
		ans += n * min(6*a,min(3*b,min(2*c,min(a+b+c,min(2*(a+b),3*a+c)))));
		p+=n*2;
		q+=n*2;
		r+=n*2;
		lli temp(INT_MAX);
		if(x-p == 1 and y-q >= 1 and z-r>=1){
			return min(solve2(p+1,q,r,ans+a),min(solve2(p+1,q+1,r,b+ans),min(solve2(p+1,q,r+1,b+ans),solve2(p+1,q+1,r+1,ans+c))));
		}
		else if(x-p >=1 and y-q == 1 and z-r >=1){
			return min(solve2(p,q+1,r,ans+a),min(solve2(p+1,q+1,r,b+ans),min(solve2(p,q+1,r+1,b+ans),solve2(p+1,q+1,r+1,ans+c))));
		}
		else if(x-p >= 1 and y-q >= 1 and z-r == 1){
			return min(solve2(p,q,r+1,ans+a),min(solve2(p,q+1,r+1,b+ans),min(solve2(p+1,q,r+1,b+ans),solve2(p+1,q+1,r+1,ans+c))));
		}
		else{
			return solve2(p,q,r,ans);
		}
	}
	if(x!=p and y!=q and z==r){
		return min(solve2(x,q,r,ans+a*(x-p)),min(solve2(p,y,r,ans+a*(y-q)),solve2(p+min(x-p,y-q),q+min(x-p,y-q),z,ans+b*min(x-p,y-q))));
	}
	if(x!=p and y==p and z!=r){
		return min(solve2(x,y,r,ans+a*(x-p)),min(solve2(p,y,z,ans+a*(z-r)),solve2(p+min(x-p,z-r),y,r+min(x-p,z-r),ans+b*min(x-p,z-r))));
	}
	if(x==p and y!=q and z!=r){
		return min(solve2(p,y,r,ans+a*(y-q)),min(solve2(p,q,z,ans+a*(z-r)),solve2(x,q+min(y-q,z-r),r+min(y-q,z-r),ans+b*min(y-q,z-r))));	
	}
	
	if(x!=p and y==q and z==r){
		return solve2(x,y,z,(x-p)*a+ans);
	}
	if(x==p and y!=q and z==r){
		return solve2(x,y,z,(y-q)*a+ans);
	}
	if(x==p and y==q and z!=r){
		return solve2(x,y,z,(z-r)*a+ans);
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>x>>y>>z>>a>>b>>c;
		cout<<solve2(0,0,0,0)<<endl;
	}
	return 0;
}
