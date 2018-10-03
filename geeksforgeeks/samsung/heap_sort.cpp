void heapify(int arr[], int n, int i)  {
    // Your Code Here
    int l = 2*i+1, r = l+1, big = i;
    if (l < n && arr[l] > arr[i]) {
        big = l; 
    }
    if (r < n && arr[r] > arr[big]) {
        big = r;
    }
    swap(arr[i], arr[big]);
    if(big != i) {
        heapify(arr, n, big);
    }
}
// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  { 
    // Your Code Here
    for (int i=n/2-1; i>=0; --i) {
        heapify(arr, n, i);
    }
}
