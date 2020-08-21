/**
 *    author        : Sudipta Banik Trisha 
 *    created       : August 08, 2020 9:14 PM
 *    Problem Name  : Chef and Linear Chess
 *    Problem Limit : 1000 ms , 256 MB
 *    Problem Url   : https://www.codechef.com/AUG20B/problems/LINCHESS
 *    @genarated by : ai-virtual-assistant
**/

#include<bits/stdc++.h>
#define ll long long int 
using namespace std;

void solve(){

        ll n,k;
        cin >> n >> k;

        ll arr[n+1], mini=INT_MAX, temp;
        bool flag = false;
        
       // for(ll i=0; i<n; i++){
         //   cin >> arr[i];
        //}

        for(ll i=0; i<n; i++){
            cin >> arr[i];
            if(k % arr[i] == 0){
                if( mini > (k/arr[i]) ){
                    mini = k/arr[i];
                    temp = i;
                    flag = true;
                }
            }
        }

        if( flag == false ){
            cout << "-1" << endl;
        }

        else cout << arr[temp] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    
    ll test;
    cin >> test;

    while(test--){
        solve() ;
    }

    return 0 ;
}
