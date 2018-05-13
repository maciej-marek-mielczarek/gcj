#include<iostream>
//#include<string>
//#include<vector>
#include<cmath>
#include<iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    double a, sd = sqrt(2)/4;
    cout.precision(10);
    cout << std::fixed;
    for(;test_case <= n_test_cases; ++test_case)
    {
        cin >> a;
        cout << "Case #" << test_case << ":" << endl;
        double sin_alpha, cos_alpha;
        if(a*a <= 2)
        {
            sin_alpha = sqrt((1-a*sqrt(2-a*a))/2);
            cos_alpha = sqrt((1+a*sqrt(2-a*a))/2);
            //cout formatting - 10 digits (should be enough)
            cout << cos_alpha/2 << " " << sin_alpha/2 << " " << 0 << endl;
            cout << -sin_alpha/2 << " " << cos_alpha/2 << " " << 0 << endl;
            cout << 0 << " " << 0 << " " << 0.5 << endl;
        }
        else
        {
            sin_alpha = (a-sqrt(6-2*a*a))/3;
            cos_alpha = (sqrt(a*a+3+2*a*sqrt(6-2*a*a)))/3;
            //cout formatting - 10 digits (should be enough)
            cout << sd << " " << sd << " " << 0 << endl;
            cout << -sd*cos_alpha << " " << sd*cos_alpha << " " << sin_alpha/2 << endl;
            cout << sd*sin_alpha << " " << -sd*sin_alpha << " " << cos_alpha/2 << endl;
        }
    }
    return 0;
}
