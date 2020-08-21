
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

void solve(){
    int guests , TableCost ;
    scanf("%d%d",&guests,&TableCost) ;

    vector<int> F(guests+1) ;
    for(int i = 1 ; i <= guests ; i++) scanf("%d",&F[i]) ;

    const int INF = 1e9 + 90 ;
    vector<int> dp(guests + 1, INF) ;
    for(int i = guests ; i > 0 ; i--){
        int cost = TableCost ;
        unordered_map<int,int> rem ;
        for(int j = i ; j <= guests ; j++){

            int g = F[j] ;
            if(rem[g] == 1) cost += 2;
            else if(rem[g] > 1) cost += 1;

            rem[g] ++ ;
            
            if(j == guests){
                dp[i] = min(dp[i] , cost) ;
                continue ;
            }
            else{
                dp[i] = min(dp[i] ,cost + dp[j+1]) ;
            }
        }
    }
    printf("%d\n",dp[1]) ;
}

int main(){

    int testcase ;
    scanf("%d",&testcase) ;
    for(int i = 0 ; i < testcase ; i ++){
        solve();
    }

    return 0 ;
}
