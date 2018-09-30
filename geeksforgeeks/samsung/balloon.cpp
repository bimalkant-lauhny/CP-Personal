
#include <iostream> 
using namespace std; 

int dp[100][100];
int getmaxscore(int arr[], int l, int r, int n) 
{ 
    if (l > r)
      return 0;
    if (dp[l][r] != -1)
      return dp[l][r];
    int mscore = 0; 
    for (int i = l; i <= r; i++) { 
        int cs = getmaxscore(arr, l, i-1, n) + getmaxscore(arr, i+1, r, n); 
        if (l == 0 && r == n) {
            cs += arr[i]; 
        } else {
            int left = 1;
            if (l-1 >= 0)
              left = arr[l-1];
            int right = 1;
            if (r+1 <= n)
              right = arr[r+1];
            cs += (left * right); 
        }
        if (cs > mscore) 
            mscore = cs; 
    }

 //printf("(%d, %d)->%d\n", l, r, mscore);
    dp[l][r] = mscore;
    return dp[l][r]; 
} 
  
int main() // driver function 
{ 
    int n = 10; // no of balloons 
    for (int i=0; i<100; ++i) {
      for(int j=0; j<100; ++j) {
        dp[i][j] = -1;
      }
    } 
    // assigning scores to each balloon 1-based indexing 
    // arr[0]=1 because to calculate score when no  
    //             balloons are left after popping 
    // arr[5]=1 because to calculate score when no 
    //             balloons are left after popping 
    // scores of balloons are assigned from 1 to 4 i.e 1 to n 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  
    /* for input input arr[n+2],  
      arr[0]=1 && arr[n+1]=1 
      cin>>n; 
      for(int i=1;i<=n;i++) 
         cin>>arr[i]; */
  
    cout << getmaxscore(arr, 0, n - 1, n - 1) << "\n"; 
  
    for (int i=0; i<n; ++i) {
      for(int j=0; j<n; ++j) {
        cout << dp[i][j] << "\t";
      }
      cout << endl;
    } 
    return 0; 
} 

