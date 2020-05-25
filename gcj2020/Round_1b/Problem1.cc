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
		    string path="";
			cout << "Case #" << case_num << ": ";
			int x,y;
			cin >>x>>y;
			bool poss=true;
			while(true)
			{
			    int sx=x%2,sy=y%2;
			    if(sx==-1)
			    {
			        sx=1;
			    }
			    if(sy==-1)
			    {
			        sy=1;
			    }
			    if(sx==sy && ((x!=0) || (y!=0)))
			    {
			        cout<<"IMPOSSIBLE";
			        poss=false;
			        break;
			    }
			    else if(x==0 && y==0)
			    {
			        //goal reached
			        break;
			    }
			    else if(x==0 && y==1)
			    {
			        path.append(1,'N');
			        break;
			    }
			    else if(x==0 && y==-1)
			    {
			        path.append(1,'S');
			        break;
			    }
			    else if(y==0 && x==1)
			    {
			        path.append(1,'E');
			        break;
			    }
			    else if(y==0 && x==-1)
			    {
			        path.append(1,'W');
			        break;
			    }
			    else if(sx==1)
			    {
			        //go we
			        y/=2;
			        sy=y%2;
			        sx=((x+1)/2)%2;
			        if(sx==-1)
			        {
			            sx=1;
			        }
			        if(sy==-1)
			        {
			            sy=1;
			        }
			        if(sx==sy)
			        {
			            //go e
			            path.append(1,'E');
			            --x;
			        }
			        else
			        {
			            path.append(1,'W');
			            ++x;
			        }
			        x/=2;
			    }
			    else
			    {
			        // go ns
			        x/=2;
			        sx=x%2;
			        sy=((y+1)/2)%2;
			        if(sx==-1)
			        {
			            sx=1;
			        }
			        if(sy==-1)
			        {
			            sy=1;
			        }
			        if(sy==sx)
			        {
			            //go n
			            path.append(1,'N');
			            --y;
			        }
			        else
			        {
			            path.append(1,'S');
			            ++y;
			        }
			        y/=2;
			    }
			}
			if(poss)
			{
			    cout<<path;
			}
			cout << endl;
		}
	return 0;
}