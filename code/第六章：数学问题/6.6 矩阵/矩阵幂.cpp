#include <iostream>
#include <vector>
using namespace std;

struct Matrix{
    int matrix[10][10];
    int row,col;
    Matrix(int r,int c) : row(r),col(c) {}
};

Matrix Multiply(Matrix x,Matrix y){
    Matrix result(x.row,y.col);
    for(int i=0;i<result.row;i++){
        for(int j=0;j<result.col;j++){
            result.matrix[i][j]=0;
            for(int k=0;k<x.col;k++){
                result.matrix[i][j]+=x.matrix[i][k] *y.matrix[k][j];
            }
        }
    }
    return result;
}

Matrix FastExponention(Matrix x,int k){
    Matrix result(x.row,x.col);
    //先要初始化为单位矩阵
    for(int i=0;i<result.row;i++){
        for(int j=0;j<result.col;j++){
            if(i==j){
                result.matrix[i][j]=1;
            }
            else{
                result.matrix[i][j]=0;
            }
        }
    }

    while(k>0){
        if(k%2==1){
            result=Multiply(result,x);  //这里这个函数就是一个累乘了
        }
        x=Multiply(x,x);
        k/=2;
    }
    return result;
}


int main(){
    int n,k;
    while(cin >> n >> k){
        Matrix x(n,n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin >> x.matrix[i][j];
            }
        }

        Matrix result =FastExponention(x,k);
        
        for(int i=0;i<result.row;i++){
            for(int j=0;j<result.col;j++){
                cout << result.matrix[i][j];
                if(j==result.row-1) cout << endl;
                else cout << ' ';
            }
        }
    }
    return 0;
}