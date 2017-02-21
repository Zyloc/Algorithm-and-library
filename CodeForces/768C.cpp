	/*
	 * Satyam Swarnkar (Zyloc), NIT Silchar
	*/
	#include <bits/stdc++.h>
	#define lli long long int
	using namespace std;
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		lli n,k,x,y,cycle(0),lcm(1);
		cin>>n>>k>>x;
		vector<lli> v;
		for(int i=0;i<n;i++){
			cin>>y;
			v.push_back(y);
			set<lli> st;
			st.insert(y);
			while(true){
				lli prevsize(st.size());
				y = y^x;
				st.insert(y);
				if(st.size() == prevsize){
					cycle = max(cycle,(lli)st.size());
					break;
				}
			}
			lcm = lcm*cycle/__gcd(lcm,cycle);
		}
		cout<<lcm<<endl;
		k--;
		k = k%lcm;
		for(int i=0;i<=k;i++){
			sort(v.begin(),v.end());
			for(int j=0;j<n;j+=2){
				v[j] = v[j]^x;	
			}
		}
		sort(v.begin(),v.end());
		cout<<v[n-1]<<" "<<v[0]<<endl;
		return 0;
	}