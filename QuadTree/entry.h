//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_ENTRY_H
#define MOVINGOBJECT_ENTRY_H

#include <tuple>
#include <vector>
#include "object.h"

using namespace std;

// define a square range in the plane.
// x_lower, y_lower, x_upper, y_upper
typedef tuple<float, float, float, float> Range;

class Node;

class Leaf;

class Entry {
protected:
    Node *parent;
    int direction;

public:
    Entry(Node *parent, int direction) : parent(parent), direction(direction) { }

    virtual ~Entry();

    virtual void range_search(const Range &range, vector<Object> &result) = 0;

    virtual void insert_object(const Object &object) = 0;

    virtual void balance() = 0;

    virtual size_t count_objects() = 0;

    virtual void print() = 0;
};

#endif //MOVINGOBJECT_ENTRY_H
