#include <iostream>
#include <windows.h>
#include <cstdlib>
using namespace std;
const int MAX = 5;

class dominos
{
    int front, rear;
    int orders[MAX];

public:
    dominos()
    {
        front = rear = -1;
    }

    bool addorder(int data);
    void serveorder();
    void displayorder();
};

bool dominos::addorder(int id)
{
    if (rear == -1)
    {
        front = rear = 0;
        orders[rear] = id;
        return true;
    }

    else
    {
        int pos = (rear + 1) % MAX;
        if (pos == front)
        {
            cout << "Dominos is currently full.PLease wait." << endl;
            return false;
        }
        else
        {
            rear = pos;
            orders[rear] = id;
            return true;
        }
    }
}

void dominos::serveorder()
{
    if (front == -1)
    {
        cout << "All orders are served.Get more orders to serve!";
    }

    else
    {
        cout << "Order no " << orders[front] << " is ready !!" << endl;
        if (front == rear)
        {
            front = rear = -1;
        }

        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void dominos::displayorder()
{
    if (front == -1)
    {
        cout << "No orders left !!";
    }
    for (int i = front; i != rear; i = (i + 1) % MAX)
    {
        cout << orders[i] << " ";
    }

    cout << orders[rear];
}

int main()
{
    int ch, id = 0;
    dominos q;

    do
    {
        cout << "\n\n------------------------------";
        cout << "Welcome    to    Dominos  ";
        cout << "----------------------";
        cout << "\n\n****MENU****\n";
        cout << "1. Accept Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit";
        cout << "\nChoice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            id++;
            if (q.addorder(id))
            {
                cout << "Thank you for Order. Order id is : " << id;
            }
            else
            {
                id--;
            }
            break;
        case 2:
            q.serveorder();
            break;
        case 3:
            q.displayorder();
            break;
        }

    } while (ch != 4);

    return 0;
}
