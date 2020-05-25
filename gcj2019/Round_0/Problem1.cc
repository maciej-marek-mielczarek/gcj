#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
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
        cout << "Case #" << test_case << ": ";
        string input;
        std::getline(cin, input);
        string a{}, b{};
        int digit_number = 1;
        bool first_digit_was_one = false;
        for(char digit : input)
           {
            if((digit_number == 2) && first_digit_was_one)
            {
                if(digit == '9')
                {
                    a.push_back('9');
                    b.push_back('1');
                    b.push_back('0');
                }
                else
                {
                    a.push_back((digit-'0'+10)/2+'0');
                    b.push_back((digit-'0'+11)/2+'0');
                }
            }
            else
            {
                if(digit == '4')
                {
                    a.push_back('2');
                    b.push_back('2');
                }
                else
                {
                    if(digit_number == 1)
                    {
                        if(digit == '1')
                        {
                            first_digit_was_one = true;
                        }
                        else
                        {
                            first_digit_was_one = false;
                            if(digit == '5')
                            {
                                a.push_back('2');
                                b.push_back('3');
                            }
                            else
                            {
                                a.push_back('1');
                                b.push_back(digit - 1);
                            }
                        }
                    }
                    else
                    {
                        a.push_back(digit);
                        b.push_back('0');
                    }
                }
            }
            ++digit_number;
        }
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
