#include <iostream>
#include <cmath>
using namespace std;

long long get_determ(long long matrix[100][100], long long n)
{
    long long A,B,C,D,i,j,k,test_determ = 0 ,test_matrix[100][100],test_factor_i,test_factor_j;

    if(n==1)          // if order of a matrix is 1
        return matrix[0][0];

    else if(n==2)         // if order of a matrix is 2
    {
       A=matrix[0][0];
       B=matrix[0][1];
       C=matrix[1][0];
       D=matrix[1][1];

       return (A*D - B*C);
    }

    else        // if order of a matrix is 3 or more
    {
        // loop for first row (0) elements. to find a determinant of a matrix we  need to find out test factors of 0th row elements
        for(k=0; k<n; k++)
         {
            test_factor_i = 0;   // test_factor is the cofactor in the matrix
            for (i=1; i<n; i++)   // started from 1 as we dont want the elements in the same row
            {
               test_factor_j = 0;
               for (j=0; j<n; j++)
                {
                    if (j!=k) {

                        test_matrix[test_factor_i][test_factor_j] = matrix[i][j];
                        test_factor_j++;
                    }
                }
                test_factor_i++;
            }

            // calculating determinant of a matrix
            test_determ = test_determ + (((int)pow(-1, k)) * matrix[0][k] * get_determ( test_matrix,(n - 1) ));  //casting pow here to int as it's return type is double and it affects the final result
         }

    return test_determ;
}}

int main(){

long long x,y,z,w,N,arr1[100][100],arr2[100][100], determ2 ;
double sum [100][100],test =0 ;
double sub [100][100];
float inverse [10][10];

do{
cout<<"Please enter dimensions of Matrix A:"<<endl;
 cin>>x>>y;     // x & y: the number of rows and cols of the first matrix
} while(x<0||y<0);

do{
 cout<<"Please enter dimensions of Matrix B:"<<endl;
 cin>>z>>w;    // z & w: the number of rows and cols of the first matrix
  }while(z<0 || w<0);


 //to fill the first one
 cout<< "Please enter values of Matrix A:"<<endl;
  for(int i = 0 ;i<x;i++){
    for(int j=0 ;j<y ;j++){
      cin>>arr1[i][j] ;
    }
  }
//  filling the second matrix ///

cout<<"Please enter values of Matrix B:"<<endl;

for(int i = 0 ;i<z;i++){
    for(int j=0 ;j<w ;j++)
        {
     cin>>arr2[i][j] ;
        }
                       }
    determ2=get_determ(arr2,w);


 // determining the operation ///

  while(true){
        cout<<"Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):"<<endl;
        cin>>N;

// addition ///

 if(N==1){
        if(x==z && y==w){
       for(int i = 0; i < x; ++i){
        for(int j = 0; j < z; ++j){
             sum[i][j] = {arr1[i][j] + arr2[i][j]};
                 cout<<round(sum[i][j])<<" " ;
                                  }
                 cout<<endl;     }
                        }
            else{
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
                continue;
                }
        }

// Subtraction ///


else if(N==2){
        if(x==z && y==w){
     for(int i = 0; i < x; ++i){
        for(int j = 0; j < z; ++j){
             sub[i][j] = {arr1[i][j] - arr2[i][j]};
            cout<<round(sub[i][j])<<" " ;
                                  }
            cout<<endl;         }
                        }

              else{
                    cout<<"The operation you chose is invalid for the given matrices."<<endl;
                    continue;
                  }
             }

// multiplication ///

else if(N==3){
         if (y==z ){

      for(int i=0; i<x; i++)
    {
        for(int j=0; j<w; j++)
        {
            test=0;
            for(int k=0; k<z; k++){
                test = test + (arr1[i][k] * arr2[k][j]);
                                  }
       cout<<test<<" " ;

        }
           cout<<endl;
    }
                   }
            else{
                cout<<"The operation you chose is invalid for the given matrices."<<endl;
    continue;
                }
              }

// 3 * 3 Division

else if (N==4){
  if((determ2!=0)  && (z==w) && (y==z) ){

    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++ ){
            inverse[i][j]=((arr2[(j+1)%3][(i+1)%3] * arr2[(j+2)%x][(i+2)%3]) - (arr2[(j+1)%x][(i+2)%3] * arr2[(j+2)%x][(i+1)%3]))/ ((float)get_determ(arr2,w));

                                   }
                               }

 for(int i=0; i<x; ++i)
    {
        for(int j=0; j<w; ++j)
        {
            test=0;
            for(int k=0; k<z; ++k){
                test = test + (arr1[i][k] * inverse[k][j]);
                                  }
       cout<<(long long )llround(test)<<" " ;

        }
           cout<<endl;
    }
                                         }

   else {
   cout<<"The operation you chose is invalid for the given matrices."<<endl;
        }
            }

// calculating the determinant of the first matrix by using the function ///

else if(N==5){
        if(x==y){

    long long  determ1=get_determ(arr1,x);
    cout<<determ1<<endl;

                }
        else {
            cout<<"The operation you chose is invalid for the given matrices."<<endl;
            continue;
             }


              }

  // calculating the determinant of the second matrix by using the function ///

else if (N==6){
        if(z==w){

       long long determ2=get_determ(arr2,w);
        cout<<determ2<<endl;

                }
        else {
        cout<<"The operation you chose is invalid for the given matrices."<<endl;
        continue;
               }

              }


 // exit from the Program ///

else if (N==7){
    cout<<"Thank you!";
    break;    }
    else {
        cin.clear();
        cin.ignore(123,'\n');

       continue;
         }
      }

    return 0;
}

