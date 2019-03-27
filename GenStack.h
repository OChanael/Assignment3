#include <iostream>
#include <stack>
#include <string>

using namespace std;

template <class T>
class GenStack
{
  public:
    GenStack(int maxSize); // constructor
    ~GenStack(); // destructor

    void push (T data);
    T pop();
    T peek();

    int isFull();
    int isEmpty();

    int top;
    int max;

    T *myArray;
};

template <class T> // constructor
GenStack<T>::GenStack(int maxSize)
{
  myArray = new T[maxSize];
  max = maxSize;
  top = -1;
}

template <class T> // destructor
GenStack<T>::~GenStack()
{
  delete []myArray;
}

template <class T>
void GenStack<T>::push(T data)
{
  if(top == max - 1) // if the stack is full, double the size
  {
    T *temp1 = new T[max];

    for (int i = 0; i < max; ++i)
    {
      temp1[i] = myArray[i];
    }
    max *= 2;
  }
  myArray[++top] = data;
}

template <class T>
T GenStack<T>::pop()
{
  if (top != -1)
  {
    return myArray[top--];
  }
  else
  {
    return 0;
  }
}

template <class T>
T GenStack<T>::peek()
{
  if(top == -1)
  {
    return 0;
  }
  else
  {
    return myArray[top];
  }
}

template <class T>
int GenStack<T>::isFull()
{
    return (top == max-1);
}

template <class T>
int GenStack<T>::isEmpty()
{
    return (top == -1);
}
