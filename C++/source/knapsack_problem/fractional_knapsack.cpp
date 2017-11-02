/*
    Fractional Knapsack Problem
    ---------------------------
    This is a Greedy Algorithm which calculates the maximum
    profit which can be earned from a given set of unsorted
    objects with associated weight and profit.
    Class implementation using Selection sort
    for more simplicity.

    Time Complexity
    ---------------
    O(n^2), where n is the number of objects

    Space Complexity
    ----------------
    O(1)
*/


#include <iostream>

using namespace std;

class object {
    public:
        float weight;
        float profit;
        float p_w_ratio;

        void get_data()
        {
            cout<<"weight:";
            cin>>weight;
            cout<<"profit:";
            cin>>profit;
        }
        void calc_ratio ()
        {
            p_w_ratio = profit/weight;
            cout<<"ratio:"<<p_w_ratio;
            cout<<endl;
        }
}obj[50];

void swap_data(float *x, float *y)
{
float temp;
temp=*x;
*x=*y;
*y=temp;
}

int main()
{
    int n, i,j;
    float size_of_bag,total_profit;

    cout<<"Enter the maximum weight of the knapsack:";
    cin>>size_of_bag;
    cout<<"Enter the number of objects:";
    cin>>n;

    cout<<"Enter the value of weight and profit of each object\n";

    for(int i=0;i<n;i++)
    {
        cout<<"\nObject"<<i+1<<endl;
        obj[i].get_data();
        obj[i].calc_ratio();
    }

    int max,pos=0;

    while(pos<n)            /* Selection Sort  */
    {
        max = pos;
        j = pos+1;
        while(j < n)
            {
                if(obj[j].p_w_ratio > obj[max].p_w_ratio)
                    max = j;
                j++;
            }
        swap_data (&obj[pos].weight, &obj[max].weight);
        swap_data (&obj[pos].profit, &obj[max].profit);
        swap_data (&obj[pos].p_w_ratio, &obj[max].p_w_ratio);

        pos++;
    }

    for (i=0;i<n;i++)        /* Algo to calculate profit */
    {
        if(size_of_bag>0 && obj[i].weight<=size_of_bag)
        {
            size_of_bag = size_of_bag-obj[i].weight;
            total_profit = total_profit+obj[i].profit;
        }
        else
            break;
    }

    if(size_of_bag > 0)
    {
        total_profit = total_profit + (size_of_bag * obj[i].p_w_ratio);
    }

    cout<<"\n Total Profit that can be earned:"<<total_profit;

    return 0;
}

