#include <iostream>
using namespace std;

void swapNumbers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int x, y;

    cout << "Enter first number: ";
    cin >> x;

    cout << "Enter second number: ";
    cin >> y;

    cout << "Before swap: " << x << " " << y << endl;

    swapNumbers(&x, &y);

    cout << "After swap: " << x << " " << y << endl;

    return 0;
}