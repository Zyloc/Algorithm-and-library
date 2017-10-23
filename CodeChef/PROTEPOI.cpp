/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
lli n,k,m;
struct coOrdinates{
	lli start,end;
};
bool cmp(coOrdinates first,coOrdinates second){
	if(first.start > first.end){
		return true;
	}
	else if(first.start == first.end){
		return first.start >= first.end;
	}
	return false;
}
lli solve(vector<coOrdinates> &horizontal,vector<coOrdinates> &vertical){
	set<lli> takenPoints;
	lli horizontalIndex(0),verticalIndex(0);
	lli start(horizontal[horizontalIndex].start),end((n-k)/2+1);
	bool flag(false);
	while(horizontalIndex < horizontal.size() and start <= (n-k)/2+1+k){
		takenPoints.insert(horizontal[horizontalIndex].start);
		end = horizontal[horizontalIndex].end;
		if(end >= (n-k)/2+k+1){
			break;
		}
		lli maxEnding(end);
		while(horizontalIndex < horizontal.size() and horizontal[horizontalIndex].start <= end){
			maxEnding = max(maxEnding,horizontal[horizontalIndex].end);
			horizontalIndex++;
		}
		end = maxEnding;
		if(maxEnding == end){
			flag = true;
			break;
		}
	}
	if(horizontal.size() > 0 and end < (n-k)/2+1+k){
		flag = true;
	}
	start = vertical[verticalIndex].start;
	end = (n-k)/2+1;
	if(flag){
		return 1e18;
	}
	return takenPoints.size();
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		cin>>n>>k>>m;
		coOrdinates temp;
		lli x1,y1,x2,y2;
		vector<coOrdinates> horizontal,vertical;
		for(int i(0);i<m;i++){
			cin>>x1>>y1>>x2>>y2;
			swap(x1,y1);
			swap(x2,y2);
			if(x1 == x2){
				temp.start = min(y1,y2);
				temp.end = max(y1,y2)+1;
				vertical.push_back(temp);
				temp.start = x1;
				temp.end = x1+1;
				horizontal.push_back(temp);
			}
			if(y1 == y2){
				temp.start = min(x1,x2);
				temp.end = max(x1,x2)+1;
				horizontal.push_back(temp);
				temp.start = y1;
				temp.end = y1+1;
				vertical.push_back(temp);
			}
		}
		sort(horizontal.begin(),horizontal.end(),cmp);
		sort(vertical.begin(),vertical.end(),cmp);
		for(auto x:horizontal){
			cout<<x.start<<" "<<x.end<<endl;
		}
		lli ans1(solve(horizontal,vertical)),ans2(solve(horizontal,vertical));
		if(ans1 != 1e18 and ans2 != 1e18){
			cout<<min(ans1,ans2)<<endl;
		}
		else {
			if(min(ans1,ans2) == 1e18){
				cout<<-1<<endl;
			}
			else{
				cout<<min(ans1,ans2)<<endl;
			}
		}
	}
	return 0;
}
