// QUEUE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;

struct queue {
    int a[5];
    int n;
    int front;
    int rear;
};
queue* createq() {
    queue* n = new queue();
    n->n = 0;
    n->front = -1;
    n->rear = -1;
    return n;
}
void insertq(int item, queue* n) {
    if (n->n >= 5) cout << "full\n";
    else if (n->n == 0) {
        n->n++;
        n->front++;
        n->rear++;
        n->a[n->front] = item;
    }
    else if ((n->n) < 5 && n->rear == 4) {
        for (int i = (n->front); i <= (n->rear); i++) {
            n->a[i - 1] = n->a[i];
        }
        n->front--;
        n->n++;
        n->a[n->rear] = item;
    }
    else if (n->n < 5 && n->rear != 4) {
        n->rear++;
        n->n++;
        n->a[n->rear] = item;
    }
}
void deleteq(queue* n) {
    n->n--;
    n->front++;
}
void show(queue* n) {
    cout << endl;
    for (int i = (n->front); i <= (n->rear); i++)
        cout << n->a[i] << "\t";
    cout << endl;
}

int main()
{
    queue* q = createq();
    insertq(21, q);
    insertq(22, q);
    insertq(23, q);
    insertq(24, q);
    deleteq(q);
    insertq(25, q);
    insertq(26, q);
    deleteq(q);
    deleteq(q);
    insertq(27, q);
    show(q);
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << q->a[i] << "\t";
    cout << endl << q->front << "\t" << q->rear;
    cout << endl;
    insertq(27, q);
    delete q;
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
