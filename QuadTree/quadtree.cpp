//
// Created by chiewen on 2015/8/14.
//

#include "quadtree.h"

using namespace std;

vector<Object> QuadTree::range_search(const Range &range) {
    vector<Object> result;
    root.range_search(range, result);
    return result;
}

