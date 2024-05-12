#include <iostream>

#define MAX_SIZE 100
using namespace std;

class Stack
{
private:
    int *arr;
    int top;

public:
    // Constructor
    Stack() : top(-1)
    {
        arr = new int[MAX_SIZE];
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
    }

    // Push an element onto the stack
    void push(int value)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
        cout << value << " pushed to stack\n";
    }

    // Pop an element from the stack
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }

    // Print the stack
    void print() const
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    int numPush, numPop, value;

    cout << "How many elements do you want to push onto the stack? ";
    cin >> numPush;

    for (int i = 0; i < numPush; ++i)
    {
        cout << "Enter value to push: ";
        cin >> value;
        stack.push(value);
    }

    cout << "How many elements do you want to pop from the stack? ";
    cin >> numPop;

    cout << "Stack at this point: ";
    stack.print();

    cout << "Popped elements: ";
    for (int i = 0; i < numPop; ++i)
    {
        int popped = stack.pop();
        if (popped != -1)
        {
            cout << popped << " ";
        }
    }
    cout << endl;

    cout << "Stack at this point: ";
    stack.print();

    return 0;
}