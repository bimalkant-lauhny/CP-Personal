#include <bits/stdc++.h>
using namespace std;

int main(){
//    ios_base::sync_with_stdio(false);
 //   cin.tie(NULL);

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        int chapters[n];
        scanf("%d", &chapters[0]);

        int max_chapter = chapters[0];
        int ordered_chapters = 0;
        int sum_chapters = chapters[0];

        for (int i=1; i<n; ++i) {
            scanf("%d", &chapters[i]);

            sum_chapters += chapters[i];

            if (chapters[i] > max_chapter)
                max_chapter = chapters[i];

            if (chapters[i-1] + 1 == chapters[i])
                ++ordered_chapters;
        }

        if (sum_chapters == ((max_chapter * (max_chapter + 1)) / 2)
            && ordered_chapters != (n-1))
            printf("yes\n");
        else 
            printf("no\n");
    }

    return 0;
}
