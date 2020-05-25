#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int a;
        cin >> a;
        vector<string> b;//opponents' moves
        string c;
        vector<string> d(1,"");//my candidate programs
        vector<bool> tmp(a,false);
        vector<vector <bool> > beaten(1,tmp);// opponents beaten by my programs
        for(int i=0;i<a;++i)
        {//read ops moves
            cin >> c;
            b.push_back(c);
        }
//        bool winnable=true;
        bool won=false;
        string winning_combination;
        for(int i=0;i<=500;++i)
        {
//            char this_move1='q', this_move2='q';

            int n_candidates_sofar=d.size();
            for(int m=n_candidates_sofar-1;m>=0;--m)
            {//loop over candidate programs
                bool seenR=false, seenP=false, seenS=false;
                for(int j=0;j<a;++j)
                {
                    //loop over opponents
                    if(beaten[m][j])
                    {
                        //opp beaten, don't count him
                    }
                    else
                    {
                        if(b[j][i%((b[j]).length())]=='R')
                        seenR=true;
                        if(b[j][i%((b[j]).length())]=='P')
                        seenP=true;
                        if(b[j][i%((b[j]).length())]=='S')
                        seenS=true;
                    }
                }


            if(seenR)
            {
                if(seenP)
                {//R and P
                    if(seenS)
                    {
                        //this program can't win
                        //remove it
                        //try next
                        d.erase(d.begin()+m);
                        beaten.erase(beaten.begin()+m);
                        continue;
                    }
                    else
                    {//no S

                            d[m]+='P';
                            for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='R')
                                    beaten[m][j]=true;
                            }

                    }
                }
                else
                {//R, no P
                    if(seenS)
                    {//no P

                            d[m]+='R';
                            for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='S')
                                    beaten[m][j]=true;
                            }

                    }
                    else
                    {//only R

                            d.push_back(d[m]);
                            d[m]+='R';
                            d[d.size()-1]+='P';
                            beaten.push_back(beaten[m]);
                            for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='S')
                                    beaten[m][j]=true;
                                if(b[j][i%((b[j]).length())]=='R')
                                    beaten[beaten.size()-1][j]=true;
                            }

                    }
                }
            }
            else
            {//no R
                if(seenP)
                {
                    if(seenS)
                    {//P,S, no R


                            d[m]+='S';
                        for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='P')
                                    beaten[m][j]=true;
                            }
                    }
                    else
                    {//only P

                            d.push_back(d[m]);
                            d[m]+='S';
                            d[d.size()-1]+='P';
                            beaten.push_back(beaten[m]);
                            for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='P')
                                    beaten[m][j]=true;
                                if(b[j][i%((b[j]).length())]=='R')
                                    beaten[beaten.size()-1][j]=true;
                            }
                    }

                }
                else
                {
                    if(seenS)
                    {//only S

                            d.push_back(d[m]);
                            d[m]+='R';
                            d[d.size()-1]+='S';
                            beaten.push_back(beaten[m]);
                            for(int j=0;j<a;++j)
                            {//update beaten ops
                                if(b[j][i%((b[j]).length())]=='S')
                                    beaten[m][j]=true;
                                if(b[j][i%((b[j]).length())]=='P')
                                    beaten[beaten.size()-1][j]=true;
                            }
                    }
                    else
                    {
                        //win
                        won=true;
                        winning_combination=d[m];
                        break;
                    }
                }
            }
            }
        }

        cout << "Case #" << test_case << ": ";
        if(won)
        {
            cout << winning_combination<<endl;
        }
        else
        {
            cout << "IMPOSSIBLE"<<endl;
        }
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
