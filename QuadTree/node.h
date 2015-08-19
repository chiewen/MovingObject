//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_NODE_H
#define MOVINGOBJECT_NODE_H

#include <memory>
#include "entry.h"
#include "leaf.h"

using namespace std;

class Node : public Entry {
public:
    float split_x, split_y;
    unique_ptr<Entry> quad[4];

private:
    virtual bool should_balance();

    bool is_overlap(const Range &range);

public:
    Node(Node *p, int direction, float x, float y) : Entry(p, direction), split_x(x), split_y(y) {
        for (int i = 0; i < 4; i++) quad[i].reset(new Leaf(this, i));
    }

    virtual ~Node();

    virtual void range_search(const Range &range, vector<Object> &result);

    virtual void insert_object(const Object &object);

    virtual void print();

    virtual size_t count_objects();

    void assign_child(int q, unique_ptr<Entry> e);

    void all_objects(vector<Object> &objects);

    virtual void balance_if_necessary();
};

#endif //MOVINGOBJECT_NODE_H
