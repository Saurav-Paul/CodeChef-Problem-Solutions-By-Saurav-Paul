
/**
 *    author        : Saurav Paul 
 *    created       : September 13, 2020 5:11 PM
 *    Problem Name  : Divide Candies
 *    Problem Limit : 2000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/SEPT20A/problems/EQDIV
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    public :
    void solve(){
        string pattern = "1001011001101001";
        int st = 5;

        ll a = 0 , b = 0 ;
        for(int i = 0 ; i < (int)pattern.size() ; i++){

            if(pattern[i] == '0'){
                b += (st * st * st) ;
            }
            else{
                a += (st * st * st) ;
            }

            st ++ ;

        }

        cout << a <<" " << b << endl ;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.solve() ;
    }

    return 0 ;
}
