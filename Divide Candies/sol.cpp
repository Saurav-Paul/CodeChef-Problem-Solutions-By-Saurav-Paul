
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

string binary(long long n){
    if(n == 0) return string(9,' ')+"0";
    string x = "" ;
    while(n){
        x += (n%2) + '0' ;
        n /= 2;
    }
    int sz = x.size() ;
    if(sz < 10){
        x += string(10-sz,' ') ;
    }
    reverse(x.begin(),x.end()) ;
    return x ;
}

using ll = long long int ;
int K ;

class K4{
    ll N ;

     vector<string> precomputed_s = {
 "0" ,
 "10" ,
 "110" ,
 "1110" ,
 "11110" ,
 "111110" ,
 "1111110" ,
 "11010001" ,
 "111110001" ,
 "1010110110" ,
 "11111010110" ,
 "110010101001" ,
 "1101001010110" ,
 "11111110000101" ,
 "100001110101001" ,
 "0000111000001110" ,
 "10000111111101010" ,
 "111111001011110001" ,
 "1000010010110111100" ,
 "00001010110111011100" ,
 "111111111011011011100" ,
 "0101001111011111110100" ,
 "00001000100110111101100" ,
 "000010011110110111110100" ,
 "1000110101011101111111000" ,
 "11101011111011101111001010" ,
 "001111000000011110111111000" ,
 "0001011111000101111011111000" ,
 "11101111111011001110111010001" ,
 "100010010001010111111111011000" ,
 "1101100001110111011111111101000" ,
 "00010000010110101111111111110000" ,
 "110101011100010111011111111110000" ,
 "1010101110111111111011101111101000" ,
 "01000111001011010111111101111110000" ,
 "100101010100011101111111111011110000" ,
 "1111111010111011111110111111111000100" ,
 "10010100100101011111110111111101110000" ,
 "000000100100010111110111111111111010000" ,
 "0000001001001100010111111111111111100000" ,
 "01000101010110011111111111011111111100000" ,
 "011111101111111010111110101111111111100000" ,
 "0001010011000001110111111111111011111100000" ,
 "00000100000101011110111111111111110111100000" ,
 "001111101111101111111010111111111110111100000" ,
 "0110010100010101010110111111111111111101100000" ,
 "01010100000101010111101111111111111111111000000" ,
 "001001000100000111110111110111111111111111000000" ,
 "0100010001010110001101111111110111111111111000000" ,
 "11111101101101111111111011111111111011111111000000" ,
 "010100000000010101011110111111111111101111111000000" ,
 "0100000000110101110111111101111111111111011111000000" ,
 "11001001011110111111111111111111111111111111101000000" ,
 "010101011101000101000111111111111111111111111101000000" ,
 "1001000000010111010101111101111111111111111111110000000" ,
 "00000001000001000011110111111111011111111111111110000000" ,
 "010001011101010111010111110111111111011111111111110000000" ,
 "0010111101100111110111111111111111111111111011111110000000" ,
 "00000101000100010111010111111111111111111111101111110000000" ,
 "000100010101010000110101111111111111111111111111011110000000" ,
 "1100110111111101111110111111111111111111111111111111010000000" ,
 "00000001000001000011010111111111011111111111111111110110000000" ,
 "000101010001010111000101111111110111111111111111111111100000000" ,
 "0000110001010101011101011101111111111101111111111111111100000000" 
    } ;
    public :
    void solve(){

        string pattern = "10010110011010010110100110010110";
        /* dif_print(pattern,32) ; */

        cin >> N ;

        if(N <= 32){
            string ans = precomputed_s[N-1] ;

            dif_print(ans,N) ;

            cout << ans << endl ;
            return ;
        }

        int mod = N % 32 ;
        int tme = N / 32 ;


        ll temp = 32 + mod ;

        string ans = precomputed_s[temp-1] ; 

        bug() dbg(ans) ;

        dif_print(ans,temp);

        for(int i = 1; i < tme ; i++){
            ans += pattern ;
        }

        cout << ans << endl ;

    }

    void dif_print(string s, int n ){
        ll a = 0 , b = 0 ;

        bug() dbg(s) dbg(s.size()) dbg(n) ;
        for(ll i = 1; i <= n ; i++){
            ll num = i * i * i * i ;
            if(s[i-1] == '1') a += (num) ;
            else b += (num);
        }

        bug() dbg(a) dbg(b) ;

        cout << abs(a - b) << endl ;
    }

};

class K3{
    ll N ;

     vector<string> precomputed_s = {
     "0",
     "01",
     "001",
     "0001",
     "00001",
     "011110",
     "0001110",
     "00110110",
     "011010110",
     "1111111010",
     "00001101001",
     "001011100110",
     "0011110101001",
     "01011001101001",
     "110100110010110",
     "0110100110010110",
     "11001011001101001",
     "010011010101011010",
     "1100110110100111100",
     "01011111110111111000",
     "001010011111111010010",
     "1011111111100001100101",
     "01111111111100010001110",
     "111111111111010100001110",
     "1101111111111110000001101",
     "00110111111110010000110110",
     "011111111111110100000111001",
     "1011011111111111101001000011",
     "01111111111111000101001011001",
     "000011111111111010111110010010",
     "1110111111111110101010110110100",
     "11111111111111110101000011101010",
     "111111111111111110011010010010110",
     "0"
    } ;
    public :
    void solve(){
        cin >> N ;

        if(N <= 32){
            string ans = precomputed_s[N-1] ;

            dif_print(ans,N) ;

            cout << ans << endl ;
            return ;
        }

        int mod = N % 16 ;
        int tme = N / 16 ;

        string pattern = "0110100110010110";

        ll temp = 16 + mod ;

        string ans = precomputed_s[temp-1] ; 

        bug() dbg(ans) ;

        dif_print(ans,temp);

        for(int i = 1; i < tme ; i++){
            ans += pattern ;
        }

        cout << ans << endl ;

    }

    void dif_print(string s, int n ){
        ll a = 0 , b = 0 ;

        for(ll i = 1; i <= n ; i++){
            if(s[i-1] == '1') a += (i * i * i) ;
            else b += (i * i * i );
        }

        cout << abs(a - b) << endl ;
    }

};


class K1{
    ll N ;

    public :
    void solve(){
        cin >> N ;

        ll sum = 0 ;
        bug() dbg(K) ;
        for(int i = 1; i <= N ; i++){
            ll temp = i ;

            sum += temp ;

        }

        ll half = sum / 2 + (sum&1) ;

        ll a = 0 , b = 0 ;
        vector<int> ans(N+1) ;
        for(ll i = N ; i > 0 ; i--){
            ll num = i ;

            if(half - num >= 0){
                ans[i] = 1 ;
                half -= num;
                a += num ;
            }
            else{
                b += num ;
            }

        }

        cout << abs(a-b) << "\n" ;

        for(int i = 1; i <= N ; i++) cout << ans[i] ;
        cout << endl ;

    }
};

class K2{
    ll N ;


    vector<string> precomputed_s = {"1","10","110","1110","10110","110110","1101001","10010110","111100110","1011011010",
    "10111000101","111111110010", "1111111001001","11111100011001","111111010100110","1111011100011001"} ;

    public :
    void solve(){
        cin >> N ;

        if(N <= 16){
            string ans = precomputed_s[N-1] ;

            dif_print(ans,N) ;

            cout << ans << endl ;
            return ;
        }

        int mod = N % 8 ;
        int tme = N / 8 ;

        string pattern = "10010110";

        ll temp = 8 + mod ;

        string ans = precomputed_s[temp-1] ; 

        bug() dbg(ans) ;

        dif_print(ans,temp);

        for(int i = 1; i < tme ; i++){
            ans += pattern ;
        }

        cout << ans << endl ;

    }

    void dif_print(string s, int n ){
        ll a = 0 , b = 0 ;

        for(int i = 1; i <= n ; i++){
            if(s[i-1] == '1') a += (i * i) ;
            else b += (i * i );
        }

        cout << abs(a - b) << endl ;
    }

};
class bruteforce{

    ll N ;
    vector<ll> v , ans_a , ans_b;

    ll best = 1e18 + 90 ;
    public :
    void solve(){
        cin >> N ;
        for(int i = 1 ; i <= N ; i++){
            ll num = i ;
            for(int j = 1 ; j < K ; j++){
                num *= i ;
            }
            v.push_back(num) ;
        }

        vector<ll> a , b ;

        brute(0,a,b) ;


        bug() dbg(v) ;

        cout << best << endl ;

        for(auto x : ans_a) cout << x <<" " ;
        cout << endl ;

        for(auto x : ans_b) cout << x <<" " ;
        cout << endl ;
    }

    void brute(int pos , vector<ll> a , vector<ll> b){

      if(pos == N){
          ll as = 0 , bs = 0 ;
          for(auto x : a) as += x;
          for(auto x : b) bs += x;

          ll dif = abs(as-bs) ;
          if(dif < best){
              best = dif ;
              ans_a = a ;
              ans_b = b ;
              /* bug() dbg(dif) ; */
              /* bug() dbg(a) ; */
              /* bug() dbg(b) ; */
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

class TC{

    int N ;

    public :
    void solve(){
        cin >> N ;

    }
};

int main(){
    ios_base::sync_with_stdio(false);

    cin >> K ;
    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){

        if(K == 1){
            K1 k1 ;
            k1.solve() ;
        }
        else if(K == 2){
            K2 k2 ;
            k2.solve() ;
        }
        else if(K == 3){
            K3 k3;
            k3.solve() ;
        }
        else if(K == 4){
            K4 k4 ;
            k4.solve() ;
        }
        else{
            assert(false) ;
        }

    }

    return 0 ;
}
