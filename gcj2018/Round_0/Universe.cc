//c++11
#include<iostream>
#include<string>
//#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
//using std::vector;

int main()
{
    int test_case = 1, n_test_cases;
    unsigned long long int shield_durability;
    string alien_program;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        cin >> shield_durability;
        cin >> alien_program;
        for(unsigned int k = 0; k < alien_program.length(); ++k)
        {
            if(alien_program[k] == 'C')
            {
                alien_program[k] = 'c';
            }
            if(alien_program[k] == 'S')
            {
                alien_program[k] = 's';
            }
        }
        cout << "Case #" << test_case << ": ";
        //if n_shots > shield_durability, the world ends
        unsigned int n_shots = 0, n_boosts = 0;
        unsigned long long int shot_damage = 1, total_damage = 0;
        int n_swaps = 0;
        for(unsigned int n = 0; n < alien_program.length(); ++n)
        {
            if(alien_program[n] == 's')
            {
                ++n_shots;
                total_damage += shot_damage;
            }
            else
            {
                ++n_boosts;
                shot_damage *= 2;
            }
        }
        if(n_shots > shield_durability)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if(shield_durability >= total_damage)
        {
            cout << 0 << endl;
            continue;
        }
        //ignore boosts (c) at the end, because
        //they don't do anything
        while(alien_program[alien_program.length()-1] == 'c')
        {
            alien_program.pop_back();
            --n_boosts;
            shot_damage /= 2;
        }
        unsigned int last_c;
        while(shield_durability < total_damage)
        {
            //swap the last 'c' with the 's' right after it
            last_c = alien_program.find_last_of('c');
            alien_program[last_c] = 's';
            alien_program[last_c + 1] = 'c';
            total_damage -= (shot_damage / 2);
            ++n_swaps;
            if(last_c+2 == alien_program.length())
            {
                //that 'c' just got moved to the end. remove it
                alien_program.pop_back();
                --n_boosts;
                shot_damage /= 2;
            }
        }
        cout << n_swaps;
        cout << endl;
    }
    return 0;
}
