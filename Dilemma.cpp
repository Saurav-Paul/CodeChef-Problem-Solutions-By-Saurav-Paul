#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;
	cin >> s;
	int cnt = 0;
	for(auto x : s)
		if(x=='1')
			cnt ++;
			
	cout<<(cnt&1?"WIN":"LOSE")<<endl;
}
int main(){
	
	ios_base::sync_with_stdio(false);
	
	int t; 
	cin >> t;
	while(t--)
		solve();
	
	return 0;
}
