
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

class bruteforce{

    ll N ;
    vector<ll> v ;

    vector<vector<ll>> ans_a , ans_b ;

    ll best = 1e18 + 90 ;
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

        vector<ll> a , b ;

        brute(0,a,b) ;

        cout << "V = " ;
        for(auto x : v) cout << x <<"  ";
        cout << "= " << sum << endl ;

        cout << best << endl ;

        int sz = ans_a.size() ;

        string Sans = string(N,'0') ;

        for(int i = 0 ; i < sz ; i++){
            ll ta = 0 , tb = 0;
            Sans = string(N,'0') ;

            cout <<"[ " ;
            for(auto x : ans_a[i]){
                cout << x << " " ;
                ta += x ;

                for(int j = 1; j <= N ; j++){
                    ll temp = j ;
                    for(int k = 1; k < K ; k++) temp *= j ;
                    if(x == temp){
                        Sans[j-1] = '1' ;
                        break ;
                    }
                }
            }
            cout << " = " << ta << " , ";
            
            for(auto x : ans_b[i]){
                cout << x << " " ;
                tb += x ;
            }
            cout << " = " << tb << " ] " << endl ;;

        }

        ll dif = best ;
        bug() dbg(dif) ;
        cout << Sans << endl ;

    }

    void brute(int pos , vector<ll> a , vector<ll> b){

      if(pos == N){
          ll as = 0 , bs = 0 ;
          for(auto x : a) as += x;
          for(auto x : b) bs += x;

          ll dif = abs(as-bs) ;
          if(dif <= best){

              if(dif < best){
                  ans_a.clear() ;
                  ans_b.clear() ;
              }
              best = dif ;
              ans_a.push_back(a) ;
              ans_b.push_back(b) ;
          }
          return ;
      }

      a.push_back(v[pos]) ;
      brute(pos+1,a,b) ;
      a.pop_back() ;
      b.push_back(v[pos]) ;
      brute(pos+1,a,b) ;

    }
};

int main(){
    ios_base::sync_with_stdio(false);

    cin >> K ;
    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){

        bruteforce tc;
        tc.solve() ;
    }

    return 0 ;
}
