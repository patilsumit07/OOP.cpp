#include<iostream>
using namespace std;
//----Base class 1-----
class Student
{
    protected:
    int rollNo;

    public:
    Student()
    {
        rollNo = 0;
        cout<<"Student Default Constructor Called"<<endl;
    }

    Student(int r)
    {
        rollNo = r;
        cout<<"Student Paraameterized Constructor Called"<<endl;

     }

     Student(const Student& s)
     {
        rollNo = s.rollNo;
        cout<<"Student Copy Constructor Called"<<endl;

     }

     ~Student()
     {
        cout<<"Student Destructor Called"<<endl;

     }
    
};

//----Base class 2----
class Sports
{
    protected:
    int sportsMarks;

    public:
    Sports()
    {
       sportsMarks = 0;
       cout<<"Sports Default Constructor Called"<<endl; 
    }

    Sports(int m)
    {
        sportsMarks = m;
        cout<<"Sports Paraameterized Constructor Called"<<endl;

     }

     Sports(const Sports& s)
     {
        sportsMarks = s.sportsMarks;
        cout<<"Sports Copy Constructor Called"<<endl;

     }

     ~Sports()
     {
        cout<<"Sports Destructor Called"<<endl;

     }
};

//----Derived Class---
class Result : public Student,public Sports{
    private:
    int totalMarks;

    public:
    Result() : Student(),Sports()
    {
       totalMarks = 0;
       cout<<"Sports Default Constructor Called"<<endl; 
    }

    Result(int r,int m,int t) : Student(r),Sports(m)
    {
        totalMarks = t;
        cout<<"Student Paraameterized Constructor Called"<<endl;

     }

    Result(const Result& obj) : Student(obj),Sports(obj)
     {
        totalMarks = obj.totalMarks;
        cout<<"Student Copy Constructor Called"<<endl;

     }

    void display()
    {
        cout<<"\nRoll No :"<<rollNo;
        cout<<"\nSports Marks :"<<sportsMarks;
        cout<<"\nTotal Marks :"<<totalMarks<<endl;
    }
    ~Result()
    {
        cout<<"Result Destructor Called"<<endl;
    }
};

//-----Main Function------
int main()
{
    cout<<"\n********** Default Constructor **********\n";
    Result r1;
    r1.display();

    cout<<"\n********** Parameterized Constructor **********\n";
    Result r2(101,25,450);
    r2.display();

    cout<<"\n********** Copy Constructor **********\n";
    Result r3(r2);
    r3.display();

    cout<<"\n========== Program End ==========\n";

    return 0;
}