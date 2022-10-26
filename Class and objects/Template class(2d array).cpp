#include <iostream>
//#include <dynArr.h>
//#include "src/dynArr.cpp"
using namespace std;


template <class T> class dynArr{
    private:
        T **data;
        int row;
        int col;
    public:
        dynArr(int,int);
        ~dynArr();
        void setValue(int,int, T);
        T getValue(int,int);
};

template<class T> dynArr<T>::dynArr(int r,int c)
{
    data = new T*[r];
    for(int i=0;i<r;i++){
        data[i]=new T[c];
    }
    row = r;
    col = c;
}
template<class T> dynArr<T>::~dynArr()
{
    for(int i=0;i<row;i++){
        delete [] data[i];
    }
    delete [] data;
}
template<class T> T dynArr<T>::getValue(int row,int col)
{
    return data[row][col];
}
template<class T> void dynArr<T>::setValue(int row, int col, T value)
{
    data[row][col] = value;
}



int main()
{
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif

    dynArr <double> obj1(2,3);
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            obj1.setValue(i,j,i+1);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            cout<<obj1.getValue(i,j)<<' ';
        }
        cout<<endl;
    }
  

    return 0;
}
