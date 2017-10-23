	/*
	 * Satyam Swarnkar (Zyloc), NIT Silchar
	*/
	#include <bits/stdc++.h>
	#define lli long long int
	using namespace std;
	const int MAX(5e5+5);
	lli BIT[MAX],freq[MAX];
	lli n,q,x;
	void update(int index,int x){
	    for(int i(index);i<MAX;i+=(i&-i)){
	        BIT[i] += x; 
	    }
	}
	lli query(int index){
	    lli ans(0);
	    for(int i(index);i>0;i-=(i&-i)){
	        ans+=BIT[i];
	    }
	    return ans;
	}
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		vector<lli> input;
		lli sum(0);
		cin>>n>>q;
		for(int i(0);i<n;i++){
		    cin>>x;
		    sum+=x;
		    freq[x]++;
		    input.push_back(x);
		}
		for(int i(1);i<MAX;i++){
		    update(i,freq[i]);
		}
		while(q--){
		    lli queryType,toChange;
		    cin>>queryType;
		    if(queryType == 1){
		        cin>>x>>toChange;
		        sum+=(toChange-input[x-1]);
		        update(input[x-1],-1);
		        freq[input[x-1]]--;
		        freq[toChange]++;
		        update(toChange,1);
		        input[x-1] = toChange;
		    }
		    else{
		    	cin>>x;
		    	if(x == 1){
		    		cout<<sum<<endl;
		    	}
		    	else{
		    		lli ans(0),counter(0),lastMultiple(0);
			        for(int i(x);i<MAX;i+=x){
			            ans+= ((query(i-1)-query(lastMultiple-1))*counter);
			            lastMultiple = i;
			            counter++;

			        }
			        cout<<ans<<endl;	
		    	}
		    }
		}
		return 0;
	}	