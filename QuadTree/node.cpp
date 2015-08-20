//
// Created by chiewen on 2015/8/14.
//

#include <iostream>
#include <algorithm>
#include "node.h"

using namespace std;

void Node::range_search(const Range &range, vector<Object> &result) {
    for (auto &q: quad) if (is_overlap(range, q->direction)) q->range_search(range, result);
}

Node::~Node() { }

void Node::assign_child(int direction, unique_ptr<Entry> child) {
    quad[direction] = move(child);
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
    return accumulate(begin(quad), end(quad), static_cast<size_t>(0),
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

    auto mm = minmax_element(begin(object_numbers), end(object_numbers));
    return *mm.first < 0.6 * *mm.second;
}

void Node::balance_if_necessary() {
    if (should_balance()) balance();
    else for (auto &e :quad) { e->balance_if_necessary(); };
}

bool Node::is_overlap(const Range &range, int d) {
    return (d == 0 && range.x_upper >= split_x && range.y_upper >= split_y) ||
           (d == 1 && range.x_lower < split_x && range.y_upper >= split_y) ||
           (d == 2 && range.x_lower < split_x && range.y_lower < split_y) ||
           (d == 3 && range.x_upper >= split_x && range.y_lower < split_y);
}
