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

size_t Node::count_objects() {
    return accumulate(quad, quad + 4, static_cast<size_t>(0),
                      [](size_t sum, unique_ptr<Entry> &p) { return sum + p->count_objects(); });
}

void Node::all_objects(vector<Object> &objects) {
    for (auto &q : quad) q->all_objects(objects);
}

//TODO specify a feasible condition for balancing a node.
bool Node::should_balance() {
    size_t object_numbers[4] = {
            quad[0]->count_objects(),
            quad[1]->count_objects(),
            quad[2]->count_objects(),
            quad[3]->count_objects()
    };

    auto mm = minmax_element(object_numbers, object_numbers + 4);
    return *mm.first < 0.6 * *mm.second;
}

void Node::balance_if_necessary() {
    if (should_balance()) balance();
    else for_each(quad, quad + 4, [](unique_ptr<Entry> &e) { e->balance_if_necessary(); });
}
