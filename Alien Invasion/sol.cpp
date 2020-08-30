
/**
 *    author        : Saurav Paul 
 *    created       : August 30, 2020 9:52 AM
 *    Problem Name  : -X-
 *    Problem Limit : NULL , NULL
 *    Problem Url   : -X-
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
using namespace std;

using ll = long long int ;

class TC{

    int N , D;
    vector<double> ships ;
    double accuracy = 1e-6;
    
    public :
    void solve(){
        cin >> N >> D;

        for(int i = 0 ; i < N ; i++){
            double x ;
            cin >> x ;
            ships.emplace_back(x) ;
        }

        sort(ships.begin(),ships.end()) ;
        double low = 0.0 , high = 1e10 , ans = 0.0 ;

        while(high - low > accuracy){
            double mid = (low + high) / 2.0 ;

            if(check(mid)){
                low = mid ;
                ans = mid ;
            }
            else{
                high = mid ;
            }
        }

        cout<<fixed<<setprecision(6)<<ans<<"\n";
    }

    bool check(double mnt){
        bool ok = true ;
        double curr = 0 , end_time = 0 ; 

        for(int i = 0 ; i < N ; i++){
            if(i){
                end_time = ships[i] + D ;
                if(end_time < curr){
                    ok = false ;
                    break ;
                }
                curr = max(curr,double(ships[i])) + mnt ;
            }
            else{
                curr = ships[i] + mnt ;
            }
        }
        return ok ;
    }
};

int main(){
    ios_base::sync_with_stdio(false);

    int testcases = 1;
    cin >> testcases ;
    for(int i = 1 ; i <= testcases ; i ++){
        TC tc;
        tc.solve() ;
        /* exit(0) ; */
    }

    return 0 ;
}
