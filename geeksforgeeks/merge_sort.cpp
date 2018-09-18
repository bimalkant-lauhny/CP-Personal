// Merges two subarrays of arr[].  First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n = r - l + 1;
    int T[n];
    int i=l, j=m+1, k=0;
    while(i <= m && j <= r) {
        if (arr[i] <= arr[j])
            T[k++] = arr[i++];
        else
            T[k++] = arr[j++];
    }
    
    while(i <= m)
        T[k++] = arr[i++];
    
    while(j <= r)
        T[k++] = arr[j++];
    
    for(int i=l; i<=r; ++i)
        arr[i] = T[i-l];
}
