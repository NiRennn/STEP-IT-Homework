#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Queue
{
public:
    Queue() = default;


    Queue& operator=(const Queue& other) = delete;

    Queue(uint16_t capacity, bool exp = false)
    {
        this->capacity = capacity;
        this->arr = new T[capacity]{};
        this->exp = exp;
    }

    ~Queue()
    {
        delete[] this->arr;
    }

    void push(T value)
    {
        if (this->size == this->capacity && this->size != this->exp)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        else
        {
            if (this->size == this->capacity && this->size == this->exp)
            {
                this->capacity *= 2;

                T* newArr = new T[this->capacity]{};

                for (uint16_t i = 0; i < this->capacity; i++)
                {
                    newArr[i] = this->arr[i];
                }

                delete[] this->arr;
                this->arr = newArr;
            }
        }
        this->arr[this->size] = value;
        this->size++;
    }



    T peek(bool reset = false)
    {
        static uint16_t iter = -1;

        if (reset)
        {
            iter = 0;
        }

        if (this->size == 0)
        {
            cout << "Queue is empty" << endl;
            return T{};
        }
        if (iter == this->size)
        {
            iter = -1;
        }
        iter++;
        return this->arr[iter];
    }


    T pop()
    {
        if (this->size == 0)
        {
            cout << "Queue is empty" << endl;
            return T{};
        }

        T tmp = this->arr[0];

        for (size_t i = 0; i < this->size; i++)
        {
            arr[i] = arr[i + 1];
        }

        this->arr[this->size] = T{};

        this->size--;

        return tmp;
    }

    friend ostream& operator<<(ostream& os, Queue other)
    {

        for (size_t i = 0; i < other.getSize(); i++)
        {
            os << other.peek();
        }

        return os;
    }

    uint16_t getSize() const
    {
        return this->size;
    }

private:
    T* arr{};
    uint16_t size{};
    uint16_t capacity{};
    bool exp{ false };
};

int main()
{
    Queue<int> queue(5, true);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);
    queue.push(6);



    cout << queue;

    return 0;
}