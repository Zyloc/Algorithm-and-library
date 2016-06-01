#include <bits/stdc++.h>
#include<stdio.h>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){

   long long int i,j,count=0,n,k;
    char str[100010];
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
    int n=26;
    int num[26]={0};
    scanf("%s%lld",str,&k);
    for(int j=0;str[j]!='\0';j++)
        num[str[j]-'a']++;
    sort(num,num+n);
    int t=25;
    for(int j=0;j<26;j++)
        if(num[j]!=0){
            printf("%d ",num[j]);
            if(num[t]-num[j]>k){
                count+=(num[t]-num[j]-k);
            }
            t--;
        }
        printf("%lld\n",count);count=0;
        }

}

