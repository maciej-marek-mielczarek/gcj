#include <iostream>

int main()
{
    int t, b;
    std::cin >> t >> b;
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        int ans[101];
        int first_same_pair_location = -1;
        int first_diff_pair_location = -1;
        for(int n=1;n<=5;++n)
        {//read first 5 and last 5
            std::cout << n << std::endl;
            std::cin >> ans[n];
            std::cout << b+1-n << std::endl;
            std::cin >> ans[b+1-n];
            if(ans[b+1-n]==ans[n])
            {
                if(first_same_pair_location == -1)
                {
                    first_same_pair_location = n;
                }
            }
            else
            {
                if(first_diff_pair_location == -1)
                {
                    first_diff_pair_location = n;
                }
            }
        }
        if(b==10)
        {//try to answer for b==10
            for(int n=1;n<=10;++n)
            {
                std::cout << ans[n];
            }
            std::cout << std::endl;
            char grade;
            std::cin >> grade;
            if(grade == 'N')
            {//wrong answer, shouldnt happen
                return 0;
            }
            else
            {//good answer, go to next case
                continue;
            }
        }
        //we have 1st 5 and last 5, b is 20 or 100
        //see what changed, then make more queries
        int known_bits=10;
        for(int queries_made = 10; queries_made<=150;)
        {
            if(known_bits == b)
            {//all bits known, try to answer, then go to next case
                for(int as=1;as<=b;++as)
                {
                    std::cout<<ans[as];
                }
                std::cout<<std::endl;
                char grade;
                std::cin >> grade;
                if(grade == 'N')
                {//wrong answer, shouldnt happen
                    return 0;
                }
                else
                {//good answer, go to next case
                    break;
                }
            }
            if((first_same_pair_location > -1) && (queries_made%10 == 0))
            {//some pairs were the same, update those
                std::cout << first_same_pair_location << std::endl;
                int tmp;
                std::cin >> tmp;
                ++queries_made;
                if(tmp != ans[first_same_pair_location])
                {//same pairs changed, update ans
                    for(int n=1;n<=known_bits/2;++n)
                    {
                        if(ans[n]==ans[b+1-n])
                        {
                            ans[n] = 1-ans[n];
                            ans[b+1-n] = 1-ans[b+1-n];
                        }
                    }
                }
            }
            if((first_diff_pair_location > -1)&& (queries_made%10 <= 1))
            {//some pairs were different, update those
                std::cout << first_diff_pair_location <<std::endl;
                int tmp;
                std::cin >> tmp;
                ++queries_made;
                if(tmp != ans[first_diff_pair_location])
                {//diff pairs changed, update them
                    for(int n=1;n<=known_bits/2;++n)
                    {
                        if(ans[n]!=ans[b+1-n])
                        {
                            ans[n] = 1-ans[n];
                            ans[b+1-n] = 1-ans[b+1-n];
                        }
                    }
                }
            }
            //update completed after quantum change
            //if 1 query used for that, waste 1 more query
            //because can only use 8 out of 9 ramaining
            //queries from this 10 (only pairs survive well)
            if(queries_made%10 == 1)
            {
                std::cout << 1 << std::endl;
                int trash;
                std::cin >> trash;
                ++queries_made;
            }
            //check next pair
            std::cout << known_bits/2+1 << std::endl;
            std::cin >> ans[known_bits/2+1];
            std::cout << b-known_bits/2 << std::endl;
            std::cin >> ans[b-known_bits/2];
            //see if it's the first same pair or first diff pair
            if(ans[known_bits/2+1]==ans[b-known_bits/2])
            {//same pair, see it it's the first one
                if(first_same_pair_location == -1)
                {
                    first_same_pair_location = known_bits/2+1;
                }
            }
            else
            {//diff pair, see if it's the first one
                if(first_diff_pair_location == -1)
                {
                    first_diff_pair_location = known_bits/2+1;
                }
            }
            ++known_bits;
            ++known_bits;
            ++queries_made;
            ++queries_made;
        }
    }
    return 0;
}