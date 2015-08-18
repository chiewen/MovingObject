//
// Created by chiewen on 2015/8/15.
//

#include <iostream>
#include "TestTree.h"
#include "../QuadTree/quadtree.h"
#include "../DataGenerator/DataGenerator.h"


void TestTree::test() {
    QuadTree qt;
    auto data = DataGenerator::generate_ordinary(20000, QuadTree::WIDTH, QuadTree::HEIGHT);

    cout << data.size() << endl << "============" << endl;

    qt.root.insert_object_range(data.begin(), data.end());
    qt.root.balance_if_necessary();

    qt.root.print();

    vector<Object> all;
    qt.root.all_objects(all);

    cout << "total:" << all.size() << endl;
    cout << "total:" << qt.root.count_objects() << endl;

    auto r = qt.range_search(make_tuple(0, 0, 1, 1));

    cout << endl << r.size() << endl;
}
