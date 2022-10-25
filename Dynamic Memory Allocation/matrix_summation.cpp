#include <bits/stdc++.h>
#define endl '\n'
typedef long long int ll;
using namespace std;

int main()
{
    int n=3;

    double **mat1=new double*[3];
    for(int i=0;i<n;i++){
        mat1[i]=new double[n];
    }
    double **mat2=new double*[3];
    for(int i=0;i<n;i++){
        mat2[i]=new double[n];
    }
    cout<<"Enter "<<n*n<<" numbers for Matrix 1"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat1[i][j];
        }
    }

    cout<<"Enter "<<n*n<<" numbers for Matrix 2"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat2[i][j];
        }
    }

    double **ans=new double*[3];
    for(int i=0;i<n;i++){
        ans[i]=new double[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    cout<<"Summation of the two matrix:"<<endl;1

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<' ';
        }
    }
    cout<<endl;


    for(int i=0;i<n;i++){
        delete [] mat1[i];
    }
    delete [] mat1;

    for(int i=0;i<n;i++){
        delete [] mat2[i];
    }
    delete [] mat2;

    for(int i=0;i<n;i++){
        delete [] ans[i];
    }
    delete [] ans;




    return 0;
}
