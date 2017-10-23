#include <bits/stdc++.h>
#define lli long long int
using namespace std;
//you may add more methods here
bool visited[100];
lli lcm(lli a,lli b){
	return (a*b)/__gcd(a,b);
}
vector<lli> input;
lli magicBox(lli position,lli startPosition,lli length){
	if(visited[position] and position == startPosition){
		return length;
	}
	visited[position] = true;
	return magicBox(input[position-1],startPosition,length+1);
}
int danceTime(int N, int P[100]) {
	lli ans(1);
	input.clear();
	for(int i(0);i<N;i++){
		input.push_back(P[i]);
	}
	for(int i(0);i<N;i++){
		memset(visited,false,sizeof visited);
		lli dummy(magicBox(P[i],P[i],0));
		ans = lcm(ans,dummy);
	}
	return ans;
}

int main() {
    int T;
    int N, P[100];
    int i;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for(i=0;i<N;i++) scanf("%d",&P[i]);
        printf("%d\n",danceTime(N,P));
    }
    return 0;
}
