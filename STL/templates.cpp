/** Learning to use templates
 * Define a template function add() that adds two variables of types int and float during call
 * Define a template class Math with methods multiply() and subtract() that return the product and difference of its two member variables. The call happens with long and double types
 * Print the results 
*/


#include <bits/stdc++.h>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

template <class T>
class Math
{
public:
    T a, b;
    T multiply();
    T subtract();
    Math(T a, T b);
};

template <class T>
Math<T>::Math(T a, T b)
{
    this->a = a;
    this->b = b;
}

template <class T>
T Math<T>::multiply()
{
    return a*b;
}

template <class T>
T Math<T>::subtract()
{
    return a-b;
}

int main(int argc, char *agrv[])
{
    int xI, yI;
    xI = 5;
    yI = 10;
    cout << "int sum = " << add<int> (xI, yI) << endl;

    float xF, yF;
    xF = 1.23f;
    yF = 5.32f;
    cout << "float sum = " << add<float> (xF, yF) << endl;

    Math<long> mathL(3213, -12);
    Math<double> mathD(2.34, 5.46);

    cout << "Math operations:" << endl;
    cout << "Long: difference = " << mathL.subtract() << "\tproduct = " << mathL.multiply() << endl;
    cout << "Double: difference = " << mathD.subtract() << "\tproduct = " << mathD.multiply() << endl;

    return 0;
}
