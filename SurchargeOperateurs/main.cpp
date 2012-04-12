#include <iostream>
#include "Duree.h"

using namespace std;

int main()
{
    Duree duree1(2, 25, 28), duree2(0, 16, 33);

    cout << duree1 << " et " << duree2 << endl;

    Duree chrono(0, 2, 30);
    cout << chrono;

    return 0;
}
