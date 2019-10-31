///stack using Linked list
#include<iostream>
using namespace std;

class stackk
{
public:
    int data;
    stackk * next = NULL;
};

stackk *top = NULL;
void inserted(int data)
{

    if(top==NULL)
    {
        top = new stackk;
        top->data = data;
        top->next= NULL;
    }
    else{
            stackk* temp = top;
            top= new stackk;
            top->data= data;
            top->next= temp;

        }

}

void print()
{
    stackk * temp = top;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp= temp->next;
    }
}
int main()
{
    int b = NULL;

while(b!=-1)
{
if(b!=NULL)
    inserted(b);
cout<<" enter the elements of stack " ;
cin>>b;

}
cout<<" the elements of stack are "<<endl;
print();


}
