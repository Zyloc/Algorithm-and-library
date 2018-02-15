/*
 * 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
	    lli n,k;
	    cin>>n>>k;
	    if(k == 1){
	        lli left(0),right(1e9),ans;
	        while(left <= right){
	            lli mid(left+(right-left)/2);
	            lli first((mid*mid));
	            lli reminder(first%2);
	            first /= 2;
	            lli second(mid);
	            reminder += second%2;
	            second /= 2;
	            first += reminder/2;
	            if(first <= n- second){
	                first += second;
	                if(first <= n){
    	                 ans = mid;
    	                 left = mid +1 ;
	                }
	                else{
	                    right = mid - 1;
	                }
	            }
	            else{
	                right = mid - 1;
	            }
	        }
	        cout<<ans<<endl;
	    }
	    else if(k == 3){
	        lli left(0),right(1e7),ans;
	        while(left <= right){
	            lli mid(left+(right-left)/2);
	            lli first((mid*mid*mid*mid));
	            lli reminder(first%4);
	            first = first/4;
	            lli second((mid*mid*mid*2));
	            reminder+=second%4;
	            second/=4;
	            lli third((mid*mid));
	            reminder += third%4;
	            third /= 4;
	            first += reminder/4;
	            if(first <= n-second){
	                first+= second;
	                if(first <= n-third){
	                    first += third;
	                }
	                if(first <= n){
	                    ans = mid;
	                    left = mid + 1;
	                }
	                else{
	                    right = mid-1;
	                }
	            }
	            else{
	                    right = mid-1;
	                }
	        }
	        cout<<ans<<endl;
	    }
	    else{
	        lli left(0),right(1e7),ans(0);
	        while(left <= right){
	            lli mid(left+(right-left)/2);
	            lli first((mid*mid*mid*2));
	            lli reminder(first%6);
	            first = first/6;
	            lli second((mid*mid*3));
	            reminder += second%6;
	            second /= 6; 
	            lli third(mid);
	            reminder += third%6;
	            third/=6;
	            first += reminder/6; 
	            if(first <= n-second){
	                first += second;
	                if(first <= n-third){
	                    first+=third;
	                }
	                if(first <= n){
	                    ans = mid;
	                    left = mid + 1; 
	                }
	                else{
	                    right = mid - 1;
	                }
	            }
	            else{
	                right = mid - 1;
	            }
	        }
	        cout<<ans<<endl;
	    }
	}
	return 0;
}
