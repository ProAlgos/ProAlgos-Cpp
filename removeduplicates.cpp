int length(char input[]){
  
  int x=0;
  for(int i=0; i<input[i]!='\0'; i++)
    x++;
  
  return x;
  
}

void removeConsecutiveDuplicates(char input[], int start){
  
  if(input[start]=='\0')
    return;
  
  removeConsecutiveDuplicates(input, start+1);
  
  if(input[start]==input[start+1]){
    
    int n=length(input);
    int i;
    for( i=start+1; i<n; i++){
      input[i-1]=input[i];
      
    }
    input[i-1]='\0';
    
  }
  
}

void removeConsecutiveDuplicates(char input[]) {
	removeConsecutiveDuplicates(input, 0);

}
