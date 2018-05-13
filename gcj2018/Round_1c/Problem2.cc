#include<iostream>
#include<string>
#include<vector>
#include<set>
//#include<map>
//#include<random>

using std::cin;
using std::cout;
using std::endl;
using std::set;
using std::multiset;
//using std::map;

int main()
{
    //std::default_random_engine generator;
    //std::uniform_int_distribution<int> distribution(1,6);
//int dice_roll = distribution(generator);
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        unsigned n_customers;
        cin >> n_customers;
        set<int> used_flavours={};
        multiset<int> pref_counts={};
        for(unsigned customer_id=1;customer_id<=n_customers;++customer_id)
        {
            unsigned n_preferences;
            cin >> n_preferences;
            int preference=-1;
            int flavor_to_sell=-1;
            //bool lolipop_sold=false;
            //map<int,int> candidates_to_sell={};
            int candidate_to_sell=-1;
            unsigned candidate_popularity=999999;
            for(unsigned preference_id=1;preference_id<=n_preferences;++preference_id)
            {
                cin>>preference;
                pref_counts.insert(preference);
                //if(!lolipop_sold)
                  //  {
                    if(used_flavours.count(preference)==0)
                        {
                        if(pref_counts.count(preference)<candidate_popularity)
                        {
                            candidate_to_sell=preference;
                            candidate_popularity=pref_counts.count(preference);//forgot this line during contest
                        }
                        //flavor_to_sell=preference;
                        //used_flavours.insert(preference);
                        //lolipop_sold=true;
                        }
                    //}
            }
if(candidate_to_sell>-1)
{
    flavor_to_sell=candidate_to_sell;
    used_flavours.insert(candidate_to_sell);
}
            cout<<flavor_to_sell<<endl;
        }
        //cout << "Case #" << test_case << ":";
    }
    return 0;
}
