#include <iostream>
using namespace std;

class Matrix
{
  int row,col;
  int** mat;
  public:
  Matrix(int r,int c):row{r},col{c}
  {
    mat=new int*[row];
    for(int i=0;i<row;i++) mat[i]=new int[col];
  } 
  
  void resize(int r,int c,int filler=0)
    {
    
    if(r==row && c==col)return;

    int** mat2=new int*[r];
    for(int i=0;i<r;i++)mat2[i]=new int[c];
    
        for(int i=0;i<r;i++)
        {
            if(i>=row) for(int j=0;j<c;j++)mat2[i][j]=filler;
            
            else
            {
              for(int j=0;j<c;j++)
              {
                  if(j>=col)mat2[i][j]=filler;
                  else mat2[i][j]=mat[i][j];
              }
            }
        }
        for(int i=0;i<row;i++)delete[] mat[i];
        delete[] mat;
        mat=mat2;
        row=r;col=c;
        return;
    }

    void transpose()
    {
      int** mat2=new int*[col];
      for(int i=0;i<col;i++)mat2[i]=new int[row];
      for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)mat2[j][i]=mat[i][j];
      for(int i=0;i<row;i++)delete[] mat[i];
      delete[] mat;
      mat=mat2;
      int temp=row;row=col;col=temp;
    }

    void display()
    {
        for(int i=0;i<col;i++)cout<<'-';cout<<endl;
        for(int i=0;i<row;i++)
        {
            cout<<"|  ";
            for(int j=0;j<col;j++)cout<<mat[i][j]<<' ';
            cout<<"  |\n";
        }
        cout<<endl;for(int i=0;i<col;i++)cout<<'-';
    }
    int& at(int i, int j) //for setting or getting the value of an index
    {
        if(i>=0&&j>=0&&i<row&&j<col) return mat[i][j];
        throw runtime_error("out of bounds");
    }
    ~Matrix()
    {
        for (int i = 0; i < row; i++) delete[] mat[i];
        delete[] mat;
    }

    void changeOddIndeces()
    {
        int count=0;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)
                {
                    if(count%2==1)mat[i][j]+=2;
                    count++;
                }
    }
};


int main()
{
    try
    {
        Matrix mat(3, 3);

        int value = 1;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                mat.at(i, j) = value++;
            }
        }

        cout << "Original Matrix:\n";
        mat.display();

        mat.transpose();
        cout << "\n\nTransposed Matrix:\n";
        mat.display();

        mat.resize(4, 5, 9);
        cout << "\n\nResized Matrix (4x5, filler = 9):\n";
        mat.display();

        mat.changeOddIndeces();
        cout << "\n\nAfter changeOddIndeces (odd-indexed elements +2):\n";
        mat.display();

        cout << "\n\nAttempting out-of-bounds access:\n";
        cout << mat.at(10, 10);
    }
    catch (const runtime_error& e)
    {
        cerr << "\nError: " << e.what() << endl;
    }

    return 0;
}
