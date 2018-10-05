void bubble sort(int a[],int n)
{
  int i,j,temp=0;  
  for(i=0;i<n;i++)
  {
   for(j=i;j<n-i;j++)
   {
     if(a[j]>a[j+1])
     {
       temp = a[j];
       a[j] = a[j+1];
       a[j+1] = temp;
     }
   }
  } 
}
       
