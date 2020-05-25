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
        int p, q;
        cin >> p >> q;
        if(q>100)
            break;
        vector<int> tmp(11, 0);
        vector< vector<int> > interest(11, tmp);
        for(int n=0;n<p;++n)
        {
            int xx, yy;
            cin >> xx >> yy;
            char d;
            cin >> d;
            if(d=='N')
            {
                for(int x=0;x<=q;++x)
                {
                    for(int y=yy+1;y<=q;++y)
                    {
                        ++(interest[x][y]);
                    }
                }
            }
            if(d=='S')
            {
                for(int x=0;x<=q;++x)
                {
                    for(int y=0;y<=yy-1;++y)
                    {
                        ++(interest[x][y]);
                    }
                }
            }
            if(d=='E')
            {
                for(int x=xx+1;x<=q;++x)
                {
                    for(int y=0;y<=q;++y)
                    {
                        ++(interest[x][y]);
                    }
                }
            }
            if(d=='W')
            {
                for(int x=0;x<=xx-1;++x)
                {
                    for(int y=0;y<=q;++y)
                    {
                        ++(interest[x][y]);
                    }
                }
            }
        }
        int x=0, y=0, score=interest[0][0];
        for(int xi=0;xi<=q;++xi)
        {
            for(int yi=0;yi<=q;++yi)
            {
                if(interest[xi][yi]>score)
                {
                    score = interest[xi][yi];
                    x=xi;
                    y=yi;
                }
            }
        }
        cout << "Case #" << test_case << ": " << x << " " << y<<"\n";
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
