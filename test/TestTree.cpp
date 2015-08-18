//
// Created by chiewen on 2015/8/15.
//

#include <iostream>
#include "TestTree.h"
#include "../QuadTree/quadtree.h"


void TestTree::test() {
    QuadTree qt;
    qt.root.quad[0].reset(new Node(&qt.root, 0, 0, 0));

    Object o = {1, 1};

    for (int i = 0; i < 43; i++)
        static_cast<Leaf *>(qt.root.quad[1].get())->insert_object(o);

    qt.root.print();

    vector<Object> all;
    qt.root.all_objects(all);

    cout << "total:" << all.size() << endl;
    cout << "total:" << qt.root.count_objects() << endl;

    auto r = qt.range_search(make_tuple(0, 0, 1, 1));

    cout << endl << r.size() << endl;
}
