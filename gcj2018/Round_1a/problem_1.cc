#include<iostream>
//#include<string>
//#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    bool debug_var=true;
    //remember^^
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    int n_rows, n_cols, n_row_cuts, n_col_cuts;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int n_chips = 0;
        cin >> n_rows >> n_cols >> n_row_cuts >> n_col_cuts;
        bool chips[100][100];
        int chips_in_portion[100][100]={};
        int row_cuts[100], col_cuts[100];//0 - cut after 1st row/col
        int row_chips[100]={0}, col_chips[100]={0};
        char one_chip;
        int row=0, col=0;
        for(row=0; row<n_rows; ++row)
        {
            for(col=0; col<n_cols; ++col)
            {
                cin >> one_chip;
                chips[row][col] = (one_chip == '@');
                if(one_chip=='@')
                {
                    ++n_chips;
                    ++row_chips[row];
                    ++col_chips[col];
                }
            }
        }
        if(debug_var)
            {
                for(int n=0;n<n_rows;++n)
                    cerr<<"row_chips["<<n<<"]="<<row_chips[n]<<endl;
                for(int k=0;k<n_cols;++k)
                    cerr<<"col_chips["<<k<<"]="<<col_chips[k]<<endl;
            }
        cout << "Case #" << test_case << ": ";
        //make row and col cuts independently, then check if its a good cut
        if(n_chips == 0)
        {//no chips no fun
            cout << "POSSIBLE" <<endl;
            if(debug_var)
            {
                cerr <<"pos1"<<endl;
            }
            continue;
        }
        if((n_chips%((n_row_cuts+1)*(n_col_cuts+1)))!=0)
        {
            //case impossible
            cout << "IMPOSSIBLE" <<endl;
            if(debug_var)
            {
                cerr<<"imp1"<<endl;
            }

            continue;
        }
        int target_row_chips=(n_chips/(n_row_cuts+1)), target_col_chips = (n_chips/(n_col_cuts+1));
        int target_portion_chips=(n_chips/((n_row_cuts+1)*(n_col_cuts+1)));
        row=0;
        col=0;
        int aggregate_chips = 0;
        bool answer = true;
        for(int row_cuts_done=0; row_cuts_done<n_row_cuts;++row)
        {
            aggregate_chips += row_chips[row];
            if(aggregate_chips > target_row_chips)
            {
                cout << "IMPOSSIBLE" <<endl;
                if(debug_var)
                {
                    cerr<<"imp2"<<endl;
                }
                answer = false;
                break;
            }
            if(aggregate_chips == target_row_chips)
            {
                //make a cut here
                row_cuts[row_cuts_done] = row;
                ++row_cuts_done;
                aggregate_chips=0;
            }
        }
        if(!answer)
        {
            continue;
        }
        for(int col_cuts_done=0; col_cuts_done<n_col_cuts;++col)
        {
            aggregate_chips += col_chips[col];
            if(aggregate_chips > target_col_chips)
            {
                cout << "IMPOSSIBLE" <<endl;
                if(debug_var)
                {
                    cerr<<"imp3"<<endl;
                }
                answer = false;
                break;
            }
            if(aggregate_chips == target_col_chips)
            {
                //make a cut here
                col_cuts[col_cuts_done] = col;
                if(debug_var)
                {
                    cerr<<"row_cuts["<<col_cuts_done<<"]="<<col<<endl;
                }
                ++col_cuts_done;
                aggregate_chips=0;
            }
        }
        if(!answer)
        {
            continue;
        }
        //done cutting. check if its a solution
        //count chips in each portion
        row=0;
        col=0;
        int row_cut=0, col_cut=0;
        for(row=0; row<n_rows; ++row)
        {
            col_cut=0;
            for(col=0; col<n_cols; ++col)
            {
                if(chips[row][col])
                {
                    ++(chips_in_portion[col_cut][row_cut]);
                }
                if(col==col_cuts[col_cut])
                {
                    ++col_cut;
                }
            }
            if(row==row_cuts[row_cut])
            {
                ++row_cut;
            }
        }
        answer=true;
        for(row_cut=0;row_cut<=n_row_cuts;++row_cut)
        {
            for(col_cut=0;col_cut<=n_col_cuts;++col_cut)
            {
                if(debug_var)
                    {
                        cerr<<"chips in portion ["<<row_cut<<", "<<col_cut<<"]=";
                        cerr<<chips_in_portion[row_cut][col_cut]<<endl;
                    }
                if((chips_in_portion[row_cut][col_cut])!=target_portion_chips)
                {
                    answer=false;

                }
            }
        }
        if(answer)
        {
            cout << "POSSIBLE" <<endl;
            if(debug_var)
            {
                cerr<<"pos2"<<endl;
            }
        }
        else
        {
            cout <<"IMPOSSIBLE" <<endl;
            if(debug_var)
            {
                cerr<<"imp4"<<endl;
            }
        }


    }
    return 0;
}
