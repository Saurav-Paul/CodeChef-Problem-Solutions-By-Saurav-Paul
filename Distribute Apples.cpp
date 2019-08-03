#include<bits/stdc++.h>
using namespace std;

void solve(){
	
	long long int n , k;
	scanf("%lld%lld",&n,&k);
	
	if(k==1 or (n/k)%k==0)
		puts("NO");
	else
		puts("YES");
	
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--)
		solve();
	
	return 0;
}
