// 1d array
int main()
{
    int n;
    cout<<"Enter size"<<endl;
    cin>>n;

    int *arr=new int[5];

    cout<<"Enter "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<'\n'<<"Printing array elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    delete [] arr;

    return 0;
}


//2d array
int main()
{
    int row,col;
    cout<<"Enter row size"<<endl;
    cin>>row;
    cout<<"Enter column size"<<endl;
    cin>>col;

    char **arr=new char*[row];
    for(int i=0;i<row;i++){
        arr[i]=new char[col];
    }
    for(int i=0;i<row;i++){
        cout<<"Enter "<<col<<" characters for row "<<i+1<<endl;
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    cout<<"Printing:"<<endl;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete [] arr;


    return 0;
}

//2d array custom row


int main()
{
    int row,col_temp;;
    cout<<"Enter row size"<<endl;
    cin>>row;

    int **arr=new int*[row];
    int *col=new int[row];

    for(int i=0;i<row;i++){
        cout<<"Enter column size for row "<<i+1<<endl;
        cin>>col_temp;
        arr[i]=new int[col_temp];
        col[i]=col_temp;

        cout<<"Enter "<<col[i]<<" elements for this row:"<<endl;
        for(int j=0;j<col[i];j++){
            cin>>arr[i][j];
        }
    }

    cout<<"\n\n\n"<<endl;
    cout<<"Printing the 2d array:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col[i];j++){
            cout<<arr[i][j]<<' ';
        }
        cout<<endl;
    }

    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete [] arr;

    return 0;
}


