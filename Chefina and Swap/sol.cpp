
/**
 *    author        : Saurav Paul 
 *    created       : September 05, 2020 9:54 PM
 *    Problem Name  : Chefina and Swap
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/CHFNSWAP
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

class TC{

    long long N ;
    public :
    void solve(){
        cin >> N ;

        long long sum = N * (N+1) ;
        sum /= 2;
        long long ans = 0;

        if(sum%2==0){
            long long half = sum / 2 ;

            long long low = 0 , high = N , pos = - 1, s ;
            while(low <= high){
                long long mid = (low + high) / 2 ;

                s = mid * (mid + 1) ;
                s /= 2 ;

                if(s == half){
                    pos = mid ;
                    break ;
                }
                if(s > half){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                    pos = mid ;
                }

            }

            s = pos * (pos + 1) ;
            s /= 2;

            if(s == half){
                ans = nc2(N-pos) + nc2(pos) + N-pos ;
            }
            else{
                ans = N - pos ;
            }
        }

        cout << ans << endl ;

    }

    long long nc2(long long n){
        n = n * (n - 1) ;
        n /= 2;
        return n ;
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
