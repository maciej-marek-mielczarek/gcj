#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int n,k;
        cin >>n>>k;
        if(n>1000)
            break;
        vector<int> c(n,0);
        vector<int> d(n,0);
        for(int i=0;i<n;++i)
            cin>>c[i];
        for(int i=0;i<n;++i)
            cin>>d[i];
        int fairfights=0;
        for(int l=0;l<=n-1;++l)
        {
            for(int r=l;r<=n-1;++r)
            {//check what swords they pick, then see if it is a fair fight
                int cskill=c[l], dskill=d[l];
                for(int s=l;s<=r;++s)
                {
                    if(c[s]>cskill)
                        cskill = c[s];
                    if(d[s]>dskill)
                        dskill = d[s];
                }
                /*int cpicks=0, dpicks=0;
                for(int s=l;s<=r;++s)
                {
                    if(c[s]==cskill)
                        ++cpicks;
                    if(d[s]==dskill)
                        ++dpicks;
                }*/
                if(((cskill-dskill) <= k) && ((dskill-cskill) <= k))
                    ++fairfights;
                    //fairfights+=cpicks*dpicks;
                std::cerr<<"("<<l<<", "<<r<<"): "<<fairfights<<endl;
            }
        }
        cout << "Case #" << test_case << ": "<<fairfights<<endl;
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
