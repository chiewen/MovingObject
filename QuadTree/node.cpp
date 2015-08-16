//
// Created by chiewen on 2015/8/14.
//

#include <iostream>
#include <algorithm>
#include "node.h"

using namespace std;

void Node::range_search(const Range &range, vector<Object> &result) {
    for (auto &q : quad) q->range_search(range, result);
}

Node::~Node() { }

void Node::assign_child(int q, unique_ptr<Entry> e) {
    quad[q] = move(e);
}

void Node::insert_object(const Object &object) {
    if (object.y >= split_y) if (object.x >= split_x) quad[0]->insert_object(object);
    else quad[1]->insert_object(object);
    else if (object.x >= split_x) quad[3]->insert_object(object);
    else quad[2]->insert_object(object);
}

void Node::print() {
    cout << "[";
    for (auto &q: quad) q->print();
    cout << "]";
}

void Node::balance() {

}

size_t Node::count_objects() {
    return accumulate(quad, quad + 4, static_cast<size_t>(0),
                      [](size_t sum, unique_ptr<Entry> &p) { return sum + p->count_objects(); });
}
