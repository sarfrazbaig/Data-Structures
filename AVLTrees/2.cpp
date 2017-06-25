#include <iostream>
using namespace std;
void printMatrix(int** matrix, int numRows, int numCols)
{
    for(int i=0; i < numRows; i++)
    {
        for(int j=0; j < numCols; j++)
        {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

void findCC(int** matrix, int numRows, int numCols, int row, int col, int Label)
{
    if(matrix[row][col] == 1)
    {
        matrix[row][col] = Label;
    }
    else
    {
        return;
    }

    if(row+1 < numRows) findCC(matrix, numRows, numCols, row+1, col, Label);
    if(row-1 >= 0)      findCC(matrix, numRows, numCols, row-1, col, Label);
    if(col+1 < numCols) findCC(matrix, numRows, numCols, row, col+1, Label);
    if(col-1 >= 0)      findCC(matrix, numRows, numCols, row, col-1, Label);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int numRows=2;
    int numCols;
    cin>>numCols;
    char input[500][500];
    int data[500][500];
    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
            cin>>input[i][j];
        }
    }

    for(int i=0;i<numRows;i++)
    {
        for(int j=0;j<numCols;j++)
        {
            if(input[i][j]=='#')
            {
                data[i][j]=1;
            }
            else if(input[i][j]=='.')
            {
                data[i][j]=0;
            }
        }
    }
    int** matrix;

    matrix = new int*[numRows];
    for(int i=0; i < numRows; i++)
    {
        matrix[i] = new int[numCols];
        for(int j=0; j < numCols; j++)
        {
            matrix[i][j] = data[i][j];
        }
    }
    printMatrix(matrix, numRows, numCols);

    int numConnectedComp = 0;
    for(int i=0; i < numRows; i++)
    {
        for(int j=0; j < numCols; j++)
        {
            if(matrix[i][j] == 1)
            {
                numConnectedComp++;
                findCC(matrix, numRows, numCols, i, j, numConnectedComp+1);
            }
        }
    }

    std::cout << "No. of CC : " << numConnectedComp << std::endl;
    printMatrix(matrix, numRows, numCols);

    for(int i=0; i < numRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    }
    
}