/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
#define lli long long int
using namespace std;

struct query{
	int l,r,index;
};
const int MAX = 2e6+1;
int n,q,BLOCK_SIZE;
lli answer;
vector<query> v;
vector<lli> input;
lli freq[MAX];
bool cmp(query lhs,query rhs){
	if(lhs.l/BLOCK_SIZE != rhs.l/BLOCK_SIZE){
		return lhs.l < rhs.l;
	}
	return lhs.r < rhs.r;
}
void add(lli x){
	answer+= x * 1ll * (freq[x] << 1 | 1);
	freq[x]++;
}
void remove(lli x){
	answer-= x * 1ll * ((freq[x] - 1) << 1 | 1);
	freq[x]--;
}
int main(){
	int x,l,r;
	//cin>>n>>q;
	scanf("%d %d",&n,&q);
	BLOCK_SIZE = sqrt(n);
	for(int i=0;i<n;i++){
		cin>>x;
		input.push_back((lli)x);
	}
	query temp;
	for(int i=0;i<q;i++){
		scanf("%d %d",&l,&r);
		l--;
		r--;
		temp.l = l;
		temp.r = r;
		temp.index = i;
		v.push_back(temp);
	}
	sort(v.begin(),v.end(),cmp);
	lli left(0),right(-1);
	lli ans[q];
	for(int i=0;i<q;i++){
		if( i == 0 or v[i].l/BLOCK_SIZE != v[i-1].l/BLOCK_SIZE){
			memset(freq,0,sizeof freq);
			answer = 0;
			for(int j=v[i].l;j<=v[i].r;j++){
				add(input[j]);
			}
			left = v[i].l;
			right = v[i].r;
		}
		else{
			int processingLeft(v[i].l),processingRight(v[i].r);
			while(right < processingRight){
				right++;
				add(input[right]);
			}
			while(right > processingRight){
				remove(input[right]);
				right--;
			}
			while(left < processingLeft){
				remove(input[left]);
				left++;
			}
			while(left > processingLeft){
				left--;
				add(input[left]);
			}	
		}
		ans[v[i].index] = answer;
		
	}
	for(int i=0;i<q;i++){
		printf("%I64d\n",ans[i]);
	}
	return 0;
}