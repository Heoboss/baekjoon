#include <iostream>
using namespace std;
 
double fac(int n)
{
    double f = 1;
    for (double i = 2; i <= n; i++)
        f *= i;
    return f;
}
int main() {
    double ans = 1;
 
    cout << "n e\n" << "- -----------" << '\n' << "0 1\n";
    for (int i = 1; i <= 9; i++)
    {
        cout << i << ' ';
        ans += 1 / fac(i);
        if (i == 1) printf("%d\n",2);
        else if (i == 2) printf("2.5\n");
        else printf("%.9f\n", ans);
    }
}