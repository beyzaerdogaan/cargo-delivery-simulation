/*Function templates are special functions that can operate
with generic types. This allows us to create a function
template whose functionality can be adapted to more than
one type or class without repeating the entire code for each type.*/

/*To use this function template we use the following format for the function call:

function_name <type> (parameters);
*/

#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H
#include <iostream>

template<typename T>
class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    int size() const;
    //Enqueue: Items are added to the back of the queue
    void enqueue(const T& newItem);
    //Dequeue: Items are removed from the front of the queue
    void dequeue();
    //Get Front: Take a look at the first item
    void getFront(T& queueTop) const;
    void getFront() const;
private:
    struct QueueNode {
        T item;
        QueueNode *next;
    };
    int _size;
    /* to avoid the traversal to the last node,
     an additional pointer to the last node is defined*/
    QueueNode *_lastNode;
    QueueNode *_firstNode;
};

template<typename T>
Queue<T>::Queue() {
    _firstNode = NULL;
    _lastNode = NULL;
    _size = 0;
}

template<typename T>
Queue<T>::~Queue() {

}

template<typename T>
bool Queue<T>::isEmpty() const {
    return _size == 0;
}

template<typename T>
int Queue<T>::size() const {
    return _size;
}

template<typename T>
void Queue<T>::enqueue(const T &newItem) {
    if (_lastNode == NULL && _firstNode == NULL)
    {
        QueueNode* temp = new QueueNode;
        temp->item = newItem;
        temp->next = nullptr;
        _lastNode = _firstNode = temp;
        _size++;
    }
    else
    {
        QueueNode* temp = new QueueNode;
        temp->item = newItem;
        temp->next = nullptr;
        _lastNode->next = temp;
        _lastNode = temp;
        _size++;
    }
}

template<typename T>
void Queue<T>::dequeue() {
    if (isEmpty())
    {
        return;
    }
    else if (_firstNode == _lastNode)
    {
        QueueNode* temp = _firstNode;
        _size--;
        delete temp;
        temp = NULL;
        _firstNode = NULL;
        _lastNode = NULL;
    }
    else
    {
        QueueNode* temp = _firstNode;
        _firstNode = _firstNode->next;
        _size--;
        delete temp;
        temp = NULL;
    }
}

template<typename T>
void Queue<T>::getFront(T &queueTop) const {
    if (isEmpty())
    {
        throw "QueueException";
    }
    else
    {
        queueTop = _firstNode->item;
    }
}

template<typename T>
void Queue<T>::getFront() const {
    if (_size == 0)
    {
        return;
    }
    else
    {
        std::cout << _firstNode->item << std::endl;
    }
}

#endif //ASSIGNMENT3_QUEUE_H
