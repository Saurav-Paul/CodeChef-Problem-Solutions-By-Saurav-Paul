
/**
 *    author        : Saurav Paul 
 *    created       : September 06, 2020 8:37 PM
 *    Problem Name  : Find XOR
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/FINXOR
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

class TC{

    long long N ;

    public :
    void solve(){
        cin >> N ;

        /* bruteforce() ; */
        /* return ; */
        long long prv =  ask(1), curr, ans = 0 ;

        if((prv&1) != (N&1)) ans = 1;

        for(int bit = 1 ; bit < 20 ; bit ++){
            int base = pow(2,bit+1) - 1 ;
            int b = pow(2,bit) ;

            curr = ask(base) ;
            if(curr >= prv * 2) break ;
            /* if( curr == prv ) continue ; */

            long long dif = prv - curr ;
            long long low = 0 , high = N , cnt = -1 ;

            while(low <= high){
                long long mid = (low + high) / 2;

                long long temp = (mid - (N-mid)) * b ;

                if(temp == dif){
                     cnt = mid ; 
                     break ;
                }
                if(temp < dif){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }

            }

            bug() dbg(cnt);
            /* assert(cnt != -1) ; */
            /* if(cnt == -1) continue ; */
            cnt = N - cnt ;
            if((cnt&1) != (N&1)){
                ans += pow(2,bit) ;
            }

            bug() dbg(dif) dbg(curr) dbg(prv) dbg(ans) dbg(cnt) ;
            prv = curr ;
            
        }

        print_answer(ans);



    }
    void print_answer(long long n){
        cout << "2 " << n << endl ;
        cout << flush ;
        long long x ;
        cin >> x;
        /* assert(x == 1) ; */
    }
    long long ask(long long n){
        cout << "1 " << n << endl ;
        cout << flush ;

        long long x ;
        cin >> x ;
        return x ;

    }
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
    void bruteforce(){
        bug() "start" ;
        vector<int> v ;
        int ans = 0 ;
        for(int i = 0 ; i < N ; i++){
            int x ;
            cin >> x;
            v.push_back(x) ;
            ans ^= x;
        }

        bug() dbg(v) ;
        bug() dbg(ans) dbg(binary(ans)) ;

        while(true){
            int x ;
            cin >> x;
            if(x == -1){
                bug() "Done." ;
                break ;
            }
            int sum = cal(x,v) ;
            string bsum = binary(sum) ;
            bug() dbg(bsum) ;
            bug() dbg(x) dbg(sum) ;
            /* cout << sum << endl ; */
        }
    }
    int cal(int x , vector<int> v){
        int sum = 0 ;
        for(int i = 0 ; i < N ; i++){
            sum += v[i]^x ;
            v[i] ^= x;
        }
        bug() "bin" ;
        cout << endl ;
        for(int i = 0 ; i < N ; i++){
            cout << v[i] << " = " << binary(v[i]) << endl ;
        }
        cout << endl ;
        return sum ;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
