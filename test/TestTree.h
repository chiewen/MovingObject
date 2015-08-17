//
// Created by chiewen on 2015/8/15.
//

#ifndef MOVINGOBJECT_TESTTREE_H
#define MOVINGOBJECT_TESTTREE_H

#include <iostream>
#include <memory>
#include "../QuadTree/entry.h"
#include "../QuadTree/node.h"

using namespace std;

class TestTree {
public:
    void test();

    void f(unique_ptr<Entry> &u) {
        cout << "u:" << u->count_objects() << endl;
    }

    void tt() {
        unique_ptr<Entry> p(new Node(nullptr, 0, 1, 1));
        f(p);
    }
};


#endif //MOVINGOBJECT_TESTTREE_H
