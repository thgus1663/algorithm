#include<iostream>

using namespace std;

int searchmin(int a, int b)
{
 if(a>b) return b;
 else return a;
}

int matrixPath(int **A, int n, int m)
{

 
 int** c = new int*[n];
 for(int i = 0; i < n; ++i)
     c[i] = new int[m];
     
  c[0][0]=A[0][0];
    for(int i=1; i<n; i++) {
     c[i][0]=c[i-1][0]+A[i][0];
 }
    for(int j=1; j<m; j++) {
     c[0][j]=c[0][j-1]+A[0][j];
 }
 

  
  
  
  
  
 for(int i=1; i<n; i++)
 {
  for(int j=1; j<m; j++)
  {
   
   c[i][j] = A[i][j] + searchmin(c[i-1][j],c[i][j-1]);
   
  }
 }
 
 return c[n-1][m-1];

}

 


int main(void)
{
  int n, m;
  cin>>n>>m;
 


 int** ary = new int*[n];
 for(int i = 0; i < n; ++i)
     ary[i] = new int[m];
    
 int num;
  
    for(int i=0; i<n; i++)
 {
  for(int j=0; j<m; j++)
  {
   cin>>num;
   ary[i][j]=num;
  }
 } 
    
   
    
 cout<<matrixPath(ary, n, m);
 
     
} 
