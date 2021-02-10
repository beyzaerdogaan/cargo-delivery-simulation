//
// Created by Beyza on 7.12.2020.
//

#ifndef ASSIGNMENT3_DOUBLYLINKEDLIST_H
#define ASSIGNMENT3_DOUBLYLINKEDLIST_H

#include <iostream>
#include <string>

template<typename T>
class DoublyLinkedList {
public:
    // constructor
    DoublyLinkedList();

    // insert: get an item and insert it to the linked list
    void insert(T data);
    // remove: remove the package that has the given index
    void remove(int packageIndex);
    // removeTruck: remove the truck
    void removeTruck();
    // deleteAll: delete all packages and trucks from the linked list
    void deleteAll();
    // getItem: get the item that has the given index and take a look
    void getItem(T &item, int pIndex);
    // size: return the size of the list
    int size();

private:
    struct Node {
        T data;
        Node* next; // Pointer to next node
        Node* prev; // Pointer to previous node
    };
    Node* head;
    int _size = 0;
};


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
}

template<typename T>
void DoublyLinkedList<T>::insert(T data) {
    if (head == NULL)
    {
        Node* node = new Node;
        node->data = data;
        node->next = NULL;
        node->prev = NULL;
        head = node;
        _size++;
    }
    else
    {
        Node* node = new Node;
        node->data = data;
        Node* temp = head->next;
        if (temp != NULL)
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
            node->prev = temp;
            node->next = NULL;
        }
        else
        {
            node->data = data;
            node->next = NULL;
            node->prev = head;
            head->next = node;
        }
        _size++;
    }
}

template<typename T>
void DoublyLinkedList<T>::remove(int packageIndex) {
    int index = packageIndex + 1;
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node* temp = head;
        for (int i=0; temp!=NULL && i<index-1; i++) {
            temp = temp->next;
        }
        Node* del = temp->next;
        if (del->next != NULL)
        {
            temp->next = temp->next->next;
            temp->next->prev = temp;
        }
        else
        {
            temp->next = NULL;
        }
        delete del;
        del = NULL;
        _size--;
    }
}

template<typename T>
void DoublyLinkedList<T>::removeTruck() {
    Node* temp = head;
    if (temp != NULL)
    {
        delete temp;
        temp = NULL;
        head = NULL;
    }
    _size = 0;
}

template<typename T>
void DoublyLinkedList<T>::deleteAll() {
    if (head == NULL)
    {
        return;
    }
    else if (head->next == NULL)
    {
        removeTruck();
        _size--;
    }
    else
    {
        Node* temp = head->next;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node* last = temp->prev;
        while (last != head)
        {
            Node* del = temp;
            temp = temp->prev;
            delete del;
            del = NULL;
            last->next = NULL;
            last = last->prev;
        }
        if (last == head)
        {
            delete head->next;
            head->next = NULL;
            removeTruck();
        }
        _size--;
    }
}

template<typename T>
void DoublyLinkedList<T>::getItem(T &item, int pIndex) {
    int index = pIndex + 1;
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node* temp = head;
        for (int i=0; temp!=NULL && i<index; i++) {
            temp = temp->next;
        }
        item = temp->data;
    }
}

template<typename T>
int DoublyLinkedList<T>::size() {
    return _size;
}


#endif //ASSIGNMENT3_DOUBLYLINKEDLIST_H
