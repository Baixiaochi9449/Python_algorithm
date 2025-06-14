#include <iostream>
#include <vector>
using namespace std;

struct Metrix{
    int metrix[10][10];
    int row,col;
    Metrix(int r,int c):row(r),col(c){}
};

int main(){
    int r,c;
    while(cin >> r >> c){
        Metrix x(r,c);
        Metrix y(r,c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> x.metrix[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin >> y.metrix[i][j];
            }
        }

        Metrix result(r,c);
        vector<int> rows(r,1),cols(c,1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                result.metrix[i][j]=x.metrix[i][j]+y.metrix[i][j];
                if (result.metrix[i][j]!=0){
                    rows[i]=0;
                    cols[j]=0;
                }
            }
        }
        int count=0;
        for(int i=0;i<r;i++){
            count+=rows[i];
        }
        for(int j=0;j<c;j++){
            count+=cols[j];
        }
        cout << count << endl;
    }
    return 0;
}