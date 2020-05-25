#include <iostream>
#include <string>

using std::string;

string mat4type1(int x, int y, int z, int w)
{
    string a(1,'0'+x), b(1,'0'+y),c(1,'0'+z),d(1,'0'+w);
    string ans = ""
    + a + " " + b + " " + d + " " + c + "\n"
    + b + " " + a + " " + c + " " + d + "\n"
    + d + " " + c + " " + a + " " + b + "\n"
    + c + " " + d + " " + b + " " + a + "\n";
    return ans;
}

string mat4type2(int x, int y, int z, int w)
{
    string a(1,'0'+x), b(1,'0'+y),c(1,'0'+z),d(1,'0'+w);
    string ans = ""
    + a + " " + b + " " + c + " " + d + "\n"
    + b + " " + a + " " + d + " " + c + "\n"
    + c + " " + d + " " + b + " " + a + "\n"
    + d + " " + c + " " + a + " " + b + "\n";
    return ans;
}

string mat4type3(int x, int y, int z, int w)
{
    string a(1,'0'+x), b(1,'0'+y),c(1,'0'+z),d(1,'0'+w);
    string ans = ""
    + a + " " + b + " " + c + " " + d + "\n"
    + c + " " + a + " " + d + " " + b + "\n"
    + d + " " + c + " " + b + " " + a + "\n"
    + b + " " + d + " " + a + " " + c + "\n";
    return ans;
}

string mat5type1(int x, int y, int z, int w, int q)
{
    string a(1,'0'+x), b(1,'0'+y),c(1,'0'+z),d(1,'0'+w),e(1,'0'+q);
    string ans = ""
    + a + " " + b + " " + c + " " + d + " " + e + "\n"
    + b + " " + a + " " + e + " " + c + " " + d + "\n"
    + e + " " + d + " " + a + " " + b + " " + c + "\n"
    + c + " " + e + " " + d + " " + a + " " + b + "\n"
    + d + " " + c + " " + b + " " + e + " " + a + "\n";
    return ans;
}

string mat5type2(int x, int y, int z, int w, int q)
{
    string a(1,'0'+x), b(1,'0'+y),c(1,'0'+z),d(1,'0'+w),e(1,'0'+q);
    string ans = ""
    + a + " " + b + " " + e + " " + c + " " + d + "\n"
    + c + " " + a + " " + b + " " + d + " " + e + "\n"
    + b + " " + d + " " + a + " " + e + " " + c + "\n"
    + d + " " + e + " " + c + " " + b + " " + a + "\n"
    + e + " " + c + " " + d + " " + a + " " + b + "\n";
    return ans;
}

int main()
{
    int t;
    std::cin >> t;
    for(int test_case = 1; test_case <= t; ++test_case)
    {
        int n,k;
        std::cin >> n >> k;
        std::cout << "Case #" << test_case << ": ";
        if( (k==n+1) || (k==n*n-1) || ( (n==3) && ((k==7)||(k==5)) ) )
        {
            std::cout << "IMPOSSIBLE\n";
        }
        else if(n<=5)
        {//smaller test set
        std::cout << "POSSIBLE\n";
            if(n==2)
            {
                if(k==2)
                {
                    std::cout << "1 2\n2 1\n";
                }
                else
                {
                    std::cout << "2 1\n1 2\n";
                }
            }
            else if(n==3)
            {
                if(k==3)
                {
                    std::cout << "1 2 3\n3 1 2\n2 3 1\n";
                }
                else if(k==6)
                {
                    std::cout << "2 1 3\n3 2 1\n1 3 2\n";
                }
                else
                {
                    std::cout << "3 1 2\n2 3 1\n1 2 3\n";
                }
            }
            else if(n==4)
            {
                if(k==4)
                {
                    std::cout << mat4type1(1,2,3,4);
                }
                else if(k==6)
                {
                    std::cout << mat4type2(1,2,3,4);
                }
                else if(k==7)
                {
                    std::cout << mat4type3(1,2,3,4);
                }
                else if(k==8)
                {
                    std::cout << mat4type3(1,2,4,3);
                }
                else if(k==9)
                {
                    std::cout << mat4type3(1,3,4,2);
                }
                else if(k==10)
                {
                    std::cout << mat4type2(3,2,1,4);
                }
                else if(k==11)
                {
                    std::cout << mat4type3(2,3,4,1);
                }
                else if(k==12)
                {
                    std::cout << mat4type3(3,2,4,1);
                }
                else if(k==13)
                {
                    std::cout << mat4type3(4,2,3,1);
                }
                else if(k==14)
                {
                    std::cout << mat4type2(3,4,1,2);
                }
                else
                {
                    std::cout << mat4type1(4,2,3,1);
                }
            }
            else
            {//n==5
                if(k==5)
                {
                    std::cout << mat5type1(1,2,3,4,5);
                }
                else if(k==7)
                {
                    std::cout << mat5type2(1,2,3,4,5);
                }
                else if(k==8)
                {
                    std::cout << mat5type2(2,1,3,4,5);
                }
                else if(k==9)
                {
                    std::cout << mat5type2(1,3,2,4,5);
                }
                else if(k==10)
                {
                    std::cout << mat5type1(2,1,3,4,5);
                }
                else if(k==11)
                {
                    std::cout << mat5type2(1,4,2,3,5);
                }
                else if(k==12)
                {
                    std::cout << mat5type2(2,3,1,4,5);
                }
                else if(k==13)
                {
                    std::cout << mat5type2(1,5,2,3,4);
                }
                else if(k==14)
                {
                    std::cout << mat5type2(2,4,1,3,5);
                }
                else if(k==15)
                {
                    std::cout << mat5type1(3,1,2,4,5);
                }
                else if(k==16)
                {
                    std::cout << mat5type2(2,5,1,3,4);
                }
                else if(k==17)
                {
                    std::cout << mat5type2(3,4,1,2,5);
                }
                else if(k==18)
                {
                    std::cout << mat5type2(4,3,1,2,5);
                }
                else if(k==19)
                {
                    std::cout << mat5type2(3,5,1,2,4);
                }
                else if(k==20)
                {
                    std::cout << mat5type1(4,1,2,3,5);
                }
                else if(k==21)
                {
                    std::cout << mat5type2(5,3,1,2,4);
                }
                else if(k==22)
                {
                    std::cout << mat5type2(4,5,1,2,3);
                }
                else if(k==23)
                {
                    std::cout << mat5type2(5,4,1,2,3);
                }
                else
                {
                    std::cout << mat5type1(5,1,2,3,4);
                }
            }
        }
        else
        {//bigger test set
            
        }
    }
    return 0;
}