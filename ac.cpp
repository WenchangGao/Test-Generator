#include<cstdio>
#include<iostream>
#include <cmath>
#include <cstring>

using namespace std;

unsigned long long int xx[1001];
int x=1;
int pd;
int f1(int a, int b, int c, int d)
{
    int x = 1;
	int sum;
	pd=0;
	char s1,s2,s3;
	for (int j = 1; j <= 4; j++)
	{
		for (int k = 1; k <= 4; k++)
		{
			for (int l = 1; l <= 4; l++)
			{
				sum = 0;
				sum += a;
				switch (j)
				{
				case 1:sum += b; break;
				case 2:sum -= b; break;
				case 3:sum *= b; break;
				case 4:
					{
						if (sum%b)
						{
							sum = 9999;
						}
						else
						{
							sum /= b;
						}
					}break;
				default:
					break;
				}
				switch (k)
				{
				case 1:sum += c; break;
				case 2:sum -= c; break;
				case 3:sum *= c; break;
				case 4:
					{
						if (sum%c)
						{
							sum = 9999;
						}
						else
						{
							sum /= c;
						}
					}break;
				default:
					break;
				}
				switch (l)
				{
				case 1:sum += d; break;
				case 2:sum -= d; break;
				case 3:sum *= d; break;
				case 4:
					{
						if (sum%d)
						{
							sum = 9999;
						}
						else
						{
							sum /= d;
						}
					}break;
				default:
					break;
				}
				if (sum == 24)
				{
					if (x==0)
					{
						xx[x]=a*1000000+b*100000+c*10000+d*1000+j*100+k*10+l;
						x++;
					}
					else
					{
						for (int i=1;i<=x;i++)
						{
							if ((a*1000000+b*100000+c*10000+d*1000+j*100+k*10+l)==xx[i])
							{
								pd=1;
								break;
							}
						}
						if (pd==0)
						{
							xx[x]=a*1000000+b*100000+c*10000+d*1000+j*100+k*10+l;
							x++;
						}
					}
					return 1;
				}
			}
		}
	}
	return 0;
}
int f2(int a, int b, int c, int d)
{
	int sum = 0;
	sum = f1(a, b, c, d) + f1(a, b, d, c) + f1(a, c, b, d) + f1(a, c, d, b) + f1(a, d, b, c) + f1(a, d, c, b);
	if (sum != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main(int argc, char* argv[])
{
    char infile[30] = "./input/test", outfile[30] = "./output/test";
    char in[10] = ".in", out[10] = ".out";
    strcat(infile,argv[1]);
    strcat(outfile,argv[1]);
    strcat(infile,in);
    strcat(outfile,out);
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
	    int a, b, c, d;
    	int sum;
	    cin >> a >> b >> c >> d;
    	sum = f2(a, b, c, d) + f2(b, a, c, d) + f2(c, a, b, d) + f2(d, a, b, c);
    	if (sum == 0)
    	{
    		cout << 'N' << endl;
	    }
        else
        {
            cout << 'Y' << endl;
        }
    }
    return 0;
}