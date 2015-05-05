#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<int> v;

    v.push_back(3);
    v.push_back(1);
    v.push_back(4);

    for each(int value in v); {
        cout << value << endl;
    }

    return 0;
}
