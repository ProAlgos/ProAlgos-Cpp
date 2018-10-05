void selectionSort(int arr[], int n) 
{ 
    int i, j, min_idx; 
  
    // One by one move boundary of unsorted subarray 
    for (i = 0; i < n-1; i++) 
    { 
        // Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
            
          int temp =arr[min_idx]; 
          arr[min_idx] = arr[i]; 
         arr[i] = temp; 
    } 
} 
