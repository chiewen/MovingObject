//
// Created by chiewen on 2015/8/15.
//

#include <iostream>
#include "TestTree.h"
#include "../QuadTree/quadtree.h"
#include "../DataGenerator/DataGenerator.h"


void TestTree::test() {
    QuadTree qt;
    vector<Object> data;
    DataGenerator::generate_ordinary(2000, QuadTree::WIDTH, QuadTree::HEIGHT, data);

    cout << data.size() << endl << "============" << endl;

    qt.root.insert_object_range(data.begin(), data.end());
    qt.root.balance_if_necessary();

    auto r = qt.range_search(Range{0, 0, 20000, 20000});

    for (auto &o: r) { cout << "(" << o.id << ", " << o.x << ", " << o.y << ") "; };

    cout << endl << r.size() << endl;
}

