//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_LEAF_H
#define MOVINGOBJECT_LEAF_H

#include "entry.h"
#include "bucket.h"
#include <list>

using namespace std;

class Leaf : public Entry {
private:
    virtual bool should_balance();

public:
    list<Bucket> bucket_list;

    static constexpr size_t MAX_LEAF_OBJECTS = Bucket::BUCKET_LENGTH * 6;

public:
    virtual void balance_if_necessary();

    Leaf(Node *p, int direction) : Entry(p, direction) { bucket_list.emplace_front(); };

    virtual ~Leaf() { };

    virtual size_t count_objects();

    virtual void insert_object(const Object &object);

    virtual void range_search(const Range &range, vector<Object> &result);

    virtual void print();

    virtual void all_objects(vector<Object> &objects);
};

#endif //MOVINGOBJECT_LEAF_H
