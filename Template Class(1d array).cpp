#include <iostream>
//#include <dynArr.h>
//#include "src/dynArr.cpp"
using namespace std;


template <class T> class dynArr{
    private:
        T *data;
        int size;
    public:
        dynArr(int);
        ~dynArr();
        void setValue(int, T);
        T getValue(int);
};

template<class T> dynArr<T>::dynArr(int s)
{
    data = new T[s];
    size = s;
}
template<class T> dynArr<T>::~dynArr()
{
    delete [] data;
}
template<class T> T dynArr<T>::getValue(int index)
{
    return data[index];
}
template<class T> void dynArr<T>::setValue(int index, T value)
{
    data[index] = value;
}



int main()
{
    dynArr <double> obj1(5);
    dynArr <int> obj2(5);

    for(int i=0;i<5;i++){
        obj1.setValue(i,3.3);
    }
    for(int i=0;i<5;i++){
        obj2.setValue(i,3);
    }
    for(int i=0;i<5;i++){
        cout<<obj1.getValue(i)<<' ';
        cout<<obj2.getValue(i)<<endl;
    }
    obj1.~dynArr();
    obj2.~dynArr();


    return 0;
}
