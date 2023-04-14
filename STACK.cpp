// STACK.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;
struct Stack
{
    int* a;
    int c;
    int n;
    int top;
};
Stack* create(int x) {
    Stack* s = new Stack();
    s->a = new int[x];
    s->c = x;
    s->n = 0;
    s->top = -1;
    return s;
}
void push(Stack* x, int item) {
    if (x->n == x->c) { 
        cout << "\nfull\n";
        return; 
    }
    x->top++;
    x->n++;
    x->a[x->top] = item;
}
int pop(Stack* x) {
    if (x->n == 0) {
        cout << "\nempty\n";
        return INT32_MIN;
    }
    x->top--;
    x->n--;
    return x->a[(x->top) + 1];
}
void show(Stack* x) {
    if (x->n == 0) {
        cout << "\nempty stack,there is nothing to display.\n";
        return;
    }
    for (int i = 0; i < x->n; i++) {
        cout << x->a[i] << "\t";
    }
}

int main()
{
    Stack* s = create(7);
    push(s, 41);
    push(s, 42);
    push(s, 43);
    push(s, 44);
    push(s, 45);
    push(s, 46);
    push(s, 47);
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    cout << pop(s) << endl;
    show(s);
    cout << endl;
    cout << s->top << endl;
    for (int i = 0; i < 7; i++)
        cout << s->a[i] << "\t";
    delete s->a;
    delete s;
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
