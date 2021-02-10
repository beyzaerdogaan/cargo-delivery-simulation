/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);

*/

#ifndef ASSIGNMENT3_STACK_H
#define ASSIGNMENT3_STACK_H
#include <iostream>

template <typename T>
class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    int size() const;

    //Push: Place item on top of the stack
    void push(const T& newItem);
    //Top: Take a look at the topmost item without removing it
    void getTop(T& stackTop) const;
    void getTop() const;
    //Pop: Remove item from the top of the stack
    void pop();
private:
    struct ListNode {
        T item;
        ListNode* next;
    };
    ListNode* _head;
    int _size;
};

template<typename T>
Stack<T>::Stack() {
    _head = NULL;
    _size = 0;
}

template<typename T>
Stack<T>::~Stack() {

}

template<typename T>
bool Stack<T>::isEmpty() const {
    return _size == 0;
}

template<typename T>
int Stack<T>::size() const {
    return _size;
}

template<typename T>
void Stack<T>::push(const T &newItem) {
    if (_head == NULL)
    {
        ListNode* temp = new ListNode;
        temp->item = newItem;
        temp->next = nullptr;
        _head = temp;
        _size++;
    }
    else
    {
        ListNode* temp = new ListNode;
        temp->item = newItem;
        temp->next = _head;
        _head = temp;
        _size++;
    }
}

template<typename T>
void Stack<T>::getTop(T &stackTop) const {
    if (isEmpty()) {
        throw "StackException";
    }
    else {
        stackTop = _head->item;
    }
}

template<typename T>
void Stack<T>::pop() {
    if (isEmpty())
    {
        std::cout << "Stack is empty." << std::endl;
    }
    else
    {
        ListNode* temp = _head;
        _head = _head->next;
        _size--;
        delete temp;
        temp = NULL;
    }
}

template<typename T>
void Stack<T>::getTop() const {
    if (_size == 0)
    {
        std::cout << "Stack is empty" << std::endl;
    }
    else
    {
        std::cout << _head->item << std::endl;
    }
}

#endif //ASSIGNMENT3_STACK_H
