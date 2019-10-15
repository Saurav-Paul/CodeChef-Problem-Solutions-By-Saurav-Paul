				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;

void solve() {
	long long int N , M , Q ;
	scanf("%lld%lld%lld",&N,&M,&Q) ;
	
	vector<long long int> X(N+1) , Y(M+1) ;
	
	for(int i = 0 ; i < Q ; i++){
		long long int x , y ;
		scanf("%lld%lld",&x,&y);
		X[x] ++ ;
		Y[y] ++;
	}
	long long int cnt = 0;
	long long int xodd = 0 , xeven = 0;
	long long int yodd = 0 , yeven = 0;
	
	for(int i = 1 ; i <= N ; i++){
		if(X[i]&1) xodd ++;
		else xeven ++;
	}
	for(int i = 1 ; i <= M ; i++){
		if(Y[i]&1) yodd ++ ;
		else yeven ++;
	}
	cnt = xeven * yodd + yeven * xodd ;
	printf("%lld\n",cnt) ;
	
}

int main()
{
	int t; scanf("%d",&t);
	
	for(int i =0; i < t ; i++) solve() ;
	
    return 0;
}
