#include <iostream>
#include <queue>
using namespace std;

int find_animal(const int& id, const queue<int>& animals){
    queue<int> temp = animals;
    if(id==1){
        while(animals.front()<0){
            temp.pop();
        }
        return animals.front();
    }
    else {
        while(animals.front()>0){
            temp.pop();
        }
        return animals.front();
    }
    
}

int main(){
    int n;
    cin >> n;
    queue<int> animals;
    for (int i =0;i<n;i++){
        int type,id;
        cin >> type >> id;
        if(type==1){
            animals.push(id);
        }
        else {
            if(id==0){
                cout << animals.front() << ' ';
                animals.pop();
            }
            else {
                int animal = find_animal(id,animals);
                cout << animal <<' ';
            }
        }
    }
    return 0;
}
