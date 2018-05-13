#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        unsigned n_ants;
        cin >>n_ants;
        vector<int> ant_weights(n_ants,0);
        //vector<int> aggregate_weights(n_ants,0);
        int aggregate_weight=0;
        for(unsigned ant_id=0;ant_id<n_ants;++ant_id)
        {
            int tmp;
            cin >>tmp;
            ant_weights[n_ants-ant_id-1]=tmp;
            aggregate_weight+=tmp;
            //aggregate_weights[ant_id]=aggregate_weight;
        }
        unsigned carrying_potential=1000*aggregate_weight;
        int last_ant_id=-1;
        unsigned n_ants_in_stack=0;
        vector<int> possible_last_ant_ids={};

        possible_last_ant_ids.push_back(last_ant_id);
        vector<int> possible_carrying_potentials ={};

        possible_carrying_potentials.push_back(carrying_potential);
        for(;n_ants_in_stack<n_ants;)
        {
            vector<int> new_possible_last_ant_ids={};
            vector<int> new_possible_carrying_potentials ={};
            for(int n=0;n<possible_last_ant_ids.size();++n)
            {
                last_ant_id=possible_last_ant_ids[n];
                carrying_potential=possible_carrying_potentials[n];
            //choose another ant so that the new stack has the highest possible carrying potential
            unsigned best_candidate_id =0;
            int best_candidate_potential=-1;
            for(unsigned next_ant_candidate_id=last_ant_id+1;next_ant_candidate_id<n_ants;++next_ant_candidate_id)
            {
                int limit_a=carrying_potential-ant_weights[next_ant_candidate_id];
                int limit_b=6*ant_weights[next_ant_candidate_id];
                int candidate_potential=((limit_a>limit_b)?limit_b:limit_a);
                std::cerr<<"case "<<test_case<<"stack height: "<<n_ants_in_stack<<" candidate potential:"<<candidate_potential<<endl;
                if(candidate_potential>best_candidate_potential)
                {
                    best_candidate_potential=candidate_potential;
                    best_candidate_id=next_ant_candidate_id;
                }
            }
            if(best_candidate_potential>-1)
            {
                ++n_ants_in_stack;
                carrying_potential=best_candidate_potential;
                last_ant_id=best_candidate_id;
            }
            else
            {
                break;
            }
        }
        }
        cout << "Case #" << test_case << ": "<<n_ants_in_stack<<endl;
    }
    return 0;
}
