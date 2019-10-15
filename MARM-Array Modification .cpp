				/*Saurav Paul*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;

ll op(ll rep , ll a, ll b){
	vector<ll> xyz;
	int cnt = 0;

	while(cnt < 3){
		a = a^b;
		b = b^a ;
		xyz.emplace_back(a) ;
		cnt ++ ;
	}

	return xyz[(rep%3==0?2:rep%3-1)] ;
	
}
	
void solve() {
	ll N , K ;
	scanf("%lld%lld",&N,&K) ;
	vector<ll> v(N) ,ans(N);
    for(auto &x : v) scanf("%lld",&x) ;
	ans = v ;

	for(int i = 0 ; i < min(N,K) ; i++){
		if(i==N-i-1){
			ans[i] = 0;
			continue ;
		}
		ll rep = K / N + ((K%N) >= (i+1) ) ;
		if(i < N-i-1)
			ans[i] = op(rep,v[i],v[N-i-1]);
		else
			ans[i] = op(rep,v[i],v[N-i-1]^v[i]);
		
	}
	for(auto x : ans ) printf("%lld ",x);
	puts("") ;
 }

int main()
{
	int t ;
	scanf("%d",&t);
	for(int i = 0; i < t ; i++ ) solve() ;

    return 0;
}
