#include<iostream>
#include<string>
#include<vector>
#include<set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;

int main()
{
    int test_case = 1, n_test_cases;
    cin >> n_test_cases;
    for(;test_case <= n_test_cases; ++test_case)
    {
        unsigned n_words, word_length;
        cin >>n_words >> word_length;
        vector<string> old_words={};
        set<string> old_words_set={};
        for(unsigned n=0;n<n_words;++n)
        {
            string old_word;
            cin >> old_word;
            old_words.push_back(old_word);
            old_words_set.insert(old_word);
        }
        cout << "Case #" << test_case << ": ";
        if(word_length==1)
        {
            cout << "-"<<endl;
        }
        if(word_length==2)
        {
            string new_word="-";
            string new_word_candidate={};
            for(unsigned n=0;n<n_words;++n)
            {
                for(unsigned m=0;m<n_words;++m)
                {
                    new_word_candidate={};
                    new_word_candidate.append(1,old_words[n][0]);
                    new_word_candidate.append(1,old_words[m][1]);
                    //std::cerr <<"case"<<test_case<<new_word_candidate<<endl;
                    if(old_words_set.count(new_word_candidate)==0)
                    {
                        new_word=new_word_candidate;
                    }
                }
            }
            cout << new_word << endl;
        }
//string test="-";
//std::cerr<<test<<endl;

    }
    return 0;
}
