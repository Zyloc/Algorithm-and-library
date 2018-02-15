/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+5);
lli bit[MAX];
lli n;
void update(lli index,lli change){
   for(int i(index);i<=n;i+=(i&(-i))){
       bit[i]+=change;
   } 
}

lli query(lli index){
    lli ans(0);
    for(int i(index);i>0;i-=(i&(-i))){
        ans+=bit[i];
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli k,x;
	cin>>n>>k;
	string input;
	cin>>input;
	lli ans(0),cnt(0);
	for(int i(0);i<n;i++){
	    if(input[i] == '1'){
	        cnt++;
	        update(i+1,1);
	    }
	    else{
	    	update(i+1,0);
	        cnt = 0;
	    }
	    ans = max(ans,cnt);
	}
	for(int i(0);i<k;i++){
	    cin>>x;
	    if(x == 1){
	        cout<<ans<<endl;
	    }
	    else{
	        cin>>x;
	        if(input[x-1]!='1'){
	            update(x,1);
	            lli rightAns(0),leftAns(0);
	            lli left(x),right(n);
	            while(left <= right){
	                lli mid((left+right)/2);
	                lli sum(query(mid)-query(x-1));
	                if(sum == mid-x+1){
	                    left = mid +1 ;
	                    rightAns = mid-x+1;
	                }
	                else{
	                    right = mid - 1; 
	                }
	            }
	            left = 1;
	            right = x;
	            while(left <= right){
	                lli mid((left+right)/2);
	                lli sum(query(x)-query(mid-1));
	                if(sum == x-mid+1){
	                    right = mid -1;
	                    leftAns = x-mid+1;
	                }
	                else{
	                    left = mid+1;
	                }
	            }
	            ans = max(ans,leftAns+rightAns-1);
	            input[x-1] = '1';
	        }
	    }
	}
	return 0;
}	