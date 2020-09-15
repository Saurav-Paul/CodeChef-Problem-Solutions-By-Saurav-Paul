
/**
 *    author        : Saurav Paul 
 *    created       : September 09, 2020 7:56 PM
 *    Problem Name  : Divide Candies
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/EQDIV
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

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



using ll = long long int ;
int K ;
class brute{

    ll N ;
    vector<ll> v ;

    void cal_subarray(vector<ll> &a, map<int,string> &rem , ll st, ll base){

        bug() dbg(st) dbg(base) ;

        int lim = (1 << base) ;
        for(int mask = 0; mask < lim ; mask ++){
            ll s= 0 ;
            string ans = string(base,'1') ;
            for(int bit = 0 ; bit < base ; bit++){
                if(mask & (1 << bit)){
                    s += v[bit+st] ;
                    ans[bit] = '0';
                }
            }
            a.push_back(s);
            rem[s] = ans ;
        }

        /* for(ll mask = 0 ; mask < (1 << base) ; mask ++){ */
        /*     ll temp = 0 ; */

        /*     for(ll bit = 0 ; bit <= base ;bit ++){ */
        /*         if(mask & (1 << bit)){ */
        /*             temp += v[bit+st] ; */
        /*         } */
        /*     } */

        /*     a.push_back(temp) ; */
        /* } */
    }

    public :
    void solve(){
        cin >> N ;
        ll sum = 0 ;
        for(int i = 1 ; i <= N ; i++){
            ll num = i ;
            for(int j = 1 ; j < K ; j++){
                num *= i ;
            }
            v.push_back(num) ;
            sum += num ;
        }

        ll s= sum / 2;

        bug() dbg(sum) ;
        bug() dbg(v) ;

        vector<ll> a, b;

        map<int,string> ra , rb ;

        cal_subarray(a,ra,0,N/2) ;
        cal_subarray(b,rb,N/2,N-N/2) ;

        sort(b.begin(),b.end()) ;
        /* bug() dbg(a) ; */
        /* bug() dbg(b) ; */

        ll mx = 0 ;

        string ans = string(N,'0') ;


        for(int i = 0 , sx = a.size(), sy = b.size(); i < sx; i++){
            if(a[i] > s) continue ;

            int p = lower_bound(b.begin(),b.end(),s-a[i]) - b.begin() ;
            if(p == sy || b[p] != (s-a[i])) p --;

            /* mx = max(mx, b[p] + a[i]) ; */
            if(mx < b[p] + a[i]){
                mx = b[p] + a[i] ;
                ans = ra[a[i]] + rb[b[p]] ;
            }
        }

        bug() dbg(mx) ;
        ll dif = sum-mx ;
        dif = abs(dif-mx) ;
        bug() dbg(dif) ;

        cout << ans << endl;


    }

};

class bruteforce{

    ll N ;
    vector<ll> v ;

    void cal_subarray(vector<ll> &a, map<int,string> &rem , ll st, ll base){

        bug() dbg(st) dbg(base) ;

        int lim = (1 << base) ;
        for(int mask = 0; mask < lim ; mask ++){
            ll s= 0 ;
            string ans = string(base,'1') ;
            for(int bit = 0 ; bit < base ; bit++){
                if(mask & (1 << bit)){
                    s += v[bit+st] ;
                    ans[bit] = '0';
                }
            }
            a.push_back(s);
            rem[s] = ans ;
        }

        /* for(ll mask = 0 ; mask < (1 << base) ; mask ++){ */
        /*     ll temp = 0 ; */

        /*     for(ll bit = 0 ; bit <= base ;bit ++){ */
        /*         if(mask & (1 << bit)){ */
        /*             temp += v[bit+st] ; */
        /*         } */
        /*     } */

        /*     a.push_back(temp) ; */
        /* } */
    }

    public :
    void solve(){
        cout << "{ ";
        for(int i = 1 ; i <= 33 ; i++){
            N = i ;
            Do() ;
        }
        cout << " \"0\" }" << endl ;
    }
    void Do(){
        ll sum = 0 ;
        v.clear() ;
        for(int i = 1 ; i <= N ; i++){
            ll num = i ;
            for(int j = 1 ; j < K ; j++){
                num *= i ;
            }
            v.push_back(num) ;
            sum += num ;
        }

        ll s= sum / 2;

        bug() dbg(sum) ;
        bug() dbg(v) ;

        vector<ll> a, b;

        map<int,string> ra , rb ;

        cal_subarray(a,ra,0,N/2) ;
        cal_subarray(b,rb,N/2,N-N/2) ;

        sort(b.begin(),b.end()) ;
        /* bug() dbg(a) ; */
        /* bug() dbg(b) ; */

        ll mx = 0 ;

        string ans = string(N,'0') ;


        for(int i = 0 , sx = a.size(), sy = b.size(); i < sx; i++){
            if(a[i] > s) continue ;

            int p = lower_bound(b.begin(),b.end(),s-a[i]) - b.begin() ;
            if(p == sy || b[p] != (s-a[i])) p --;

            /* mx = max(mx, b[p] + a[i]) ; */
            if(mx < b[p] + a[i]){
                mx = b[p] + a[i] ;
                ans = ra[a[i]] + rb[b[p]] ;
            }
        }

        bug() dbg(mx) ;
        ll dif = sum-mx ;
        dif = abs(dif-mx) ;
        bug() dbg(dif) ;

        cout << " \"" << ans << "\","  << endl ;


    }

};

int main(){
    ios_base::sync_with_stdio(false);

    cin >> K ;
    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){

        brute tc;
        tc.solve() ;
    }

    return 0 ;
}
