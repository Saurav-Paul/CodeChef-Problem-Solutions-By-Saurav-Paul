#include <bits/stdc++.h>
using namespace std;
int alpha[27];
int main()
{
        string s;
        int tcase;
        cin>>tcase;
        while(tcase--)
        {
                cin>>s;
                int tsize=s.size();
                for(int i=0; i<tsize; i++)
                        alpha[s[i]-'A']++;
                sort(alpha,alpha+26,greater<int>());

                int temp=0,minimum=INT_MAX;
                for(int i=0; i<26; i++)
                {
                        int j=i+1;

                        if(tsize%j==0)
                        {
                                int tdivide=tsize/j;
                                int total=0;
                                for(int M=0; M<=i; M++)
                                {
                                        if(alpha[M]<tdivide)
                                                total+=abs(alpha[M]-tdivide);

                                }

                                if(minimum>total)
                                        minimum=total;
                        }

                }
                cout<<minimum<<endl;
                memset(alpha,0,sizeof(alpha));
        }
        return 0;
}

