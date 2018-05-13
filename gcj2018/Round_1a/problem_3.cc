#include<iostream>
//#include<string>
//#include<vector>
#include<iomanip>
#include<cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout.precision(10);
    cout << std::fixed;
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        int n_cookies, target_sum;
        cin>>n_cookies>>target_sum;
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
        double width=tmp,height=tmp2;
        double best_answer=(width+height)*2.0*n_cookies;
        double candidate_answer = best_answer;
        double start=best_answer;
        for(int n=0;n<n_cookies;++n)
        {
            for(int n_cuts=0;n_cuts<n;++n_cuts)
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
