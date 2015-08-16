//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_LEAF_H
#define MOVINGOBJECT_LEAF_H

#include "entry.h"
#include "bucket.h"
#include "list"

using namespace std;

class Leaf : public Entry {
public:
    list<Bucket> bucket_list;

public:
    Leaf(Node *p, int direction) : Entry(p, direction) { bucket_list.emplace_front(); };

    virtual ~Leaf();

    virtual size_t count_objects();

    virtual void insert_object(const Object &object);

    virtual void range_search(const Range &range, vector<Object> &result);

    virtual void print();

    virtual void balance();

private:
    bool need_balance();
};

#endif //MOVINGOBJECT_LEAF_H
