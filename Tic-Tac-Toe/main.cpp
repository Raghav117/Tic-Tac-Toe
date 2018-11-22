#include<iostream>
using namespace std;



void show(char s[]);                                 // To Show Tic-Tac-Toe box

void input(char s[],int p[],int a[],int x,int i);    // For taking input from player

void sort(int p[],int a[],int l,int k);              // Sorting player input in ascending order     

void check(int p[],int x);                           // To check weather player win or not

int main()
{
    char s[9];
    int  p1[3],p2[3],a[9];
    int i=0,j=0,k,c;
    
    for(i=0;i<9;++i)
        a[i]=i+1;

    for(i=0;i<9;++i)            //Tic Tac box
        s[i]=i+49;
    
    show(s);                    //For Showing Tic Tac box
    
    for(i=0;i<3;++i)
    {
        input(s,p1,a,0,i);      //For taking input from player 1
        
        if(i==2)
            check(p1,0);        //For checking weather player 1 wins or not
        
        
        input(s,p2,a,1,i);      //For taking input from player 2
        
        if(i==2)
            check(p2,1);        //For checking weather player 2  wins or not
    }
    
    cout<<"Game draws !!!";
    
    return 0;
}

void show(char s[])                             //For showing Tic-Tac box
{
    cout<<"\n\n\n";
    int i;
    for(i=0;i<9;++i)
    {
        cout<<s[i]<<" ";
        if((i+1)%3==0)
            cout<<"\n";
    }
}

void input(char s[],int p[],int a[],int x,int i)        //For taking input
{
    int k,c;
    
    jump:
    cin>>k;
    c=1;
    if(1<=k && k<=9)
    {
        if(s[k-1]==k+48)
        {
            if(x)
                s[k-1]='0';
            else
                s[k-1]='X';
            if(!i)
            {
                p[i]=a[k-1];
            }
            else
                sort(p,a,i,k);                  //Sorting the user input in ascending order
            
            c=0;
        }
    }
    if(c)
    {
        cout<<"Please re-enter again \n";
        goto jump;
    }
    else
        show(s);                              //Showing Tic-Tac box after taking input from user   
}
   


void sort(int p[],int a[],int l,int k)      // Sorting Tic-Tac box
{
    int i=l;
    while(l)
    {
        if(p[l-1]>a[k-1])
            p[l]=p[l-1];
        else
            break;
        --l;
    }
    p[l]=a[k-1];

}



void check(int p[],int x)        // Check weather payer wins or not
{
    int c;
        c=p[1]-p[0];
        if(c==1 || c==3 || c==4)
        {
            if(c==(p[2]-p[1]))
            {
                if(x)
                    cout<<"Yeah ! Player 2 wins the match. ";
                else
                    cout<<"Yeah ! Player 1 wins the match. ";
                    
                exit(0);
            }
        }
}
