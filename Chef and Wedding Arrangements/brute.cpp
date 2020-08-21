
/**
 *    author        : Saurav Paul 
 *    created       : August 08, 2020 8:49 PM
 *    Problem Name  : Chef and Wedding Arrangements
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/CHEFWED
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

#define ll long long int

long long ans = 1e12 + 90 ;
void bruteforce(int point ,const vector<long long> &v, int cost , vector<bool>sep){
  if(point == v.size()){
    // calculation
    map <int,int> rem ;
    int same = 0, table = 1 ;;
    for(int i = 0 ; i < v.size() ; i++){
      int g = v[i] ;
      if(sep[i] == true){
        rem.clear() ;
        table ++ ;
      }
      else if(rem[g] == 1){
        same += 2;
      }
      else if(rem[g] > 1){
        same ++ ;
      }
      rem[g] ++ ;
    }
    long long temp = same + (cost * table) ;
    bug() dbg(v) dbg(sep) dbg(temp) dbg(same) ;
    ans = min(temp,ans) ;
    return ;
  }
  for(int i = point + 1; i <= v.size() ; i++ ){
    sep[i] = true ;
    bruteforce(i,v,cost,sep) ;
    sep[i] = false ;
  }
}

void solve(){
    ans = 1e12 + 90 ;
    ll guests , TableCost ;
    cin >> guests >> TableCost ;

    vector<ll> F(guests) ;
    for(auto &x : F){
        cin >> x ;
    }

    vector<bool> sep(guests+1) ;
    bug() dbg(sep) ;
    bruteforce(0,F,TableCost,sep) ;

    cout << ans << endl;

    /* auto getValue = [&](ll cnt){ */
    /*     ll same = 0 ; */
    /*     unordered_map<ll,ll> rem ; */
    /*     ll xcnt = 0 ; */
    /*     ll table = 1 ; */

    /*     bug() dbg(cnt) ; */
    /*     for(int i = 0 ; i < guests ; i++){ */
    /*         ll g = F[i] ; */
    /*         ll temp = 0 ; */
    /*         if(rem[g] == 1){ */
    /*             same += 2; */
    /*             temp += 2; */
    /*         } */
    /*         else if(rem[g] > 1) { */
    /*             same ++ ; */
    /*             temp ++ ; */
    /*         } */

    /*         bug() dbg(rem)  dbg(g) dbg(same) dbg(xcnt) ; */
    /*         if(same - xcnt > cnt){ */
    /*             table ++ ; */
    /*             rem.clear() ; */
    /*             same -= temp ; */
    /*             xcnt = same ; */
    /*         } */

    /*         rem[g] ++ ; */
    /*         bug() dbg(table) dbg(same) ; */

    /*     } */
    /*     ll ans = ((table * TableCost) + same) ; */
    /*     bug() dbg(ans) ; */
    /*     return ans; */
    /* } ; */

    /* // bruteforcing */ 
    /* ll ans = 1e12 + 90 ; */
    /* for(int cnt = 1 ; cnt <= guests ; cnt ++ ){ */
    /*     ans = min(ans, getValue(cnt)) ; */
    /* } */

    /* cout << ans << endl ; */

    /*


    3
    5 1
    5 1 3 3 3

    1 = 5 1 3 | 3 | 3 = 3 * 1 = 3
    2 = 5 1 3 3 | 3 = 1 * 2 + 2 = 3
    3 = 5 1 3 3 3 = 1 + 3 = 4

    5 14
    1 4 2 4 4

    1 = 1 4 2 | 4 | 4 = 14* 3 = 42
    2 = 1 4 2 4 | 4 = 14 * 8 + 2 = 30
    3 = 1 4 2 4 4 = 14 + 3 = 17
    
    5 2
    3 5 4 5 1
    1 = 3 5 4 | 5 1 = 2 * 2 = 4
    2 = 3 5 4 5 1 = 2 + 2 = 4



    auto check = [&](int cost){

    };
        
    int low = TableCost , high = TableCost * guests , ans = -1 ;
    while(low <= high){
        int mid = low + (high - 1)/2 ;

        if(check(mid)){
            ans = mid ;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    assert(ans != -1) ;
    cout << ans << endl ;
    */
}

int main(){
    ios_base::sync_with_stdio(false);

    int testcase ;
    cin >> testcase ;
    for(int i = 0 ; i < testcase ; i ++){
        solve();
    }

    return 0 ;
}
