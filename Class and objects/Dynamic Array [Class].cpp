#include <iostream>
//#include"dynarr.cpp"
using namespace std;

class dynarr{
    public:
        dynarr();
        dynarr(int, int);
        ~dynarr();
        void setValue(int, int, int);
        int getValue(int, int);
        void allocate(int, int);
    private:
        int **data;
        int row, col;
};

dynarr::dynarr(){
    data = NULL;
    row = 0, col = 0;
}
dynarr::dynarr(int row, int col){
    data = new int*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new int[col];
    }
}
dynarr::~dynarr(){
    delete [] data;
}
int dynarr::getValue(int row, int col){
    return data[row][col];
}
void dynarr::setValue(int row,int col, int value){
    data[row][col] = value;
}
void dynarr::allocate(int row, int col){
    data = new int*[row];
    for (int i = 0; i < row; i++) {
        data[i] = new int[col];
    }
}




int main(){    
    #ifndef ONLINE_JUDGE  
           freopen("input.txt", "r", stdin); 
           freopen("output.txt", "w",stdout);
    #endif
    int row,col,input;
    dynarr d1();
    dynarr d2(5, 5);
    cin >> row >> col;
    d2.allocate(row, col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> input;
            d2.setValue(i,j,input);
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cout << d2.getValue(i,j) << " ";
        }
        cout << endl;
    }
    return 0;
}
