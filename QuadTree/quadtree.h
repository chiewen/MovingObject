//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_QUADTREE_H
#define MOVINGOBJECT_QUADTREE_H
#include "entry.h"
#include "object.h"

class QuadTree {
public:
    const int M = 8;
    const int m = M / 2;

public:
    void insert_or_update(Object o);
};

#endif //MOVINGOBJECT_QUADTREE_H
