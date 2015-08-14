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
private:
    list <tuple<int, Bucket>> bucket_list;
};

#endif //MOVINGOBJECT_LEAF_H
