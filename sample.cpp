#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class MyCircularDeque
{
public:
    int size, curr;
    Node *front, *rear;
    MyCircularDeque(int k)
    {
        size = k;
        curr = 0;
        front = NULL;
        rear = NULL;
    }

    bool insertFront(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = new Node(value);
            rear = front;
            curr++;
            return true;
        }
        Node *temp = new Node(value);
        temp->next = front;
        front->prev = temp;
        front = temp;
        curr++;
        return true;
    }

    bool insertLast(int value)
    {
        if (isFull())
            return false;
        if (isEmpty())
        {
            front = new Node(value);
            rear = front;
            curr++;
            return true;
        }
        Node *temp = new Node(value);
        temp->prev = rear;
        rear->next = temp;
        rear = temp;
        curr++;
        return true;
    }

    bool deleteFront()
    {
        if (isEmpty())
            return false;
        if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
            curr--;
            return true;
        }
        Node *temp = front;
        front = front->next;
        front->prev = NULL;
        temp->next = NULL;
        delete temp;
        curr--;
        return true;
    }

    bool deleteLast()
    {
        if (isEmpty())
            return false;
         if(front == rear){
            delete front;
            front = NULL;
            rear = NULL;
            curr--;
            return true;
        }
        Node *temp = rear;
        rear = rear->prev;
        rear->next = NULL;
        temp->prev = NULL;
        delete temp;
        curr--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;
        return front->data;
    }

    int getRear()
    {
        if (isEmpty())
            return -1;
        return rear->data;
    }

    bool isEmpty()
    {
        if (curr == 0)
            return true;
        return false;
    }

    bool isFull()
    {
        if (curr == size)
            return true;
        return false;
    }
};
