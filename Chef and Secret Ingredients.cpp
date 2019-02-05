#include<iostream>
using namespace std;
int main()
{
    int t_case;
    cin>>t_case;
    while(t_case--)
    {

        int n;
        int alp[30];
        bool check[30];
        for(int i=0; i<30; i++)
        {
            alp[i]=0;
        }
        cin>>n;
        int temp=n;
        while(temp--)
        {

            for(int i=0; i<30; i++)
            {
                check[i]=0;
            }
            string s;
            cin>>s;

            for(int i=0; i<s.size(); i++)
            {
                char c=s[i];

                if(check[c-97])
                    continue;
                alp[c-97]++;
                check[c-97]=1;

            }


        }
        int cnt=0;
        for(int i=0; i<30; i++)
        {
            if(alp[i]==n)
                cnt++;

        }
        cout<<cnt<<endl;
    }
    return 0;
}
