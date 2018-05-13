#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int n_robots, n_bits, n_cashiers;
        cin >> n_robots >> n_bits >> n_cashiers;
        long long max_items[1000], scan_times[1000], pack_times[1000];
        long long cashier_time[1000]={},cashier_items[1000]={};
        int cashier_id;
        for(cashier_id=0;cashier_id<n_cashiers;++cashier_id)
        {
            cin >> max_items[cashier_id] >> scan_times[cashier_id] >> pack_times[cashier_id];
        }
        if(n_bits>20)
        {
            break;
            //small-only solution
        }
        for(int n=0;n<n_bits;++n)
        {
            int best_cashier_id=0;
            for()
        }
        cout << "Case #" << test_case << ": ";
    }
    return 0;
}
