#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int t;
    cin>>t;
    for(int test=1;test<=t;++test)
    {
        cout<<"Case #"<<test<<":\n";
        int n;
        cin>>n;
        cout <<"1 1"<<endl;
        if(n<=500)
        {
            for(int k=2;k<=n;++k)
            {
                cout<<k<<" 1"<<endl;
            }
        }
        else if(n<=1000)
        {
            n-=7;
            int r=n/2,l=n-r;
            for(int k=2;k<=n;)
            {
                if(k==2)
                {
                    cout<<"2 1\n3 2\n4 2\n5 2\n";
                    k+=3;
                }
                else if(k==r+1)
                {
                    cout<<r+1<<" 2"<<endl;
                    k+=r;
                }
                else if(k<=r)
                {
                    cout<<k<<" 1"<<endl;
                    ++k;
                }
                else
                {
                    cout<<k-r<<" 1"<<endl;
                    ++k;
                }
            }
        }
    }
    return 0;
}