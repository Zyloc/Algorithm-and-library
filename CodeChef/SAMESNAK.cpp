/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

bool status(pair<lli, lli> A[], pair<lli, lli> B[]);
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		pair<lli, lli>A[2], B[2];
		pair<lli, lli>A1[2], B1[2];
		lli X[2], x[2], Y[2], y[2];
		cin>>X[0]>>Y[0]>>X[1]>>Y[1];
		cin>>x[0]>>y[0]>>x[1]>>y[1];

		A1[0].second 	= A[0].first = X[0];
		A1[0].first		= A[0].second = Y[0];
		A1[1].second 	= A[1].first = X[1];
		A1[1].first 	= A[1].second = Y[1];
		B1[0].second 	= B[0].first = x[0];
		B1[0].first 	= B[0].second = y[0];
		B1[1].second 	= B[1].first = x[1];
		B1[1].first 	= B[1].second = y[1];
		
		if(status(A, B) || status(A1, B1)){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}

bool status(pair<lli, lli> A[], pair<lli, lli> B[]){
	if(A[0].first == A[1].first){
		if(B[0].first == B[1].first && B[0].first == A[0].first){
			lli Y1, Y2, y1, y2;
			if(A[0].second<A[1].second){
				Y1 = A[0].second;
				Y2 = A[1].second;
			} else {
				Y1 = A[1].second;
				Y2 = A[0].second;
			}
			
			y1 = B[0].second;
			y2 = B[1].second;

			if(Y2>=y1 && Y1<=y1) return true;
			if(Y2>=y2 && Y1<=y2) return true;
			return false;
		}
		if(		(B[1].first == A[1].first && B[1].second == A[1].second)
			||	(B[1].first == A[0].first && B[1].second == A[0].second)
			||	(B[0].first == A[1].first && B[0].second == A[1].second)
			||	(B[0].first == A[0].first && B[0].second == A[0].second)){
			if(B[0].second == B[1].second){
				return true;
			}
			return false;
		}
	}
	return false;
}
