#include <iostream>
#include <string>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::set;

int main()
{
	int t;
	cin >> t;
	for(int case_num = 1; case_num <= t; ++case_num)
		{
			cout << "Case #" << case_num << ": ";
			int u;
			cin>>u;
			char mapping_possibilities[10][10];
			//digit position, possibility number
			for(int i=0;i<10;++i)
			{
			    for(int j=0;j<10;++j)
			    {
			        mapping_possibilities[i][j]='0';
			    }
			}
			set<char> seen_digits;
			int n_seen_digits=0;
			for(int ii=0;ii<10000;++ii)
			{
			    int q;
			    cin>>q;
			    string r;
			    cin>>r;
			    if(seen_digits.size()<10)
			    {
			        for(char digit:r)
			        {
			            if(seen_digits.find(digit)==seen_digits.end())
			            {
			                seen_digits.insert(digit);
			                for(int i=0;i<10;++i)
			                {
			                    mapping_possibilities[i][n_seen_digits]=digit;
			                }
			                ++n_seen_digits;
			            }
			        }
			    }
			    //rule out possibilities
			    if(q<10)
			    {//r is one digit, not a 0, r<=q
			        for(int i=0;i<10;++i)
			        {//r is not 0
			            if(mapping_possibilities[0][i]==r[0])
			            {
			                mapping_possibilities[0][i]='0';
			            }
			        }
			        for(int i=0;i<=10;++i)
			        {//r is not >q
			            for(int j=q+1;j<=9;++j)
			            {
			                if(mapping_possibilities[j][i]==r[0])
			                {
			                    mapping_possibilities[j][i]='0';
			                }
			            }
			        }
			    }
			}
			int guessed_digits=0;
			for(int k=0;k<=20;++k)
			{
			for(int i=0;i<=9;++i)
			{//look for digits with only 1 possibility
			    int poss=0,position;
			    for(int j=0;j<=9;++j)
			    {
			        if(mapping_possibilities[i][j]!='0')
			        {
			            ++poss;
			            position=j;
			        }
			    }
			    if(poss==1)
			    {
			        for(int j=0;j<=9;++j)
			        {
			            if(j!=i)
			            mapping_possibilities[j][position]='0';
			        }
			    }
			}}
			string ans;
			for(int i=0;i<=9;++i)
			{
			    for(int j=0;j<=9;++j)
			    {
			        if(mapping_possibilities[i][j]!='0')
			        {
			            ans.push_back(mapping_possibilities[i][j]);
			        }
			    }
			}
			cout<<ans;
			cout << endl;
		}
	return 0;
}