#ifndef TIMER_H
#define TIMER_H
#include <bits/stdc++.h>

using namespace std;

struct Timer {
    Timer() = default;
    time_t preTime = 0;
    time_t preline = 0;
    int16_t cnt = 0;
    // how to use: timer->prepare(__LINE__);
    void prepare(int line) {
        cnt = 1;
        preline = line;
        preTime = clock();
    }
    // how to use: timer->getTimePass(__LINE__);
    void getTimePass(int line) {
        if (cnt != 1) {
            cerr << "line " << line << ": ";
            cerr << "Please call prepare() first!" << endl;
            return;
        }
        cout << "Time taken from line " + to_string(preline) + " to line " + to_string(line) + " is: ";
        auto tmp = clock() - preTime;
        cout << setprecision(3) << fixed << (1.0 * tmp / CLOCKS_PER_SEC) << endl;
        cnt = 0;
    }
};

#endif