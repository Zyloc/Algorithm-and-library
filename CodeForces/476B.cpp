/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
#define loop(i,start,end) for (lli i=start;i<=end;i++)
#define pool(i,start,end) for(lli i=start;i>=end;i--)
#define zyloc() lli t;cin>>t;while(t--)
#define vi(v) vector <long long  int> v;
#define pb(n) push_back(n)
#define mp(a,b) make_pair(a,b)
#define fill(a,value) memset(a,value,sizeof(a)) 
#define MOD 1000000007
#define PI  3.14159265358979323846
#define MAX 1000002
#define vpi(v) vector <pair <long long int, long long int> > v
#define lli long long int 
#define debug() cout<<"######"<<endl 
lli combination( lli n, lli k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    lli result = n;
    for( lli i = 2; i <= k; ++i ) {
        result = ((result)*(n-i+1));
        result /= i;
    }
    return result;
}
int main(){
	lli actualPos(0),relativePos(0),totalMoves(0),countQuestion(0);
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	loop(i,0,s1.length()-1){
		if (s1[i]=='-'){
			actualPos--;
		}
		else{
			actualPos++;
		}
		if (s2[i]=='-'){
			relativePos--;
		}
		else if (s2[i]=='+'){
			relativePos++;
		}
		else{
			countQuestion++;
		}
	}
	totalMoves = abs(relativePos-actualPos);
	lli noOfPositive(totalMoves+(countQuestion-totalMoves)/2),noOfNegative((countQuestion-totalMoves)/2+(countQuestion-totalMoves)%2);
	printf("%.12f\n",(combination(countQuestion,noOfPositive)*1.0)/pow(2,countQuestion));
	return 0;
}	