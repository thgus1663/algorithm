#include<iostream>

using namespace std;

int searchmax(int a, int b)
{
 if(a>b) return a;
 else return b;
}
int searchmax(int a, int b, int c)
{
 int max=a;
 if(max<b) max=b;
 if(max<c) max=c;
 return max;
}
int searchmax(int a, int b,int c, int d)
{
 int max=a;
 if(max<b) max=b;
 if(max<c) max=c;
 if(max<d) max=d;
 return max;
}

int PebbleSum(int **A, int m)
{

 int** w = new int*[4];
 for(int i = 0; i < 4; ++i)
     w[i] = new int[m];
 
 for(int i=0; i<m; i++) 
 {
  w[0][i]=A[0][i];
  w[1][i]=A[1][i];
  w[2][i]=A[2][i];
  w[3][i]=A[0][i]+A[2][i];
 }
 

 
 int** c = new int*[4];
 for(int i = 0; i < 4; ++i)
     c[i] = new int[m];
     
  for(int i=0; i<4; i++)
  {
   c[i][0]=w[i][0];
  }
  
  
 for(int j=1; j<m; j++)
 {
  
  c[0][j]=searchmax(c[1][j-1],c[2][j-1]) + w[0][j];
  c[1][j]=searchmax(c[0][j-1],c[2][j-1],c[3][j-1]) + w[1][j];
  c[2][j]=searchmax(c[0][j-1],c[1][j-1]) + w[2][j];
  c[3][j]=c[1][j-1] + w[3][j];
  
  } 
  

 
 return searchmax(c[0][m-1],c[1][m-1],c[2][m-1],c[3][m-1]);

}

 


int main(void)
{
  int m;
  cin>>m;
 


 int** ary = new int*[3];
 for(int i = 0; i < 3; ++i)
     ary[i] = new int[m];
    
 int num;
  
    for(int i=0; i<3; i++)
 {
  for(int j=0; j<m; j++)
  {
   cin>>num;
   ary[i][j]=num;
  }
 } 
    
   
    
 cout<<PebbleSum(ary, m);
 
     
} 
