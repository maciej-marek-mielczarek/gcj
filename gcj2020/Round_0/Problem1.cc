#include <iostream>

int main()
{
    int t;
    int mat[101][101];
    std::cin >> t;
    for(int test_number=1; test_number<=t; ++test_number)
    {
        std::cout << "Case #" << test_number << ": ";
        int n, trace=0, bad_rows=0, bad_cols=0;
        std::cin >> n;
        for(int row=1; row<=n; ++row)
        {
            for(int col=1; col<=n; ++col)
            {
                std::cin >> mat[row][col];
                if(row == col)
                {
                    trace += mat[row][col];
                }
            }
        }
        for(int row=1; row<=n; ++row)
        {
            bool used_numbers[101];
            for(int col = 1; col<=n; ++col)
            {
                used_numbers[col] = false;
            }
            for(int col = 1; col<=n; ++col)
            {
                int x = mat[row][col];
                if(used_numbers[x])
                {//already seen this number
                    ++bad_rows;
                    break;
                }
                else
                {
                    used_numbers[x] = true;
                }
            }
        }
        for(int col=1; col<=n; ++col)
        {
            bool used_numbers[101];
            for(int row = 1; row<=n; ++row)
            {
                used_numbers[row] = false;
            }
            for(int row = 1; row<=n; ++row)
            {
                int x = mat[row][col];
                if(used_numbers[x])
                {//already seen this number
                    ++bad_cols;
                    break;
                }
                else
                {
                    used_numbers[x] = true;
                }
            }
        }
        std::cout << trace << " ";
        std::cout << bad_rows << " ";
        std::cout << bad_cols << " ";
        std::cout << "\n";
    }
    return 0;
}