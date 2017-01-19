#include <iostream>
#include <iomanip>
#define MAX 100000
using namespace std;
/*  badizz™ */
int main()
{
  int k(0),adet(0),tmp;
  char a[MAX];
  
  cin>>adet;
  

cin>>a;  

  for (int i=0; i<adet; i++) 
  {
	  for (int j=0; j<adet-1; j++)
          
		  if (a[j+1] < a[j]) 
          {  
             tmp = a[j];    
             a[j] = a[j+1];
             a[j+1] = tmp;
           	 k++;  
          }        
  }
 cout << endl  << "Devrik Cift Sayisi " << k;
 
 /*  badizz™ */
  return 0; 
}

