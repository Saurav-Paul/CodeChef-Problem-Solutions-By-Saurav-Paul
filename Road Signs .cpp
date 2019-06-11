				/*Saurav Paul*/
#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int

const int mod = 1e9 +7;

ll BigMod(ll N, ll k){
	if(k==0)
		return 1;
	if(k%2==0){
		ll ret = BigMod(N,k/2);
		return ((ret%mod)*(ret%mod))%mod;
	}
	else
		return ((N%mod)*(BigMod(N,k-1)%mod))%mod;
}
void solve(){
	ll k;
	scanf("%lld",&k);
	k--;
	
	ll ans = BigMod(2,k);
	
	printf("%lld\n",(ans*10)%mod);
	
	
}

int main()
{
	
	int n;
	scanf("%d",&n);
	while(n--)
		solve();
		
    return 0;
}
