/*
 * Satyam Swarnkar (Zyloc), NIT Silchar
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAX = 51;
int dp[4][4][MAX][MAX][MAX];
int A(0),B(1),C(2),D(3);
int magicBox(int start,int last,int countA,int countB,int countC){
	if(countA == 0 and countB == 0 and countC == 0){
		return last!=start;
	}
	int &result = dp[start][last][countA][countB][countC];
	if(result!=-1){
		return result;
	}
	int sum(0);
	if(start == D){
		if(countA)
			sum = (sum+magicBox(A,A,countA-1,countB,countC))%MOD;
		if(countB)
			sum = (sum+magicBox(B,B,countA,countB-1,countC))%MOD;
		if(countC)
			sum = (sum+magicBox(C,C,countA,countB,countC-1))%MOD;
	}
    else{
    	if(last == A){
			if(countB)
				sum = (sum+magicBox(start,B,countA,countB-1,countC))%MOD;
			if(countC)
				sum = (sum+magicBox(start,C,countA,countB,countC-1))%MOD;
        }
        if(last == B){
            if(countA)
            	sum = (sum+magicBox(start,A,countA-1,countB,countC))%MOD;
            if(countC)
            	sum = (sum+magicBox(start,C,countA,countB,countC-1))%MOD;
        }
        if(last == C){
            if(countA)
            	sum = (sum+magicBox(start,A,countA-1,countB,countC))%MOD;
            if(countB)
            sum = (sum+magicBox(start,B,countA,countB-1,countC))%MOD;
        }
    }
	return result=sum;
}
class ColorfulCupcakesDivTwo{
public:
	int countArrangements(string C){
		int countA(count(C.begin(),C.end(),'A'));
		int countB(count(C.begin(),C.end(),'B'));
		int countC(count(C.begin(),C.end(),'C'));
		memset(dp,-1,sizeof dp);
		return magicBox(D,D,countA,countB,countC)%MOD;
	}
};
