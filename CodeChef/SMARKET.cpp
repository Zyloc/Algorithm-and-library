	/*
	 * Satyam Swarnkar (Zyloc), NIT Silchar
	*/
	#include <bits/stdc++.h>
	#define lli long long int
	using namespace std;
	const int MAX(1e5+2);
	vector<int> preProcessed[MAX];
	int input[MAX],tempArray[MAX],rightToLeft[MAX],leftToRight[MAX];
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		lli t;
		cin>>t;
		while(t--){
			lli n,q,x;
			cin>>n>>q;
			for(int i(0);i<n;i++){
				cin>>input[i];
			}
			tempArray[0] = 1;
			preProcessed[1].push_back(0);
			for(int i(1);i<n;i++){
				if(input[i] == input[i-1]){
					tempArray[i] = 1+tempArray[i-1];
				}
				else{
					tempArray[i] = 1;
				}
				preProcessed[tempArray[i]].push_back(i);
			}
			int last(n-1);
			rightToLeft[n-1] = last;
			for(int i(n-2);i>=0;i--){
				if(input[i]!=input[i+1]){
					last = i;
				}
				rightToLeft[i] = last;
			}
			int first(0);
			leftToRight[0] = first;
			for(int i(1);i<n;i++){
				if(input[i]!=input[i-1]){
					first = i;
				}
				leftToRight[i] = first;
			}
			while(q--){
				int l,r,k,ans(0);
				cin>>l>>r>>k;
				l--;
				r--;
				if(tempArray[l] != 1){
					if(tempArray[min(r,rightToLeft[l])]-tempArray[l-1] >= k){
						ans++;
					}
					l = rightToLeft[l]+1;
				}
				if(tempArray[r]!= 1){
					if(tempArray[r] >= k and leftToRight[r] >= l){
						ans++;
					}
					r = leftToRight[r]-1;
				}
				if(l <= r and preProcessed[k].size() > 0){	
					lli left(0),right(preProcessed[k].size()-1),leftIndex(-1),rightIndex(-1);
					while(left <= right){
						lli mid((left+right)/2);
						if(preProcessed[k][mid] >= l){
							right = mid - 1;
							leftIndex = mid;
						}
						else{
							left = mid + 1;
						}
					}
					if(leftIndex != -1){
						left = leftIndex;
						right = preProcessed[k].size()-1;
						while(left <= right){
							lli mid((left+right)/2);
							if(preProcessed[k][mid] <= r){
								left = mid + 1;
								rightIndex = mid; 
							}
							else{
								right = mid - 1;
							}
						}	
					}
					if(rightIndex!= -1 and leftIndex!= -1 and preProcessed[k][rightIndex] <= r and preProcessed[k][leftIndex] >= l){
						ans+= (rightIndex-leftIndex+1);	
					}
				}
				cout<<ans<<endl;
			}
			for(int i(0);i<MAX;i++){
				preProcessed[i].clear();	
			}
		}
		return 0;
	}	