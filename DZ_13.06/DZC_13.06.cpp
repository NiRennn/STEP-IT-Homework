#include <iostream>
#include <string>
using namespace std;



class LinkedList {
    public:
    struct Node{
        int value;
        Node* next;
        Node* prev;

    public:
        Node(int value) {
            this->value = value;
            this->next = this->prev = NULL;
        }
    };

    Node* head;
    Node* tail;

    public:
    LinkedList()
    {
        head = tail = NULL;
    }

    Node* push_front(int data){
        Node* tmp = new Node(data);
        tmp->next = head;
        if (head != NULL)
            head->prev = tmp;
        if (tail == NULL)
            tail = tmp;
        head = tmp;

        return tmp;
    }

    Node* push_back(int data){
        Node* tmp = new Node(data);
        tmp->prev = tail;
        if (tail != NULL)
            tail->prev = tmp;
        if (head == NULL)
            head = tmp;
        tail = tmp;

        return tmp;
    }

    void pop_front(){
        if (head == NULL)
            return;

        Node* tmp = head->next;
        if (tmp != NULL)
            tmp->prev = NULL;
        else
            tail = NULL;

        delete head;
        head = tmp;
    }

    void pop_back(){
        if (tail == NULL)
            return;

        Node* tmp = tail->prev;
        if (tmp != NULL)
            tmp->next = NULL;
        else
            head = NULL;

        delete tail;
        tail = tmp;
    }

    Node* getAt(int index)
    {
        Node* tmp = head;
        int n = 0;

        while (n != index)
        {
            if (tmp == NULL)
                return tmp;
            tmp = tmp->next;
            n++;
        }
        return tmp;
    }

    Node* operator [] (int index)
    {
    return getAt(index);
    }


    Node* insert (int index, int value)
    {
        Node* right = getAt(index);
        if (right == NULL)
            return push_back(value);

        Node* left = right->prev;
        if (left == NULL)
            return push_front(value);

        Node* tmp = new Node(value);

        tmp->prev = left;
        tmp->next = right;
        left->next = tmp;
        right->prev = tmp;

        return tmp;

    }

    void erase(int index)
    {
        Node* tmp = getAt(index);
        if (tmp == NULL)
            return;
        if (tmp->prev == NULL)
        {
            pop_front();
            return;
        }
        if(tmp->next == NULL)
        {
            pop_back();
            return;
        }

        Node* left = tmp->prev;
        Node* right = tmp->next;
        left->next = right;
        right->prev = left;

        delete tmp;

    }

//    friend ostream operator <<(ostream& os, const LinkedList& spisok)
//    {
//        Node* current = spisok.head;
//        while (current != nullptr){
//            os << current->value << " ";
//            current = current->next;
//        }
//        return os;
//    }

};


int main() {

LinkedList spisok;











    return 0;
}
