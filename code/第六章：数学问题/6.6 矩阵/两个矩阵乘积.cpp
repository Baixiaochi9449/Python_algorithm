#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> matrix_1(2);
    vector<vector<int>> matrix_2(3);
    for(int i=0;i<2;i++){
        vector<int> temp(3);
        for(int j=0;j<3;j++){
            cin >>temp[j]; 
        }
        matrix_1[i]=temp;
    }
    for(int i=0;i<3;i++){
        vector<int> temp(2);
        for(int j=0;j<2;j++){
            cin >>temp[j]; 
        }
        matrix_2[i]=temp;
    }

    vector<vector<int>> matrix(2);
    for(int i=0;i<2;i++){
        vector<int> temp(2,0);
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                temp[j]+=matrix_1[i][k] * matrix_2[k][j]; 
            }
        }
        matrix[i]=temp;
    }

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }


}