/*
 * Richie who's not Rich 
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
const int MAX(1e5+10);
lli bit[MAX],n;
void update(lli index,lli change){
    for(int i(index);i<=n;i+=(i&-i)){
        bit[i]-=change;
    }
}
lli query(lli index){
    lli ans(0);
    for(int i(index);i>0;i-=(i&-i)){
        ans+=bit[index];
    }
    return ans;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli x;
	cin>>n;
	vector<lli> input;
	input.push_back(-1e18);
	for(int i(0);i<n;i++){
	    cin>>x;
	    input.push_back(x);
	}
	lli q;
	cin>>q;
	while(q--){
	    cin>>x;
	    if(x == 1){
	        cin>>x;
	        lli left(1),right(n),rightAns(-1);
	        while(left <= right){
	        	lli mid((left+right)/2);
	        	if(query(mid+1)+input[mid] > x){
	        		right = mid - 1;
	        	}
	        	else{
	        		rightAns = mid;
	        		left = mid + 1;
	        	}
	        }
	        left = 1;
	        right = n;
	        lli leftAns(-1);
	        while(left <= right){
	        	lli mid((left+right)/2);
	        	if(query(mid+1)+input[mid] < 1){
	        		left = mid +1;
	        	}
	        	else{
	        		leftAns = mid;
	        		right = mid -1;
	        	}
	        }
	        if(leftAns!=-1 and rightAns!=-1){
	        	if(leftAns!=1)
	        		update(+1,-1);
	        	update(n-rightAns+1,1);
	        }
	    }
	    else{
	        cin>>x;
	        lli left(1),right(n),check(false);
	        while(left <= right){
	            //cout<<left<<" "<<right<<endl;
	            lli mid((left+right)/2);
	            if(input[mid]+query(n-mid+1) == x){
	               	check = true;
	                break;
	            }
	            else if(input[mid]+query(n-mid+1) < x){
	                left = mid + 1;
	            }
	            else{
	                right = mid - 1;
	            }
	        }
	        if(check){
	            cout<<"yes"<<endl;
	        }
	        else{
	            cout<<"no"<<endl;
	        }
	    }
	}
	return 0;
}
