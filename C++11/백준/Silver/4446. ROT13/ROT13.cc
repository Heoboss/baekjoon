#include <iostream>
#include <string>
using namespace std;
int main() {
    string w;
    string com = "aiyeou";
    string com1 = "AIYEOU";
    string a = "bkxznhdcwgpvjqtsrlmf";
    string b = "BKXZNHDCWGPVJQTSRLMF";
    while (getline(cin, w))
    {
        for (int i = 0; i < w.size(); i++)
        {
            if (w[i] == 'a' || w[i] == 'i' || w[i] == 'y' || w[i] == 'e' || w[i] == 'o' || w[i] == 'u' || w[i] == 'A' || w[i] == 'I' || w[i] == 'Y' || w[i] == 'E' || w[i] == 'O' || w[i] == 'U')
            {
                for (int j = 0; j < 6; j++)
                {
                    if (w[i] == com[j])
                    {
                        if (j >= 3)
                            printf("%c", com[j - 3]);
                        else
                            printf("%c", com[j + 3]);
                    }
                    else if (w[i] == com1[j])
                    {
                        if (j >= 3)
                            printf("%c", com1[j - 3]);
                        else
                            printf("%c", com1[j + 3]);
                    }
                }
                continue;
            }
            else if (isalpha(w[i]) && w[i] != 'a' && w[i] != 'i' && w[i] != 'y' && w[i] != 'e' && w[i] != 'o' && w[i] != 'u' && w[i] != 'A' && w[i] != 'I'  &&  w[i] != 'Y' && w[i] != 'E' && w[i] != 'O' && w[i] != 'U')
            {
                for (int p = 0; p < a.size(); p++)
                {
                    if (w[i] == a[p])

                    {
                        if (p >= 10)
                            printf("%c", a[p - 10]);
                        else
                            printf("%c", a[p + a.size() - 10]);
                    }
                    else if (w[i] == b[p])
                    {
                        if (p >= 10)
                            printf("%c", b[p - 10]);
                        else
                            printf("%c", b[p + b.size() - 10]);
                    }
                }
            }
            else
                printf("%c", w[i]);
            
        }
        cout << '\n';
    }
}