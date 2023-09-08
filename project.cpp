#include<bits/stdc++.h>
using namespace std;
int n;
int ar[10000];
ofstream file;
void create(int n,int ar[]);
void chose(int n,int ar[]);
void  insertt(int n,int ar[]);
void deletee(int n,int ar[]);
void searchh(int n,int ar[]);
void display(int n,int ar[]);
void exit();
void create(int n,int ar[])
{
    file.open("data.txt");
    file<<"Given Array "<<endl;
    for(int i=0; i<n; i++)
        file<<ar[i]<<" ";
    file<<endl;
    sort(ar,ar+n);
    file<<"After Sorted "<<endl;
    for(int i=0; i<n; i++)
        file<<ar[i]<<" ";
    file<<endl;
}
void chose(int n,int ar[])
{
    cout<<"What Do You Want To Do "<<endl;
    cout<<"1.Insert"<<endl;
    cout<<"2.Delete"<<endl;
    cout<<"3.Search"<<endl;
    cout<<"4.Dsply"<<endl;
    cout<<"5.Exit"<<endl;
    int cs;
    cin>>cs;
    if(cs==1)       insertt(n,ar);
    else if(cs==2)   deletee(n,ar);
    else if(cs==3)   searchh(n,ar);
    else if(cs==4)    display(n,ar);
    else if(cs==5)      exit();
}
void  insertt(int n,int ar[])
{
    cout<<"What Value Do You Want To Insert  ";
    int value,pos=n;
    cin>>value;
    for(int i=0; i<n; i++)
    {
        if(ar[i]==value || ar[i]>value )        //finding index
        {
            pos=i;
            break;
        }
    }
    cout<<"This  Value Need To Insert In Index    "<<pos<<endl;
    for(int i=n-1; i>=pos; i--)
    {
        if(i>=pos)
            ar[i+1]=ar[i];                   //insert
    }
    ar[pos]=value;              //pos e value ta insert
    n++;
    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";         //console e print
    cout<<endl;
    file<<"After Inserting "<<value<<endl;
    for(int i=0; i<n; i++)
        file<<ar[i]<<" ";             //file e print
    file<<endl;
    chose( n,ar);
}
void deletee(int n,int ar[])
{
    int value,pos=-1;
    cout<<"What Value Do You Want To Delete  ";
    cin>>value;
    for(int i=0; i<n; i++)
    {
        if(ar[i]==value)        //finding index
        {
            pos=i;
            break;
        }
    }
    if(pos==-1)
    {
        cout<<"Sorry You Have Input A Number Which Is Not In The Array ,Input A Correct Number"<<endl;
        deletee(n,ar);
    }
    else
    {
        cout<<"We Need To Delete  Index    "<<pos<<endl;
        for(int i=0; i<n; i++)
        {
            if(i>=pos)
                ar[i]=ar[i+1];
        }
        n--;
        cout<<"After Deleting ";
        for(int i=0; i<n; i++)
            cout<<ar[i]<<" ";         //console e print
        cout<<endl;
        file<<"After Deleting "<<value<<endl;
        for(int i=0; i<n; i++)
            file<<ar[i]<<" ";             //file e print
        file<<endl;
        chose(n,ar);
    }
}
void searchh(int n,int ar[])
{
    int l=0,r=n-1;
    int value,pos=-1;
    cout<<"What Value Do You Want To Search  ";
    cin>>value;
    int flag=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(ar[mid]>value)
            r=mid+1;
        else if(ar[mid]<value)  l=mid+1;
        else
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        for(int i=0; i<n; i++)
        {
            if(ar[i]==value)        //finding index
            {
                pos=i;
                break;
            }
        }
        cout<<"Found This Element In This  "<<pos<<" Index "<<endl;
        file<<"Searching "<<value<<" Element  And Found This Element In "<<pos<<" Index "<<endl;

    }
    else cout<<"Not Found This Element "<<endl;
    chose(n,ar);

}
void display(int n,int ar[])
{
    cout<<"Displaying The Array ";
    for(int i=0; i<n; i++)
        cout<<ar[i]<<" ";         //console e print
    cout<<endl;
    file<<"Displaying The Array ";
    for(int i=0; i<n; i++)
        file<<ar[i]<<" ";             //file e print
    file<<endl;
    chose(n,ar);
}
void exit()
{
    cout<<"THANK YOU"<<endl;
    file<<"THANK YOU"<<endl;

}
int main()
{
    cout<<"Enter Array Size :";
    cin>>n;
    cout<<"Input Array Element : ";
    for(int i=0; i<n; i++) cin>>ar[i];
    create(n,ar);
    chose(n,ar);
    return 0;
}
