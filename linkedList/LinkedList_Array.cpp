#include <iostream>
using namespace std;

struct Node 
{
    int data;   // The data part
    int next;   // Index of the next node
};

class LinkedList 
{
private:
    Node* ptr;     // ptr of nodes
    int capacity;    // Total capacity of the list
    int head;        // Index of the head node
    int size;        // Current size of the list

public:
    LinkedList(int capacity) : capacity(capacity), head(-1), size(0) 
	{
		//do the array of Nodes like array of int data this array of Nodes but with constant size in this case 
        ptr = new Node[capacity]; //reserv the block of data like array but in heap and use it by ptr pointer 
        for (int i = 0; i < capacity; ++i) 
		{
            ptr[i].next = -1; // Initialize all 'next' indices to -1
        }
    }

    void insert(int value) 
	{
        if (size >= capacity) // because we use the array here so the capacity is constant 
		{
            cout << "List is full." << endl;
            return;
        }

        int currentIndex = size; // Use the next free index
        ptr[currentIndex].data = value;
        ptr[currentIndex].next = head;
        head = currentIndex;
        size++;
    }

    void print() 
	{
        int current = head;
        while (current != -1) 
		{
            cout << ptr[current].data << " ";
            current = ptr[current].next;
        }
        cout << endl;
    }

    ~LinkedList() 
	{
        delete[] ptr;
    }
};

int main() 
{
    LinkedList list(10);
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.print(); // Output: 3 2 1

    return 0;
}
