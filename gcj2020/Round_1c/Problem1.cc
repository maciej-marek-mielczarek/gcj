#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	int t;
	cin >> t;
	for(int case_num = 1; case_num <= t; ++case_num)
		{
			cout << "Case #" << case_num << ": ";
			int x,y;
			cin>>x>>y;
			string cats_path;
			cin>>cats_path;
			int cats_pos_x=x,cats_pos_y=y;
			int best_x_pos,best_y_pos,best_time=-1;
			int n_steps=0;
			for(char c : cats_path)
			{
			    if(c=='N')
			    {
			        ++cats_pos_y;
			    }
			    else if(c=='S')
			    {
			        --cats_pos_y;
			    }
			    else if(c=='E')
			    {
			        ++cats_pos_x;
			    }
			    else
			    {
			        --cats_pos_x;
			    }
			    ++n_steps;
			    int cat_dist=0;
			    if(cats_pos_x>0)
			    {
			        cat_dist+=cats_pos_x;
			    }
			    else
			    {
			        cat_dist-=cats_pos_x;
			    }
			    if(cats_pos_y>0)
			    {
			        cat_dist+=cats_pos_y;
			    }
			    else
			    {
			        cat_dist-=cats_pos_y;
			    }
			    if(cat_dist<=n_steps)
			    {
			        best_x_pos=cats_pos_x;
			        best_y_pos=cats_pos_y;
			        best_time=n_steps;
			        break;
			    }
			}
			if(best_time==-1)
			{
			    cout<<"IMPOSSIBLE";
			}
			else
			{
			    cout << best_time;
			}
			cout << endl;
		}
	return 0;
}