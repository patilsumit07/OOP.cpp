#include<iostream>
using namespace std;

class Matrix
{
    private:
    int row,col;
    int a[10][10];

    public:
    void readMatrix()
    {
        cout<<"Enter Number Of Row and Columns :";
        cin>>row>>col;

        cout<<"Enter matrix elements :\n";
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cin>>a[i][j];
            }
        }

    }

    void displayMatrix()
    {
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }
    }

    Matrix addMatrix(Matrix m)
    {
        Matrix temp;

        if(row !=m.row||col != m.col)
        {
            cout<<"Addition Not Possible.\n";
            temp.row = temp.col = 0;
            return temp;
        }

        temp.row = row;
        temp.col = col;

        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp.a[i][j] = a[i][j] + m.a[i][j];
            }
        }
        return temp;

    }
    Matrix subtractMatrix(Matrix m)
    {
        Matrix temp;

        if(row !=m.row||col != m.col)
        {
            cout<<"Subtraction Not Possible.\n";
            temp.row = temp.col = 0;
            return temp;
        }

        temp.row = row;
        temp.col = col;

        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp.a[i][j] = a[i][j] - m.a[i][j];
            }
        }
        return temp;
    }
    Matrix multiplyMatrix(Matrix m)
    {
        Matrix temp;

        if(col != m.row)
        {
            cout<<"Multiplication Not Possible.\n";
            temp.row = temp.col = 0;
            return temp;
        }

        temp.row = row;
        temp.col = m.col;

        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                temp.a[i][j] = 0;

                for (int k=0;k<col;k++)
                {
                    temp.a[i][j] = a[i][j] + m.a[i][j];
                }

            }
        }
        return temp;
    }
    bool isValid()
    {
        return(row>0 && col>0);
    }
};
int main()
{
    Matrix A,B,C;
     cout<<"Enter First Matrix :\n";
     A.readMatrix();

     cout<<"\nEnter Second Matrix :\n";
     B.readMatrix();

     cout<<"\n First Matrix :\n";
     A.displayMatrix();

     cout<<"\n Second Matrix :\n";
     B.displayMatrix();

     cout<<"\nAddition of Matrices :\n";
     C = A.addMatrix(B);
     if(C.isValid())
     C.displayMatrix();

     cout<<"\nSubtraction of Matrices :\n";
     C = A.subtractMatrix(B);
     if(C.isValid())
     C.displayMatrix();

     cout<<"\nMultiplication of Matrices :\n";
     C = A.multiplyMatrix(B);
     if(C.isValid())
     C.displayMatrix();

     return 0;
}
