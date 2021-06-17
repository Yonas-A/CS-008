#include <iostream>
#include <vector>

#include "../../!includes/Stack/stack.h"
#include "../../!includes/Utility/util.h"
#include "../../!includes/Utility/utilrecord.h"

using namespace std;

int main() {
    vector<long> vec({1, 3, 5, 7, 8});

    Stack<Util*> p;
    p.Push(new Util("Sir"));
    p.Push(new UtilRecord(vec));

    cout << p << endl;

    Util* a;
    a = p.Pop();

    cout << static_cast<int>(a->get_type()) << endl;

    return 0;
}
