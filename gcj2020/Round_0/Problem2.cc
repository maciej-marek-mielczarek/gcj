#include <iostream>
#include <string>

std::string parenthesize(std::string x)
{
    if(x.empty())
    {
        return x;
    }
    int n=0;
    for(std::string::iterator it=x.begin(); it!=x.end(); ++it)
    {
        if(*it == '0')
        {
            return parenthesize(x.substr(0, n)) + "0" + parenthesize(x.substr(n+1));
        }
        ++n;
    }
    for(std::string::iterator it=x.begin(); it!=x.end(); ++it)
    {
        if((*it >= '0') && (*it <= '9'))
        {
            --(*it);
        }
    }
    return "(" + parenthesize(x) + ")";
}

std::string replace_numbers(std::string nums, std::string str)
{
    std::string::iterator n = nums.begin();
    for(std::string::iterator it=str.begin(); it!=str.end(); ++it)
    {
        if(*it == '0')
        {
            *it = *n;
            ++n;
        }
    }
    return str;
}

int main()
{
    int t;
    std::cin >> t;
    for(int test_number=1; test_number<=t; ++test_number)
    {
        std::cout << "Case #" << test_number << ": ";
        std::string in;
        std::cin >> in;
        std::string out = "";
        out = parenthesize(in);
        out = replace_numbers(in, out);
        std::cout << out << "\n";
    }
    return 0;
}