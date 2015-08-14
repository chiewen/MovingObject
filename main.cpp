#include <iostream>
#include <memory>
#include "QuadTree/quadtree.h"
#include "QuadTree/bucket.h"

using namespace std;

void f(int *u) {
    cout << *u << endl;
}

int main() {
    QuadTree tree;
    tree.insert_or_update(Object());

    cout << sizeof(tuple<long long, Bucket>) << endl;

    return 0;
}