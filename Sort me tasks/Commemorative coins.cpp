#include <iostream>

using namespace std;

int main() {
    int x;
    cin >> x;

    int fives = x / 5;
    int threes = 0;
    bool found = false;

    while (fives >= 0 && !found) {
        int rem = x - (fives * 5);
        if (rem % 3 == 0) {
            threes = rem / 3;
            found = true;
        } else {
            fives--;
        }
    }

    if (found) {
        cout << threes << " " << fives << endl;
    }

    return 0;
}
