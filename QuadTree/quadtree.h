//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_QUADTREE_H
#define MOVINGOBJECT_QUADTREE_H
#include "entry.h"
#include "object.h"
#include "node.h"

class QuadTree {
public:
    static constexpr float WIDTH = 20000;
    static constexpr float HEIGHT = 20000;
    static constexpr size_t MAX_LEAF_OBJECTS = Bucket::BUCKET_LENGTH * 6;
public:
    Node root;

public:
    QuadTree() : root(nullptr, 0, WIDTH / 2, HEIGHT / 2) { };

    vector<Object> range_search(const Range &range);
};

#endif //MOVINGOBJECT_QUADTREE_H
