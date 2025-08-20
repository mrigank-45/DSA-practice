#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class MyLinkedList
{
public:
    Node *head, *tail;
    MyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    int get(int index)
    {
        if (index < 0 || head == NULL)
        {
            return -1;
        }
        Node *current = head;
        while (index--)
        {
            current = current->next;
            if (current == NULL)
            {
                return -1;
            }
        }
        return current->data;
    }

    void addAtHead(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void addAtTail(int val)
    {
        Node *newNode = new Node(val);
        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            newNode->next = NULL;
        }
    }

    void addAtIndex(int index, int val)
    {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        
        index--;

        Node *current = head;
        while (index--)
        {
            current = current->next;
            if (current == NULL)
            {
                return;
            }
        }
        if (current == NULL)
        {
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;

        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    void deleteAtIndex(int index)
    {
        if(head == NULL || index < 0)
        {
            return;
        }
        if (index == 0)
        {
            head = head->next;
            if (head == NULL)
            {
                tail = NULL;
            }
            return;
        }
        index--;
        Node *current = head;
        while (index--)
        {
            current = current->next;
            if (current->next == NULL)
            {
                return;
            }
        }
        if (current->next == NULL)
        {
            return;
        }
        current->next = current->next->next;
        if (current->next == NULL)
        {
            tail = current;
        }
    }
};
