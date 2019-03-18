#include<bits/stdc++.h>
#define endl '\n'
#define ll long long int
#define loop(i,a,b)           for(ll i=a;i<=b;++i)
#define pb                    push_back
#define F                     first
#define S                     second
#define mp                    make_pair
#define clr(x)                x.clear()
#define MOD                   1000000007
#define itoc(c)               ((char)(((int)'0')+c))
#define SZ(x)                 (x).size()
#define all(p)                p.begin(),p.end()
#define mid(s,e)              (s+(e-s)/2)
#define tcase()               ll t,n; cin>>t;n=t; while(t--)
#define iscn(num)             scanf("%d",&num);
using namespace std;
typedef pair<ll,ll>Pair;
bool file=0,rt=1;
clock_t tStart ;
void FAST_IO();
////////////////////////
int vowel[2][2][2][2][2];
int main()
{

    FAST_IO();
    ////////////////////////
    ll tcase,n,temp;
    cin>>tcase;
    while(cin>>n){
        char c;
        string final,s;
        std::map<string, ll> m;
        std::map<string, ll> :: iterator it,it2;
        for(int i=0; i< n; i++){
            final="00000";
            cin>>s;
            ll sz=SZ(s);
            for(int i=0; i< sz ; i++){
                c=s[i];
                if(c=='a')
                    final[0]='1';
                if(c=='e')
                    final[1]='1';
                if(c=='i')
                    final[2]='1';
                if(c=='o')
                    final[3]='1';
                if(c=='u')
                    final[4]='1';
            }
            m[final]++;
        }
        ll cnt=0;
        ll j=1;
        for(it=m.begin() ; it!=m.end(); it++,j++){
            string a=it->first ;
            if(a=="11111"){

                for(int i=it->second-1 ; i>0 ; i--)
                    cnt+=i;                
            }
            for(it2=next(it); it2!=m.end(); it2++){
               bool flag=true ;
                string b=it2->first;
                   for(int i=0; i< 5 ; i++){
                    if(a[i]=='1' || b[i]=='1')
                        continue ;
                    else{
                        flag=false;
                        break;
                    }
                   }
               if(flag){
                cnt+=(it2->second * it->second) ;

               }
              
            }

        }
        cout<<cnt<<endl;
    }

    ////////////////////////
    if(rt && file){
     printf("\nTime taken: %.6fs", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    }
    return 0;
   }

void FAST_IO()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    //cout.tie(NULL);
    //cout.setf(ios::fixed);
    //cout.precision(2);
    if(rt && file){ tStart = clock(); }
    if(file){
    #ifndef _offline
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    }
}
