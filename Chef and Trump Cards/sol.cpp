/**
 *    author        : Saurav Paul
 *    created       : September 08, 2020 9:40 PM
 *    Problem Name  : Chef and Trump Cards
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/CRDGAME2
 *    @genarated by : ai-virtual-assistant
**/
#include<bits/stdc++.h>
using namespace std;
using ll = long long int ;
const ll MOD = 1e9 + 7 ;
unordered_map<int,int> cnt ;
// nCr
const ll SZ = 1e5 + 10;
vector<ll> fact(SZ+1) ;
ll mod_inverse[SZ+5];
ll BigMod(ll num , ll power, ll mod){
	if(power == 0 ){
		return 1 ;
	}
	ll x = 1 ;
	if(power&1){
		x = num ;
	}
	ll y = BigMod(num,power/2,mod) ;
	y = ( y%mod * y%mod )%mod ;
	return (y%mod * x%mod)%mod ;
}
ll BigModInverse(ll num , ll mod ){
	return BigMod(num,mod-2,mod) ;
}
void precomputation(){
    fact[0] = mod_inverse[0]= 1;
    for(int i = 1 ; i < SZ ; i++){
        fact[i] = (fact[i-1] * i) % MOD ;
        ll x=BigModInverse(fact[i], MOD)%MOD;
        mod_inverse[i]=x;
    }
}
ll nCr(ll num,ll r){
    ll temp =((fact[num]*mod_inverse[r])%MOD)*mod_inverse[num-r];
    temp%=MOD;
    return temp ;
}
// nCr end
class TC{
    public :
    void solve(){
        ll N ;
        cin >> N ;
        ll total = bigmod(2,N) , bad_dibo = 0 ;
        int mx = 0 ;
        cnt.clear() ;
        for(int i = 0 ; i < N ; i++){
            int x;
            cin >> x;
            cnt[x] ++ ;
            mx = max(mx,x) ;
        }
        bool bad_dite_hobe = true ;
        ll ase = cnt[mx] ;
        if(ase&1) bad_dite_hobe = false ;
        else{
            ll baki = N - ase ;
            bad_dibo = bigmod(2,baki) ;
            ll keep = bigmod(2, ase);
            keep-=nCr(ase, ase/2);
            if(keep < 0) keep += MOD ;
            total=((keep%MOD)*(bad_dibo%MOD))%MOD;
        }
        cout << total << endl ;
    }
    ll bigmod(ll num , ll power){
        if(power == 0 ){
            return 1 ;
        }
        ll x = 1 ;
        if(power&1){
            x = num ;
        }
        ll y = bigmod(num,power/2) ;
        y = ( y%MOD * y%MOD )%MOD ;
        return (y%MOD * x%MOD)%MOD ;
    }
};
int main(){
    ios_base::sync_with_stdio(false);

    precomputation() ;

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.solve() ;
    }
    return 0 ;
}
