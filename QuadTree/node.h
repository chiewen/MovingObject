//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_NODE_H
#define MOVINGOBJECT_NODE_H

#include <memory>
#include "entry.h"

using namespace std;

class Node : public Entry {
public:
    float split_x, split_y;
    Node *parent;
    unique_ptr<Entry> quad_1, quad_2, quad_3, quad_4;

};
#endif //MOVINGOBJECT_NODE_H
