#include<iostream>
//#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    int useless_info;
    for(;test_case <= n_test_cases; ++test_case)
    {
        cin >> useless_info;
        int full_columns = 0;
        vector<bool> col1, col2, col3, col4;
        int ans_i, ans_j;
        for(int i=1; i<=3; ++i)
        {//just to be sure I don't screw up initialization
            col1.push_back(false);
            col2.push_back(false);
            col3.push_back(false);
            col4.push_back(false);
        }
        //cout << "Case #" << test_case << ":";
        bool wrong_answer = false;
        while(full_columns < 67)
        {
            if(full_columns < 5)
            {
                cout << 2 << " " << full_columns+2 << endl;
            }
            if((full_columns >= 5) & (full_columns < 7))
            {
                cout << 2 << " " << 6 << endl;
            }
            if((full_columns >= 7) & (full_columns < 65))
            {
                cout << 2 << " " << full_columns+2 << endl;
            }
            if((full_columns >= 65) & (full_columns < 67))
            {
                cout << 2 << " " << 66 << endl;
            }
            cin >> ans_i >> ans_j;
            if(ans_j == full_columns+1)
            {
                col1[ans_i-1] = true;
                for(int k = 1; k <= 3; ++k)
                {//check if col2 and col3 got filled earlier
                    if(col1[0] & col1[1] & col1[2])
                    {
                        ++full_columns;
                        col1 = col2;
                        col2 = col3;
                        col3 = col4;
                    }
                }
            }
            if(ans_j == full_columns+2)
            {
                col2[ans_i-1] = true;
            }
            if(ans_j > full_columns+2)
            {
                col3[ans_i-1] = true;
            }
            if(ans_j == 0)
            {
                break;
            }
            if(ans_j == -1)
            {
                wrong_answer = true;
                break;
            }
        }
        if(wrong_answer)
        {
            break;
        }
    }
    return 0;
}
