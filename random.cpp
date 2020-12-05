#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <time.h>

#include <unistd.h>

using namespace std;

const int num = 1e5;
int main(int argc, char* argv[])
{
    char outfile[30] = "./input/test";
    char out[10] = ".in";
//   strcat(infile, argv[1]);
    strcat(outfile, argv[1]);
    strcat(outfile, out);
//    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    srand((unsigned int)time(NULL));
    int n = 1 + rand() % num;
    printf("%d\n", n);
    for(int i = 1;i <= n;i++)
    {
        int x1 = 1 + rand() % 13, x2 = 1 + rand() % 13, x3 = 1 + rand() % 13, x4 = 1 + rand() % 13;
        printf("%d %d %d %d\n", x1, x2, x3, x4);
    }
    sleep(1);
}