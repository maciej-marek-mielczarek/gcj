#include<iostream>
//#include<string>
#include<vector>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::set;

//using std::cerr;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        vector<int> ns{}, ms{};
        int n_signs;
        cin >> n_signs;
        for(int s=0;s<n_signs;++s)
        {
            int distanse_to_town, a, b;
            cin >> distanse_to_town >> a >> b;
            int m = distanse_to_town+a;
            ms.push_back(m);
            int n = distanse_to_town-b;
            ns.push_back(n);
        }
        int longest_set_size = 0;
        int curr_set_size=0;
//        int first_bad_m, first_bad_n;
        //int n_best_sets=0;
        set<int> best_set_starts= {};
        int best_set_start_candidate=0;
        for(unsigned i=0;i<ns.size();++i)
        {
            for(unsigned j=0;j<ms.size();++j)
            {
                best_set_start_candidate=0;
                int n=ns[i], m=ms[j];
                curr_set_size=0;
                bool ended_in_1=false;
                for(unsigned k=0;k<ms.size();++k)
                {
                    //cerr<<"Case #"<<test_case<<", (i,j,n,m,k) = ("<<i<<", "<<j<<", "<<n<<", "<<m<<", "<<k<<")\n";
                    if((ns[k]==n)||(ms[k]==m))
                    {
                        if(curr_set_size==0)
                        {
                            best_set_start_candidate=k;
                        }
                        ++curr_set_size;
                        ended_in_1=true;
                        //
                    }
                    else
                    {
                        if(curr_set_size>longest_set_size)
                        {
                            longest_set_size=curr_set_size;
                            //n_best_sets=1;
                            best_set_starts.clear();
                            best_set_starts.insert(best_set_start_candidate);
                        }
                        if(curr_set_size==longest_set_size)
                        {
                            //++n_best_sets;
                            best_set_starts.insert(best_set_start_candidate);
                        }
                        curr_set_size=0;
                        ended_in_1=false;
                    }
                }
                //a
                if(ended_in_1)
                {
                    if(curr_set_size>longest_set_size)
                    {
                        longest_set_size=curr_set_size;
                        //n_best_sets=1;
                        best_set_starts.clear();
                        best_set_starts.insert(best_set_start_candidate);
                    }
                    if(curr_set_size==longest_set_size)
                    {
                        //++n_best_sets;
                        best_set_starts.insert(best_set_start_candidate);
                    }
                    curr_set_size=0;
                }
            }
        }
        /*
        int n=ns[0], m=ms[0];
        int n_best_sets=1;
        for(int s=1;s<n_signs;++s)
        {
            bool n_set_end=false,m_set_end=false;
            if(ns[s]==n)
            {
                //
            }
            else
            {
                n=ns[s];
                n_set_end=true;
            }
            if(ms[s]==m)
            {
                //
            }
            else
            {
                ms[s]=m;
                m_set_end=true;
            }
            if(m_set_end && n_set_end)
            {
                if(longest_set_size<curr_set_size)
                {
                    longest_set_size=curr_set_size;
                    n_best_sets=1;
                }
                if(longest_set_size==curr_set_size)
                {
                    ++n_best_sets;
                }
                curr_set_size=0;
                //
            }
            else
            {
                ++curr_set_size;
                //
            }
            //
        }
        */
        /*
        for(int s=0;s<n_signs;++s)
        {
            //
        }
        */
/*
int dupa2=1;
        for(auto dupa=best_set_starts.begin();dupa!=best_set_starts.end();++dupa,++dupa2)
        {
            cerr<<"Case #"<<test_case<<", element #"<<dupa2<<": "<<*dupa<<endl;
        }
        */

        cout << "Case #" << test_case << ": " << longest_set_size << " " << best_set_starts.size()<<endl;
    }
    return 0;
}
