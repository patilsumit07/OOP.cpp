//EXP2_Salary
#include<iostream>
#include<string>

using namespace std;


class staff
{
private:
  int Staff_ID;
  string name;
  float Basic_Salary;
  float DA, HRA, Itax, NetSalary;
  
public:
  
  void accept()
  {
    cout<<"\nEnter staff ID : \t";
    cin>> Staff_ID;
    cout<<"\nEnter staff Name : \t";
    cin>> name;
    cout<<"\nEnter staff Salary : \t";
    cin>> Basic_Salary; 
  }//accept
  
  void calculate()
  {
    DA = Basic_Salary * 0.25 ;
    HRA = 800;
    Itax = Basic_Salary *0.15;
    NetSalary= Basic_Salary + DA + HRA -Itax;  
  }//calc
  
  void display()
  {
    cout<<"\n\n\nStaff ID \t"<< Staff_ID;
    cout<<"\nStaff Name \t"<< name;
    cout<<"\nBasic Salary \t"<< Basic_Salary;
    cout<<"\nDA(25%) \t"<< DA;
    cout<<"\nHRA \t"<< HRA;
    cout<<"\nIncome Tax\t"<< Itax;
    cout<<"\nNet Salary \t"<< NetSalary << endl;
    
  }//display
  
  string getName()
  {
    return name;
  } //name
  
}; // class staff

int main()
{ 
  int i,j,n;
  
  cout<<"Enter Number of staff you want to fill\t";
  cin >> n;
  staff s[n];
  
  for(i=0;i<n;i++)
  {
    cout<<"\nEnter staff Details of staff "<< i +1 << endl;
    s[i].accept();
    s[i].calculate();
  }//for loop Accept data
  
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(s[i].getName()>s[j].getName())
      {
        swap(s[i],s[j]);
      }
    }
  }//for loop sorting 
  
  cout<<"\n staff pay slip";
  
  for(i=0;i<n;i++)
  {
    s[i].display();
  }//for loop for display
  
  return 0;
  
  
}//main
