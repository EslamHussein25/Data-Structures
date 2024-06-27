#include <iostream>

template <class T>
class Node
{
public:
T Data ;
Node<T> * Next ;
Node()
{
  Next = NULL ;
}
};

template <class T>
class Queue
{
    private:
Node<T> * Front ;
Node<T> * Rear ;
    public:
Queue()
{
    Front = Rear = NULL; 
}

~Queue()
{
    delete Front ;
    delete Rear ;
}

void Enqeuue(T Data)
{
    //add new node with new data to the queue 
    Node<T> * newNode = new Node<T> ;
    newNode->Data = Data ;
    if(IsEmpty())
    {
        Front = newNode ;
        Rear  = newNode ;
    }
    else 
    {  
        Rear->Next = newNode ;
        Rear = newNode ;
    }
}

Node<T> * Dequeu()
{
    Node<T> * Obj = NULL ;
    if(IsEmpty())
    {
        std::cout<<"Error: No Eelemnts to delete\n";
    }
    else 
    {
        Obj = Front ;
        Front = Front->Next ;
        delete Obj ;
    }
    return Obj ;
}

void Search(T Key)
{
    Node<T> * Temp = Front ;
    bool Flag = false ;
    while(Temp != Rear)
    {
        if(Temp->Data == Key)
        {
            std::cout<<"Found\n" ;
            Flag = true ;
            break;
        }
        Temp = Temp->Next ;
    }
    if(!Flag)
    {
        std::cout<<"Not Found\n" ;
    }
    delete Temp ;
}

void Display()
{
    Node<T> * Temp = Front ;
    while(Temp != NULL)
    {
        std::cout<<Temp->Data<<"\n" ;
        Temp = Temp->Next ;
    }

    delete Temp ;
}

bool IsEmpty()
{
    return (Front == NULL);
}

T GetFront()
{
    return Front->Data ;
}

T GetRear()
{
    return Rear->Data ;
}

};

int main()
{
Queue<int> q ;
q.Display();
q.Enqeuue(10);
q.Enqeuue(20);
q.Enqeuue(30);
q.Enqeuue(40);
q.Dequeu();
q.Dequeu();
q.Enqeuue(50);
q.Dequeu();
q.Display();
    return 0 ;
}