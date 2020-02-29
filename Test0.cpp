#include <iostream>

using namespace std;

template <typename Type>
class Vector {
private:
    Type* mass;
    int index;
    int size;
public:
    Vector() {
        index = 0;
        size = 3;
        mass = new Type[size];
    }
    Vector(int s) {
        index = 0;
        size = s;
        mass = new Type[size];
    }
    ~Vector() {
        delete[] mass;
    }
    bool insert(Type var) {
        if (index < size) {
            mass[index] = var;
            index++;
            cout << "if";
            return true;
        }
        else {
            size = size + 10;
            Type* ptr = new Type[size];
            memcpy(ptr, mass, size * sizeof(Type));
            delete[] mass;
            mass = ptr;
            mass[index] = var;
            index++;
            cout << "else";
            return false;
        }
    }
    Type out(int ind) {
        if (ind > size) return -1;
        else return mass[ind];
    }
};

int main(){
    Vector<int> gg(5);
    for (int i = 0; i < 7; i++) {
        gg.insert(i);
        cout << gg.out(i) << endl;
    }
    return 0;
}