#include <bits/stdc++.h>
using namespace std;
int main() {
    int c;
    cin >> c;
    string input;
    cin >> input;
    string camel, snake, pascal;
    if (c == 1) {
        string camel, snake, pascal;
        camel = input;
        snake = "";
        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                snake += input[i];
            } else {
                snake += "_";
                char big = (input[i] + 32);
                snake += big;
            }
        }
        pascal = input;
        pascal[0] -= 32;
        cout << camel << '\n'
             << snake << '\n'
             << pascal;
    }
    if (c == 2) {
        bool big = false;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '_') {
                big = true;
                continue;
            } else if (big) {
                camel += (input[i] - 32);
                big = false;
            } else {
                camel += input[i];
            }
        }
        snake = input;
        pascal = camel;
        pascal[0] -= 32;
        cout << camel << '\n'
             << snake << '\n'
             << pascal;
    }
    if (c == 3) {
        camel = input;
        camel[0] += 32;
        snake = "";
        for (int i = 0; i < input.size(); i++) {
            if (i == 0) {
                snake += (input[i] + 32);

            } else if (input[i] >= 'a' && input[i] <= 'z') {
                snake += input[i];
            } else {
                snake += "_";
                char bg = (input[i] + 32);
                snake += bg;
            }
        }
        pascal = input;
        cout << camel << '\n'
             << snake << '\n'
             << pascal;
    }
}