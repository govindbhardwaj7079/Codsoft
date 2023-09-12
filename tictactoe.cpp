#include<iostream>
using namespace std;
 
char space[3][3]={{ '1', '2', '3'}, { '4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token= 'X';
bool tie=false;
string n1="";
string n2="";
void functionOne(){


cout<<"    |    |    "<<endl;
cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"  | "<<space[0][2]<<endl;
cout<<"____|____|____"<<endl;
cout<<"    |    |    "<<endl;
cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"  | "<<space[1][2]<<endl;
cout<<"____|____|____"<<endl;
cout<<"    |    |    "<<endl;
cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"  | "<<space[2][2]<<endl;
cout<<"    |    |    "<<endl;

}

void functionTwo(){
  int digit;
  
  if(token=='X')
  {
    cout<<n1<<"please enter";
    cin>>digit;
  }
  
  if(token=='0')
  {
    cout<<n2<<"please enter";
    cin>>digit;
  }

  if(digit==1)
  {
    row=0;
    column=0;
  }

   if(digit==2)
  {
    row=0;
    column=1;
  }

   if(digit==3)
  {
    row=0;
    column=2;
  }
   if(digit==4)
  {
    row=1;
    column=0;
  }
   if(digit==5)
  {
    row=1;
    column=1;
  }
   if(digit==6)
  {
    row=1;
    column=2;
  }
   if(digit==7)
  {
    row=2;
    column=0;
  }
   if(digit==8)
  {
    row=2;
    column=1;
  }
   if(digit==9)
  {
    row=2;
    column=2;
  }
  else if(digit<1 || digit>9){
    cout<<"invalid !!!"<<endl;
  }

  if(token== 'X' && space[row][column] !='X' && space[row][column] !='0')
{
  space[row][column]='X';
  token='0';

}
else if(token== '0' && space[row][column] !='X' && space[row][column] !='0')
{
    space[row][column]='0';
    token='X';

}
else{
    cout<<"there is no empty space"<<endl;
    functionTwo();
}
    functionOne();
}
bool functionthree()
{
    for(int i=0; i<3; i++)
    {
       if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]) 
       return true;
    }
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    {
        return true;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0;j<3; j++)
        {
          if(space[i][j] != 'X' && space[i][j] != '0')
          {
            return false;
          }  
        }
    }
    tie=true;
    return false;
}

int main(){
 cout<<"enter the name of first first player :"<<endl;
getline(cin, n1);
cout<<"enter the name of the second player :"<<endl;
getline(cin, n2);
cout<<n1<<" is player1 so he will play first "<<endl;
cout<<n2<<" is player2 so he will play second"<<endl;

    while(!functionthree())
    {
        functionOne();
        functionTwo();
        functionthree();

    }
    if(token =='X' && tie == false)
    {
        cout<<n1<<"wins!!"<<endl;
    }
    else if(token =='0' && tie == false)
    {
        cout<<n2<<"wins!!"<<endl;
    }
    else{
        cout<<" its is draw!"<<endl;
    }
}