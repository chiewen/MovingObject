//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_ENTRY_H
#define MOVINGOBJECT_ENTRY_H

#include <tuple>
#include <vector>
#include <algorithm>
#include <memory>
#include "object.h"

using namespace std;

// define a square range in the plane. x_lower, y_lower, x_upper, y_upper
typedef tuple<float, float, float, float> Range;


class Node;

class Entry {
    friend class TestTree;

protected:
    Node *parent;

    int direction;

    virtual bool should_balance() = 0;

    void balance();

public:
    Entry(Node *parent, int direction) : parent(parent), direction(direction) { }

    virtual ~Entry() { };

    virtual void all_objects(vector<Object> &objects) = 0;

    virtual void range_search(const Range &range, vector<Object> &result) = 0;

    virtual void insert_object(const Object &object) = 0;

    virtual size_t count_objects() = 0;

    virtual void print() = 0;

    void insert_object_range(vector<Object>::iterator b, vector<Object>::iterator e);

    virtual void balance_if_necessary() = 0;
};

#endif //MOVINGOBJECT_ENTRY_H
