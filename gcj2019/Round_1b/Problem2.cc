#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int test_case = 1, n_test_cases, w;
    cin >> n_test_cases>>w;
    for(;test_case <= n_test_cases; ++test_case)
    {
        if(w<3)
            break;
        int a,b,c,d,e,f;
        cout << 1<<endl;
        cin>>a;
        cout<<2<<endl;
        cin>>b;
        cout<<3<<endl;
        cin>>c;
        cout<<4<<endl;
        cin>>d;
        cout<<5<<endl;
        cin>>e;
        cout<<6<<endl;
        cin>>f;
        int r1,r2,r3,r4,r5,r6;
        r1=((f-2*a)-6*(b-a)-2*(c-b))/40;
        r2=(b-a)-2*r1;
        r3=(c-b)-4*r1;
        r4=(d-c)-8*r1-2*r2;
        r5=(e-d)-16*r1;
        r6=a-2*r1-r2-r3-r4-r5;
        cout<<r1 << " "<<r2<< " "<<r3<< " "<<r4<< " "<<r5<< " "<<r6<<endl;
        int ans;
        cin>>ans;
        if(ans==-1)
            break;
        //cout << "Case #" << test_case << ": ";
    }
    /*
    int test_case = 1, n_test_cases = 0;
    string tmp{};
    std::getline(cin, tmp);
    for(char digit : tmp)
    {
        if(digit >= '0' && digit <= '9')
        {
            n_test_cases *= 10;
            n_test_cases += (digit - '0');
        }
    }
    for(;test_case <= n_test_cases; ++test_case)
    {
    }
    */
    return 0;
}
