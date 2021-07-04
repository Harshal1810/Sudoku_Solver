//Harshal Khamkar
#include<bits/stdc++.h>
using namespace std;

//Check whether there is an entry exist which is not assigned:
bool FindUnassigned(int grid[9][9], int& row, int& col){
   for(row=0;row<9;row++)
     {
      for(col=0;col<9;col++)
        if(grid[row][col]==0) return true;
     }
        
        return false;
                                                       }
//Check whether it is possible to assign a 'num' to given (row,col)
bool isSafe(int grid[9][9], int row, int col, int num);

//Takes an partially filled grid and check whether solution exist or not:
bool sudoku(int grid[9][9]){
   int row,col;
   //If there is no unassigned location left, we are done!
   if(!FindUnassigned(grid,row,col)) return true;
   
   // Else try to assign digits from 1-9:
   for(int num=1;num<=9;num++)
    {
      //Check whether it is possible to assign num to (row,col)
      if(isSafe(grid,row,col,num))
        {
        grid[row][col]=num;
       
     //If success, return true
      if(sudoku(grid)) return true;
    
    //Failure, Unmake and try again
      grid[row][col]=0;
         }
    }
    //BackTracking:
    return false;
}

//Check if 'num' exist in given row
bool UsedInRow(int grid[9][9],int row, int num){
    for(int col=0;col<9;col++)
     {
         if(grid[row][col]==num) return true;
     }
     return false;
}

//check if 'num' exist in given column
bool UsedInCol(int grid[9][9],int col, int num){
    for(int row=0;row<9;row++)
     {
         if(grid[row][col]==num) return true;
     }
     return false;
}

//Check if 'num' exist in given 3x3 box
bool UsedInBox(int grid[9][9], int BoxStartRow, int BoxStartCol, int num){
     for(int row=0;row<3;row++)
       for(int col=0;col<3;col++)
          if(grid[row+BoxStartRow][col+BoxStartCol]==num)
              return true;

    return false;
}

//Check whether it is possible to assign num to (row,col)
bool isSafe(int grid[9][9], int row, int col, int num){
    return !UsedInRow(grid,row,num)
           && !UsedInCol(grid,col,num)
           && !UsedInBox(grid,row-row%3,col-col%3,num)
           && grid[row][col]==0;
}

//Function to print the grid
void PrintGrid(int grid[9][9]){
    for(int row=0;row<9;row++)
     {
      for(int col=0;col<9;col++)
         cout<<grid[row][col]<<" ";
          
        cout<<endl;
     }
          
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   
    int grid[9][9];
    // '0' means unassigned cells
    cout<<"Input the grid row-wise: "<<endl;
    for(int i=0;i<9;i++)
      for(int j=0;j<9;j++)
        cin>>grid[i][j];

    if(sudoku(grid))
    {
     cout<<endl<<" Solution Exist: "<<endl;
     PrintGrid(grid);
    }
    
    else 
     cout<<"No Solution Exist"<<endl;
    
    return 0;
}