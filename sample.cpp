#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    vector<int> v;
    int front = 0, rear = -1, tot = 0;
    MyCircularQueue(int k)
    {
        tot = k;
    }

    bool enQueue(int value)
    {
        int size = rear - front + 1;
        if (size >= tot)
            return false;
        v.push_back(value);
        rear++;
        return true;
    }

    bool deQueue()
    {
        int size = rear - front + 1;
        if (size <= 0)
            return false;
        front++;
        return true;
    }

    int Front()
    {
        int size = rear - front + 1;
        if (size <= 0)
            return -1;
        return v[front];
    }

    int Rear()
    {
        int size = rear - front + 1;
        if (size <= 0)
            return -1;
        return v[rear];
    }

    bool isEmpty()
    {
        int size = rear - front + 1;
        return size <= 0;
    }

    bool isFull()
    {
        int size = rear - front + 1;
        return size == tot;
    }
};
