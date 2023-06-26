#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class MyVector {
private:
    T *arr{};
    size_t length{};
    size_t capacity{};

public:
    MyVector(size_t capacity) {
        this->capacity = capacity;
    }

    MyVector(initializer_list<T> list) {
        this->capacity = list.size() * 2;
        this->length = list.size();
        this->arr = new T[this->capacity]{};

        for (auto i = list.begin(); i < list.end(); ++i) {
            this->arr[i - list.begin()] = *i;
        }
    }

    void append(T element) {
        if (this->length == this->capacity) {
            this->capacity *= 2;
            T *new_arr = new T[this->capacity]{};
            for (size_t i = 0; i < this->length; ++i) {
                new_arr[i] = this->arr[i];
            }
            delete[] this->arr;
            this->arr = new_arr;
        }
        this->arr[this->length] = element;
        this->length++;
    }

    void sort() {
        for (size_t i = 0; i < this->length - 1; ++i)
        {
            for (size_t j = 0; j < this->length - i - 1; ++j)
            {
                if (this->arr[j] > this->arr[j + 1])
                {
                    int tmp = this->arr[j];
                    arr[j] = this->arr[j + 1];
                    arr[j + 1] = tmp;
                }
            }
        }

    }
    void deleteLast() {

        T *new_arr = new T[this->capacity - 1]{};

        for (size_t j = 0; j < this->length - 1; ++j)
        {
            new_arr[j] = this->arr[j];
        }
        delete[] this->arr;
        this->arr = new_arr;
    }



    size_t getLength() const {
        return this->length;
    }

    friend ostream &operator<<(ostream &os, MyVector<T> &v) {
        for (size_t i = 0; i < v.length; ++i) {
            os << v.arr[i] << ' ';
        }
        return os;
    }

    T &operator[](size_t index) {
        if(index < this->length) {
            return this->arr[index];
        }
    }
};

int main() {

    MyVector<int> v1 = {2, 6, 3, 7, 1};
    cout << v1 << endl;

    v1.append(6);
    cout << v1 << endl;

    v1.sort();
    cout << v1 << endl;

    v1.deleteLast();
    cout << v1 << endl;

    cout << v1.getLength() << endl;
    return 0;
}
