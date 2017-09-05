#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string cur_time;
    cin >> cur_time;
    
    int hour = (cur_time[0] - '0') * 10 + (cur_time[1] - '0');
    int minute =  (cur_time[3] - '0') * 10 + (cur_time[4] - '0');
    if (hour >= 0 && hour <= 4) {
        int pal_minute = hour * 10;
        if (minute <= pal_minute)
            cout << pal_minute - minute << endl;
        else
            cout << (pal_minute + 10) + (60 - minute) << endl;
    } else if (hour == 5) {
        if (minute <= 50)
            cout << 50 - minute<< endl;
        else
            cout << 241 + (60 - minute) << endl;
    } else if (hour >= 6 && hour <= 9) {
        cout << (60 - minute) + ((10 - hour - 1)* 60) + 1 << endl;
    } else if (hour >= 10 && hour <= 14) {
        int pal_minute = ((hour - 10) * 10) + 1; 
        if (minute <= pal_minute)
            cout << pal_minute - minute << endl;
        else 
            cout << (pal_minute + 10) + (60 - minute) << endl;
    } else if (hour == 15) {
        if (minute <= 51) 
            cout << 51 - minute << endl;
        else 
            cout << 242 + (60 - minute) << endl;
    } else if (hour >= 16 && hour <= 19) {
        cout << (60 - minute) + ((20 - hour - 1)* 60) + 2 << endl;
    }  else if (hour >= 20 && hour <= 22) {
        int pal_minute = ((hour - 20) * 10) + 2; 
        if (minute <= pal_minute)
            cout << pal_minute - minute << endl;
        else 
            cout << (pal_minute + 10) + (60 - minute) << endl;
    } else {
        if (minute <= 32)
            cout << 32 - minute << endl;
        else
            cout << 60 - minute << endl;
    }
    return 0;
}
