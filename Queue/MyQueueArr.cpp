#include <iostream>

template <class T>
class Queue
{
    
private:
int Capcity ;
int front ;
int rear ;
int size ;
int * queArr ;

public:
Queue(int Cap) : Capcity(Cap)
{
queArr = new T[Cap]; // create new area for array size 
size = 0 ;
front = 0;
rear = 0;
}

void Enqueue(T Item)
{

  if (IsFull())
  {
    std::cout<<"Queue is Full \n";
  }
  else 
  {
    queArr[size] = Item ;
    size++ ;
    rear = size ;
  }
}

T Dequeue()
{
    T Item ;
    if(IsEmbty())
    {
        std::cout<<"No Elements\n";
    }
    else 
    {
        Item = queArr[size];
        for(int count = 0  ; count<= size ; count++)
        {
            queArr[count] = queArr[(count+1)];
        }
        size--;
        rear  = size ;
    }
    return Item ;
}

T search(T Key)
{
    bool flag = false ;
    T Data ;
     for(int count = front ; count < size ; count++)
    {
        if(queArr[count] == Key)
        {
            std::cout<<"Found\n";
            flag = true ;
            Data = queArr[count];
        }
    }   
    if(flag)
    {
        std::cout<<"Not Found\n";  
        return ;
    }
    return Data ;
}
void Display()
{
    for(int count = front ; count < size ; count++)
    {
        std::cout<<queArr[count]<<"\n";
    }
}

bool IsEmbty()
{
 return(rear == front);
}

bool IsFull()
{
 return (Capcity == size);
}

T Peek()
{
    return queArr[front];
}

int Count()
{
    return size ;
}

T Back()
{
    return queArr[rear - 1];
}

};

int main()
{
Queue<int> q(4);
q.Enqueue(1);
q.Dequeue();
q.Dequeue();
q.Enqueue(2);
q.Enqueue(3);
q.Enqueue(5);
q.Dequeue();
q.Display();
std::cout<<"The peek is : "<<q.Peek()<<"\n";
if(std::cout<<"0")
{
std::cout<<"Done" ;
}
    return 0 ;
}