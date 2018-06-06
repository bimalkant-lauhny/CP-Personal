#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string good;
    cin >> good;
    bool gdav[26];
    fill(gdav, gdav+26, false);
    for (int i=0; i<good.size(); ++i)
        gdav[good[i] - 'a'] = true;

    string pattern;
    cin >> pattern;
    int spos = -1;
    for (int i=0; i<pattern.size(); ++i)
        if (patter[i] == '*') {
            spos = i;
            break;
        } 
    int queries;
    cin >> queries;
    string qstr;
    while (queries--) {
        bool res = true;
        cin >> qstr;
        if (spos == -1) {
            for (int i=0; i<qstr.size(); ++i) {
                if (qstr[i] != pattern[i]) {
                    if (pattern[i] == '?') {
                        if (gdav[qstr[i] - 'a']) {
                            gdav[qstr[i] - 'a'] = false;
                        } else {
                            res = false;
                            break;
                        }
                    } else {
                        res = false;
                        break;
                    }
                }
            }
        } else {
            for (int i=0; i<spos; ++i) {
                if (qstr[i] != pattern[i]) {
                    if (pattern[i] == '?') {
                        if (gdav[qstr[i] - 'a']) {
                            gdav[qstr[i] - 'a'] = false;
                        } else {
                            res = false;
                            break;
                        }
                    } else {
                        res = false;
                        break;
                    }
                }
            }
            for (int i = pattern.size() - 1; i>spos; --i) {
                int qpos = i + (qstr.size() - pattern.size());
                if (qstr[i] != pattern[i]) {
                    if (pattern[i] == '?') {
                        if (gdav[qstr[i] - 'a']) {
                            gdav[qstr[i] - 'a'] = false;
                        } else {
                            res = false;
                            break;
                        }
                    } else {
                        res = false;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
