#include <iostream>
#include <cmath>

using namespace std;

long long int power(long long int a, long long int b, long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}

int main()
{
    long long int P, G, a, b, R1, R2, ka, kb;

    cout << "Enter a prime number P: ";
    cin >> P;

    cout << "Enter a primitive root for P, G: ";
    cin >> G;

    cout << "Enter a private key for Aniket, a: ";
    cin >> a;

    // Calculate R1
    R1 = power(G, a, P);
    cout << "R1: " << R1 << endl;

    cout << "Enter a private key for Aviral, b: ";
    cin >> b;

    // Calculate R2
    R2 = power(G, b, P);
    cout << "R2: " << R2 << endl;

    // Calculate the shared secret key for Aniket and Aviral
    ka = power(R2, a, P);
    kb = power(R1, b, P);

    cout << "Secret key for Aniket: " << ka << endl;
    cout << "Secret key for Aviral: " << kb << endl;

    return 0;
}
