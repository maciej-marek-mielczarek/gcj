#include <iostream>
#include <string>

int main()
{
    int t;
    std::cin >> t;
    for(int test_number=1; test_number<=t; ++test_number)
    {
        std::cout << "Case #" << test_number << ": ";
        //numbers of acivities starting at given times:
        int starts1[24*60+1], starts2[24*60+1];
        //numbers of acivities ending at given times:
        int ends1[24*60+1], ends2[24*60+1];
        // Note that if more than 2 activities
        // occur at the same time,
        // then the case is impossible.
        // So if more than 2 start or end at the same time,
        // then the case is aso impossible.
        for(int min = 0; min <= 24*60; ++min)
        {//-1 means 'no activity'
            starts1[min]=-1;
            starts2[min]=-1;
            ends1[min]=-1;
            ends2[min]=-1;
        }
        int n;//number of activities
        std::cin >> n;
        bool impossible = false;
        for(int activity_number = 0; activity_number < n; ++activity_number)
        {
            int start_time, end_time;
            std::cin >> start_time >> end_time;
            if(starts1[start_time]>=0)
            {//already 1 activity starting at this time
                if(starts2[start_time]>=0)
                {//already 2 activities starting at this time
                    //case impossible, but keep reading inputs
                    impossible = true;
                }
                else
                {
                    starts2[start_time] = activity_number;
                }
            }
            else
            {
                starts1[start_time] = activity_number;
            }
            if(ends1[end_time]>=0)
            {//already 1 activity ending at this time
                if(ends2[end_time]>=0)
                {//already 2 activities ending at this time
                    //case impossible, but keep reading inputs
                    impossible = true;
                }
                else
                {
                    ends2[end_time] = activity_number;
                }
            }
            else
            {
                ends1[end_time] = activity_number;
            }
        }
        if(impossible)
        {
            std::cout << "IMPOSSIBLE";
        }
        else
        {//no impossibility detected yet, carry on
            //number of acivity done by j and c:
        int j_busy = -1, c_busy = -1;//-1 means 'no activity'
        char ans[1000];
        for(int temp=0;temp<1000;++temp)
        {
            ans[temp]='\0';
        }
        for(int min = 0; min <= 24*60; ++min)
        {//assign new activities every minute
        //keep track of how who's busy
        //and what are they doing
        //
        //note that an activity might start on 1st list
        //and end on 2nd list and vice versa
            if(ends1[min]>=0)
            {//something from first list ends
                // free up whoever's doing that
                if(j_busy == ends1[min])
                {
                    j_busy = -1;
                }
                else
                {
                    c_busy = -1;
                }
            }
            if(ends2[min]>=0)
            {//something from second list ends
                // free up whoever's doing that
                if(j_busy == ends2[min])
                {
                    j_busy = -1;
                }
                else
                {
                    c_busy = -1;
                }
            }
            if(starts1[min]>=0)
            {//something from first list starts
            //assign it to someone
                if(j_busy == -1)
                {//j was free, so he gets the task
                    j_busy = starts1[min];
                    ans[j_busy] = 'J';
                }
                else if(c_busy == -1)
                {//c was free, so she gets the task
                    c_busy = starts1[min];
                    ans[c_busy] = 'C';
                }
                else
                {//both are busy, case impossible
                    std::cout << "IMPOSSIBLE";
                    impossible = true;
                    break;
                }
            }
            if(starts2[min]>=0)
            {//something from second list starts
                //assign it to someone
                if(j_busy == -1)
                {//j was free, so he gets the task
                    j_busy = starts2[min];
                    ans[j_busy] = 'J';
                }
                else if(c_busy == -1)
                {//c was free, so she gets the task
                    c_busy = starts2[min];
                    ans[c_busy] = 'C';
                }
                else
                {//both are busy, case impossible
                    std::cout << "IMPOSSIBLE";
                    impossible = true;
                    break;
                }
            }
        }
        if(!impossible)
        {//write the answer
            std::cout << ans;
        }
        }
        std::cout << "\n";
    }
    return 0;
}