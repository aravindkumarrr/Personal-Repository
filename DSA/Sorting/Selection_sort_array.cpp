void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int k = i;
        int min = arr[i];
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                k=j;
            }
        }
        arr[k] = arr[i];
        arr[i] = min;
    }
}
