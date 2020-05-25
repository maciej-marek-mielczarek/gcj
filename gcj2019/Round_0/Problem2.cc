#include<iostream>
#include<string>
#include<vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
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
        int maze_size = 0;
        std::getline(cin, tmp);
        for(char digit : tmp)
        {
            if(digit >= '0' && digit <= '9')
            {
                maze_size *= 10;
                maze_size += (digit - '0');
            }
        }
        int n_steps = 2 * maze_size - 2;
        string input{}, output{};
        std::getline(cin, input);
        cout << "Case #" << test_case << ": ";
        if((input[0] == 'E' || input[0] == 'e')&& (input[n_steps - 1] == 'S' || input[n_steps - 1] == 's'))
        {
            output.append(maze_size - 1, 'S');
            output.append(maze_size - 1, 'E');
        }
        else if((input[0] == 'S' || input[0] == 's')&& (input[n_steps - 1] == 'E' || input[n_steps - 1] == 'e'))
        {
            output.append(maze_size - 1, 'E');
            output.append(maze_size - 1, 'S');
        }
        else if(input[0] == 'S' || input[0] == 's')
        {
            int Es_until_first_EE = -1;
            char last_step = 'S';
            for(char step:input)
            {
                if(step == 'E' && last_step == 'E')
                {
                    break;
                }
                if(step == 'E')
                {
                    ++Es_until_first_EE;
                }
                last_step = step;
            }
            output.append(Es_until_first_EE + 1, 'E');
            output.append(maze_size - 1, 'S');
            output.append(maze_size - Es_until_first_EE - 2, 'E');
        }
        else
        {
            int Ss_until_first_SS = -1;
            char last_step = 'E';
            for(char step:input)
            {
                if(step == 'S' && last_step == 'S')
                {
                    break;
                }
                if(step == 'S')
                {
                    ++Ss_until_first_SS;
                }
                last_step = step;
            }
            output.append(Ss_until_first_SS + 1, 'S');
            output.append(maze_size - 1, 'E');
            output.append(maze_size - Ss_until_first_SS - 2, 'S');
        }
        cout << output << '\n';
    }
    return 0;
}
