
/**
 *    author        : Saurav Paul 
 *    created       : September 13, 2020 11:26 PM
 *    Problem Name  : Divide Candies
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/EQDIV
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

#define bug()				  debug() <<
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef PAUL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#ifdef ONLINE_JUDGE
#define cerr if (false) cerr
#endif


class TC{

    public :

    void Do(){
        /* cout << "{" << endl; */

        /* N = 64 ; */
        /* cin >> N ; */

        for(ll i =1 ; i <=5  ; i++){
            solve(i) ;
        }
        /* cout << " \"0\""<<endl<<" }" << endl ; */ 
    }

    void solve(ll N){

        map<ll,ll> rem ;
        ll sum = 0 ;
        vector<ll> v ;
        for(ll i = 1 ; i <= N ; i++){
            ll num = i * i * i * i ;
            v.push_back(num) ;
            sum += num ;
            rem[num] = i ;
        }

        ll half = sum / 2 ;

        /* bug() dbg(sum) dbg(half) ; */
        vector<ll> dp(sum + 1) ;
        vector<pair<int,int>> info(sum+1) ;

        dp[0] = 1;

        info[0] = {-1,-1} ;

        ll mx = 0 ;
        vector<ll> points ;
        points.push_back(0) ;


        for(auto num : v){
            ll st = half ;

            for(ll i = points.size() - 1 ; i >= 0 ; i--){
                if(points[i] + num <= half){

                      ll tar = points[i] + num ;

                      dp[tar] = 1 ;
                      info[tar] = {num,tar} ;

                      if(i <= half) mx = max(mx,i) ;
                      points.push_back(tar) ;
                }
            }

            sort(points.begin(), points.end()) ;

            /* for(ll i = half ; i - num >= 0 ; i --){ */
            /*     if (dp[i-num]){ */
            /*         dp[i] = 1 ; */
            /*         info[i] = {num,i-num} ; */

            /*         if(i <= half) mx = max(mx,i) ; */
            /*     } */
            /* } */
        }


        /* for(auto num : v){ */
        /*     for(ll i = half ; i - num >= 0 ; i --){ */
        /*         if (dp[i-num]){ */
        /*             dp[i] = 1 ; */
        /*             info[i] = {num,i-num} ; */

        /*             if(i <= half) mx = max(mx,i) ; */
        /*         } */
        /*     } */
        /* } */


        bug() dbg(v) ;
        /* bug() dbg(dp) ; */

        /* for(int i = 0 ; i <= half ; i++){ */
        /*     if(dp[i]){ */
        /*         mx = i ; */
        /*     } */
        /* } */

        /* cout << mx << endl ; */
        bug() dbg(mx) ;

        vector<ll> nisi ;


        for(ll i = mx ; i ; ){
            ll temp = info[i].first ;
            nisi.push_back(temp) ;
            i -= temp ;
        }

        bug() dbg(nisi) ;
        string ans = string(N,'0') ;

        ll a = 0 ;

        for(auto x : nisi){
            ll t = rem[x] - 1 ;
            ans[t] = '1' ;

            a += x ;
        }

        ll dif = sum - a;

        dif =  abs(dif - a) ;

        bug() dbg(dif) ;
        cout <<" \""<< ans<<"\" ,"<< endl ;

    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.Do() ;
    }

    return 0 ;
}
