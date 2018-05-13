//c++11
#include<iostream>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::multiset;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    int n_numbers, curr_number;
    for(;test_case <= n_test_cases; ++test_case)
    {
        cin >> n_numbers;
        multiset<unsigned long> odd, even;
        unsigned long read_element;
        bool reading_odd = true;//numbering elements in the given list from 1
        for(curr_number = 1; curr_number <= n_numbers; ++curr_number)
        {
            cin >> read_element;
            if(reading_odd)
            {
                odd.insert(read_element);
            }
            else
            {
                even.insert(read_element);
            }
            reading_odd = !reading_odd;
        }
        cout << "Case #" << test_case << ": ";
        auto it_odd = odd.begin();
        auto it_even = even.begin();
        reading_odd = true;
        int answer = -1;
        bool sorting_successful = true;
        while(true)//(!((it_odd == odd.end()) & (it_even == even.end())))
        {
            ++answer;
            if(reading_odd)
            {
                if((*it_odd) > (*it_even))
                {
                    sorting_successful = false;
                    break;
                }
                ++it_odd;
                if(it_odd == odd.end())
                {
                    break;
                }
            }
            else
            {
                if((*it_even) > (*it_odd))
                {
                    sorting_successful = false;
                    break;
                }
                ++it_even;
                if(it_even == even.end())
                {
                    break;
                }
            }
            reading_odd = !reading_odd;
            //this is the zipper thing
        }
        //sort odd and even sublists separately,
        //then zipper-merge them and go through
        //the resulting list to find the answer
        if(sorting_successful)
        {
            cout << "OK";
        }
        else
        {
            cout << answer;
        }
        cout << endl;
    }
    return 0;
}
