#include<iostream>
//#include<string>
//#include<vector>
#include<iomanip>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

int main()
{
    bool debug_var=false;
    cout.precision(10);
    cout << std::fixed;
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int n_cookies, t;
        cin>>n_cookies>>t;
        double target_sum=t;
        int wid, hei;
        //small-only
        for(int n=0; n<n_cookies;++n)
        {
            cin >>wid>>hei;
        }
        int tmp=wid;
        if(tmp>hei)
        {
            tmp=hei;
        }
        double tmp2=sqrt(wid*wid+hei*hei);
        double width=2*tmp,height=2*tmp2;
        double best_answer=(wid+hei)*2.0*n_cookies;
        double candidate_answer = best_answer;
        double start=best_answer;
        if(debug_var)
        {
            cerr <<"width = "<<width<<endl;
            cerr<<"height = "<<height<<endl;
            cerr<<"wid = "<<wid<<endl;
            cerr<<"hei = "<<hei<<endl;
            cerr<<"start = "<<start<<endl;
            cerr<<"n_cookies = "<<n_cookies<<endl;
            cerr<<"target_sum = "<<target_sum<<endl;
        }
        for(int n=0;n<=n_cookies;++n)
        {
            for(int n_cuts=0;n_cuts<=n;++n_cuts)
            {
                candidate_answer=start+n_cuts*width+(n-n_cuts)*height;
                if((candidate_answer>best_answer)& (candidate_answer<=target_sum))
                {
                    best_answer=candidate_answer;
                }
                if((n_cuts>0)&((candidate_answer+height-width)>target_sum)&(candidate_answer<=target_sum))
                {
                    best_answer=target_sum;
                }
                if(((n-n_cuts)>0)&((candidate_answer-height+width)>target_sum)&(candidate_answer<=target_sum))
                {
                    best_answer=target_sum;
                }
            }
        }
        cout << "Case #" << test_case << ": ";
        cout << best_answer<<endl;
    }
    return 0;
}
