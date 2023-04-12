// CircularQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct cqueue {
    int a[10];
    int n;
    int front;
    int rear;
};
cqueue* create() {
    cqueue* p = new cqueue();
    p->n = 0;
    p->front = -1;
    p->rear = -1;
    return p;
}
void insert(int item, cqueue* p) {
    if (p->n == 10)cout << "\nfull\n";
    else if (p->n == 0) {
        p->n++;
        p->front++;
        p->rear++;
        p->a[p->front] = item;
    }
    else {
        p->n++;
        p->rear = (p->rear + 1) % 10;
        p->a[p->rear] = item;
    }
}
void deletecq(cqueue* p) {
    if (p->n == 1)
    {
        p->n--;
        p->front = -1;
        p->rear = -1;
    }
    else
    {
        p->n--;
        p->front = (p->front + 1) % 10;
    }
}
void show(cqueue* p) {
    if (p->n == 0)return;
    else if (p->front <= p->rear)
    {
        for (int i = p->front; i <= p->rear; i++) {
            cout << p->a[i] << "\t";
        }
        cout << endl;
    }
    else {
        for (int i = p->front; i <= 9; i++)
            cout << p->a[i] << "\t";
        for (int i = 0; i <= p->rear; i++)
            cout << p->a[i] << "\t";
    }
}

int main()
{
    cqueue* p = create();
    insert(21, p);
    insert(22, p);
    insert(23, p); 
    insert(24, p);
    insert(25, p);
    insert(26, p);
    insert(27, p);
    insert(28, p);
    insert(29, p);
    insert(30, p);
    deletecq(p);
    deletecq(p);
    deletecq(p);
    insert(31, p);
    insert(32, p);
    deletecq(p);
    deletecq(p);
    show(p);
    cout << endl;
    for (int i = 0; i < 10; i++)
        cout << p->a[i] << "\t";
    cout << endl << p->front << "\t" << p->rear;
    delete p;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
