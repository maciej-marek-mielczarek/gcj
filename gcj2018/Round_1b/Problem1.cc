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
    int n_people, n_langs;
    for(;test_case <= n_test_cases; ++test_case)
    {
        //ans=100+n_round_ups-n_round_downs
        cin >> n_people >> n_langs;
        vector<int> lang_counts(n_langs,0);
        int n_people_answered = 0;
        vector<int> round_ups_downs(n_langs,0);
        int n_round_ups=0, n_round_downs=0;
        vector<int> gains(n_langs,0);
        for(int lang=0; lang<n_langs; ++lang)
        {
            int tmp;
            cin >> tmp;
            lang_counts[lang]=tmp;
            n_people_answered += tmp;
            int nearest_half_percent_below_this_number = 200*tmp/n_people;
            int ppl_required_for_next_half_percent = (nearest_half_percent_below_this_number+1)*n_people/200;
            if(200*ppl_required_for_next_half_percent/n_people < (nearest_half_percent_below_this_number+1))
            {
                ++ppl_required_for_next_half_percent;
            }
            gains[lang] = ppl_required_for_next_half_percent-tmp;
            if((tmp*100)%n_people==0)
            {
                //no round
                continue;
            }

            if(((200*tmp)/n_people)%2==0)
            {
                //round down
                ++n_round_downs;
                round_ups_downs[lang] = -1;
            }
            else
            {
                //round up
                ++n_round_ups;
                round_ups_downs[lang] = 1;
            }
        }


        for(int remaining_people=n_people-n_people_answered; remaining_people>0;)
        {
            //get a round up using the least people possible
            //gain a round up from a new lang:
            int best_gain = n_people/200;
            if(best_gain*200/n_people<1)
            {
                ++best_gain;
            }
            int index_of_best_gain = -1;
            //try to gain a round up from existing lang
            for(unsigned lang = 0;lang<lang_counts.size();++lang)
            {
                if(gains[lang]<best_gain)
                {
                    best_gain = gains[lang];
                    index_of_best_gain = lang;
                }
                if(best_gain>remaining_people)
                {
                    break;
                }
                if(index_of_best_gain==-1)
                {
                    lang_counts.push_back(best_gain);
                    int nearest_half_percent_below_this_number = 0;
                    int ppl_required_for_next_half_percent = (nearest_half_percent_below_this_number+1)*n_people/200;
                    if(200*ppl_required_for_next_half_percent/n_people < (nearest_half_percent_below_this_number+1))
                    {
                        ++ppl_required_for_next_half_percent;
                    }
                    gains.push_back(ppl_required_for_next_half_percent-best_gain);
                    if((best_gain*100)%n_people==0)
                    {
                        round_ups_downs.push_back(0);
                        //no round
                    }
                    else
                    {

                        if(((200*best_gain)/n_people)%2==0)
                        {
                            //round down
                            ++n_round_downs;
                            round_ups_downs.push_back(-1);
                        }
                        else
                        {
                            //round up
                            ++n_round_ups;
                            round_ups_downs.push_back(1);
                        }
                    }

                }
                else
                {
                    lang_counts[index_of_best_gain] += best_gain;
                    int nearest_half_percent_below_this_number = 200*lang_counts[index_of_best_gain]/n_people;
                    int ppl_required_for_next_half_percent = (nearest_half_percent_below_this_number+1)*n_people/200;
                    if(200*ppl_required_for_next_half_percent/n_people < (nearest_half_percent_below_this_number+1))
                    {
                        ++ppl_required_for_next_half_percent;
                    }
                    gains[index_of_best_gain] = ppl_required_for_next_half_percent-lang_counts[index_of_best_gain];
                    int tmp2=round_ups_downs[index_of_best_gain];
                    if(tmp2<1)
                    {
                        ++round_ups_downs[index_of_best_gain];
                    }
                    if((lang_counts[index_of_best_gain]*100)%n_people==0)
                    {
                        round_ups_downs[index_of_best_gain]=0;
                        //no round
                    }
                    else
                    {

                        if(((200*lang_counts[index_of_best_gain])/n_people)%2==0)
                        {
                            //round down
                            ++n_round_downs;
                            round_ups_downs[index_of_best_gain]=-1;
                        }
                        else
                        {
                            //round up
                            ++n_round_ups;
                            round_ups_downs[index_of_best_gain]=1;
                        }
                    }
                }
                remaining_people -= best_gain;
                //
            }
        }
        int ans=0;
        for(unsigned k=0;k<lang_counts.size();++k)
        {
            ans+=100*lang_counts[k]/n_people;
        }
        cout << "Case #" << test_case << ": " << ans<<endl;
    }
    return 0;
}
