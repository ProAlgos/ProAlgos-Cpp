template <typename T>
T partition(T s,T e) 	// assuming pivot is the last element
{
    T temp = s, pivot = med_pivot(s,s + (e-s)/2,e-1);

    if(pivot != (e-1))  // replace pivot with the last element
        *pivot+=*(e-1),    *(e-1)=*pivot-*(e-1),     *pivot-=*(e-1),    pivot = e-1;

    for(T it=s;it!=e;it++) // make the elements smaller than pivot be at left of pivot and the larger be at right of pivot
        if(*it<*pivot)
        {
            if(temp != it)  *temp+=*it,    *it=*temp-*it,     *temp-=*it; // replace temp content with it content
            temp++;
        }
    if(temp != pivot)   *temp+=*pivot,    *pivot=*temp-*pivot,     *temp-=*pivot; // replace temp content with pivot content

    return temp;    // return pivot;
}

template <typename T>
void quick(T s,T e)
{
    if(e-s<2)   return; 	// there are less than two elements

    T q = partition(s,e);    	// split the array between larger pivot and smaller pivot
    quick(s,q);         	// call left sub_array for pivot
    quick(q+1,e);       	// call right sub_array for pivot
}
