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
        size = 0;
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
            return true;
        }
        else {
            size = size + 1;
            Type* ptr = new Type[size];
            memcpy(ptr, mass, size * sizeof(Type));
            delete[] mass;
            mass = ptr;
            mass[index] = var;
            index++;
            return false;
        }
    }
    Type out(int ind) {
        if (ind > size) return -1;
        else return mass[ind];
    }
    bool isEmpty() {
        if (size > 0) return false;
        else return true;
    }
    int sizeOf() {
        return size;
    }
    void pushBack(Type var) {
        size = size + 1;
        Type* ptr = new Type[size];
        memcpy(ptr, mass, size * sizeof(Type));
        delete[] mass;
        mass = ptr;
        mass[size - 1] = var;
    }
};

int main(){
    Vector<int> gg(5);
    for (int i = 0; i < 7; i++) {
        gg.insert(i);
        cout << gg.out(i) << endl;
    }
    gg.pushBack(228);
    cout << endl;
    for (int i = 0; i < 8; i++) {
        cout << gg.out(i) << endl;
    }
    cout << "Is it empty - " << gg.isEmpty() << endl << "that's size - " << gg.sizeOf() << endl;
    return 0;
}