void reverseArray(int arr[], int size){
  int start=0, end=size-1;
  while(start<end){
      temp=arr[start];
      arr[start]=arr[end];
      arr[end]=temp;
      start++;
      end--;
  }
}
    
