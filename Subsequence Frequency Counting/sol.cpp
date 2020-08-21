/**
 *    author        : Saurav Paul 
 *    created       : August 10, 2020 12:04 PM
 *    Problem Name  : Subsequence Frequency Counting
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/SUBSFREQ
 *    @genarated by : ai-virtual-assistant
**/
#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;
int n ;
const ll SZ = 5e5 + 10;
const ll MOD = 1e9 + 7 ;
vector<ll> fact(SZ+1) ;
ll mmi[SZ+5];

void mul(ll &x, ll y){
    x = (x * y) % MOD ;
}
void add(ll &x, ll y){
    x = (x + y) % MOD ;
}
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
    fact[0] = mmi[0]= 1;
    for(int i = 1 ; i < SZ ; i++){
        fact[i] = (fact[i-1] * i) % MOD ;
        ll x=BigModInverse(fact[i], MOD)%MOD;
        mmi[i]=x;
    }
}
ll nCr(ll num,ll r){
    ll ans =((fact[num]*mmi[r])%MOD)*mmi[num-r];
    ans%=MOD;
    return ans ;
}

// building a segment tree 
class Value{
    public :
	vector<ll> sums ;
	void initial_build(int limit){
	    sums.emplace_back(1) ;
	    ll prev = 1;
	    for(int i = 1 ; i <= limit ; i++){
		ll temp = nCr(limit , i) ;
		add(temp,prev) ;
		prev = temp ;
		sums.emplace_back(temp) ;
	    }
	}
	ll ans(int limit){
	    int sz = sums.size() ;
	    return sums[min(sz-1,limit)] ;
	}
	void update(vector<ll> &x , vector<ll> &y){
	    ll sx = x.size() ;
	    ll sy = y.size() ;
	    ll smx = max(sx,sy) ;
	    sums = vector<ll> (smx) ;
	    for(ll i = 0 ; i < smx ; i++){
		ll temp = 1 ;
		mul(temp,x[min(i,sx-1)]) ;
		mul(temp,y[min(i,sy-1)]) ;
		sums[i] = temp ;
	    }
	}
	void print(){
	    for(auto x : sums){
		cout << x << " " ;
	    }
	    cout << endl ;
	}
} ;
vector<Value> tree ;
ll treelim = 0 ;
vector<pair<ll,ll>> v;
void build_segment_tree(int node, int st , int sp) {
    if(st == sp){
	// building base
	tree[node].initial_build(v[st].second) ;
	return ;
    }
    ll lft = (node * 2) ;
    ll rght = lft + 1 ;
    ll mid =  (st + sp) / 2 ;
    build_segment_tree(lft,st,mid) ;
    build_segment_tree(rght,mid+1,sp) ;
    tree[node].update(tree[lft].sums,tree[rght].sums) ;

}
ll  query(int node , int a ,int b,int st , int sp,int lim){
    if(a > sp || b < st)
	    return 1LL;
    if(st>=a && sp<=b){
	    return tree[node].ans(lim);
    }
    ll lft = 2 * node;
    ll rght = 2 * node + 1;
    ll mid = (st+sp)/2;
    ll ans = query(lft,a,b,st,mid,lim);
    ll ans2 = query(rght,a,b,mid+1,sp,lim);
    mul(ans,ans2) ;
    return ans;

}
// end building segment tree

void solve(){
    scanf("%lld",&n) ;
    v = vector<pair<ll,ll>> ();
    map<int,int> rem; 
    for(int i = 0 ; i < n ; i++){
	int x ;
	scanf("%lld",&x) ;
	rem[x] ++ ;
    }
    for(auto x : rem){
	v.push_back(make_pair(x.first,x.second)) ;
    }
    treelim = v.size() ;
    tree = vector<Value> (4*treelim + 1) ;
    build_segment_tree(1,0,treelim-1) ;
    vector<ll> new_answer(n+1) ;
    for(int i = 0 ; i < treelim ; i ++){
	ll sumOfproduct = 0;
	ll num_lim = v[i].second ;
	for(int j = 1 ; j <= num_lim ; j ++){
	    ll product = 1;
	    ll temp = 1;
	    product = nCr(num_lim,j) ;
	    if(j > 1 && i > 0){
		temp = query(1,0,i-1,0,treelim-1,j-1) ;	
		mul(product,temp) ;
	    }
	    if(i < treelim -1){
		temp = query(1,i+1,treelim-1,0,treelim-1,j) ;	
		mul(product,temp) ;
	    }
	    add(sumOfproduct,product) ;
	}
	new_answer[v[i].first] = sumOfproduct ;
    }
    for(int i = 1 ; i <= n ; i++){
	cout << new_answer[i] << (i < n?" ":"\n") ;
    }
}
int main(){
    precomputation() ;
    int testcase ;
    scanf("%d",&testcase) ;
    for(int i = 1 ; i <= testcase ; i ++){
        solve();
    }
    return 0 ;
}
