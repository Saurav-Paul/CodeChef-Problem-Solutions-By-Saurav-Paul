
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

class TC{

    long long N ;

    public :
    void solve(){
        cin >> N ;

        long long prv =  ask(1), curr, ans = 0 ;

        if((prv&1) != (N&1)) ans = 1;

        for(int bit = 1 ; bit < 20 ; bit ++){
            int base = pow(2,bit+1) - 1 ;
            int b = pow(2,bit) ;

            curr = ask(base) ;
            if(curr >= prv * 2) break ;

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

            cnt = N - cnt ;
            if((cnt&1) != (N&1)){
                ans += b ;
            }

            prv = curr ;
            
        }

        print_answer(ans);



    }
    void print_answer(long long n){
        cout << "2 " << n << endl ;
        cout << flush ;
        long long x ;
        cin >> x;
        assert(x == 1) ;
    }
    long long ask(long long n){
        cout << "1 " << n << endl ;
        cout << flush ;

        long long x ;
        cin >> x ;
        return x ;

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
