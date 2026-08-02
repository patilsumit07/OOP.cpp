#include<iostream>
#include<string>
using namespace std;

class Publication
{
    protected:
    string title;
    float price;

    public:
    void getPublication()
    {
        cout<<"Enter Title :";
        cin>>title;
        cout<<"Enter Price :";
        cin>>price;

    }
    void displayPublication()
    {
        cout<<"Title :"<<title<<endl;
        cout<<"Price :"<<price<<endl;
    }
    void resetPublication()
    {
        title = "0";
        price =0;
    }
};

class Book : public Publication
{
    private :
    int pageCount;

    public :
    void getData()
    {
        try
            {
                getPublication();

                cout<<"Enter Page Count :";
                cin>>pageCount;

                if (pageCount<0)
                throw pageCount;

            }
            catch(...)
            {
                cout<<"\nInvalide Input! Exception Caught.\n";
                resetPublication();
                pageCount =0;

            }
        }
        void displayData()
        {
            cout<<"\n********** BOOK DETAILS **********"<<endl;
            displayPublication();
            cout<<"Page Count :"<<pageCount<<endl;

        }


    };
    class Tape : public Publication
    {
        private:
        float playTime;

        public:
        void getData()
        {
            try

                {
                    getPublication();

                    cout<<"\nEnter Playing Time (minutes) :";
                    cin>>playTime;

                    if (playTime<0)
                    throw playTime;
                }
                catch (...)
                {
                    cout<<"\n Invalide Input! Exception Caught.\n";
                    resetPublication();
                    playTime = 0;

                }
        }
            void displayData()
            {
                cout<<"\n********** TAPE DETAILS **********\n";
                    displayPublication();
                    cout<<"Playing Time :"<<playTime<<"minutes"<<endl;
            }


        };

        int main()
        {
            Book b;
            Tape t;

            cout<<"Enter Book Detials\n";
            b.getData();

            cout<<"\n Enter Tape Detials\n";
            t.getData();

            cout<<"\n========== Publication Information ==========\n";

            b.displayData();
            t.displayData();

            return 0;
        }
