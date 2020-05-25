#include <iostream>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::multiset;

int main()
{
	int t;
	cin >> t;
	for(int case_num = 1; case_num <= t; ++case_num)
		{
			cout << "Case #" << case_num << ": ";
			int n,d;
			cin>>n>>d;
			multiset<long long> a;
			vector<long long> good_sizes;
			for(int i=0;i<n;++i)
			{
			    long long ai;
			    cin>>ai;
			    a.insert(ai);
			}
			long long ans=d-1;
			for(long long b:a)
			{
			    if(d==2)
			    {
			        if(a.count(b)>=2)
			        {
			            ans=0;
			            break;
			        }
			    }
			    if(d==3)
			    {
			        if(a.count(b)>=3)
			        {
			            ans=0;
			            break;
			        }
			        else if(ans==1)
			        {
			            continue;
			        }
			        else if(a.count(2*b)>=1)
			        {
			            ans=1;
			        }
			        else if(a.count(b)==2 && a.upper_bound(b)!=a.end())
			        {
			            ans=1;
			        }
			    }
			}
			cout <<ans;
			cout << endl;
		}
	return 0;
}