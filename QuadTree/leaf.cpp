//
// Created by chiewen on 2015/8/14.
//

#include <iostream>
#include <assert.h>
#include <algorithm>
#include "leaf.h"
#include "quadtree.h"

using namespace std;

void Leaf::range_search(const Range &range, vector<Object> &result) {
    for (const auto &b : bucket_list) {
        copy(b.objects, b.objects + b.number, back_inserter(result));
    }
}

Leaf::~Leaf() { }

void Leaf::insert_object(const Object &object) {
    assert(!bucket_list.empty());

    if (bucket_list.front().number == Bucket::BUCKET_LENGTH)
        bucket_list.emplace_front();

    bucket_list.front().objects[bucket_list.front().number++] = object;

    if (is_need_balance()) balance();
}

bool Leaf::is_need_balance() { return count_objects() > QuadTree::MAX_LEAF_OBJECTS; }

size_t Leaf::count_objects() {
    return Bucket::BUCKET_LENGTH * (bucket_list.size() - 1) + bucket_list.front().number;
}

void Leaf::print() {
    cout << "{";
    for (const auto &b : bucket_list)
        for_each(b.objects, b.objects + b.number,
                 [](const Object &o) { cout << "(" << o.x << ", " << o.y << ") "; });
    cout << "}";
}

//the operation will invalidate the
void Leaf::balance() {
    size_t obj_num = count_objects();
    assert(obj_num > 4);

    vector<Object> objects;
    objects.reserve(obj_num);
    all_objects(objects);

    auto s = split_four(obj_num, objects);

    unique_ptr<Node> n(new Node(parent, direction, get<0>(s), get<1>(s)));

    for_each(objects.begin(), get<2>(s), [&n](const Object &o) { n->quad[0]->insert_object(o); });
    for_each(get<2>(s), objects.begin() + obj_num / 2, [&n](const Object &o) { n->quad[1]->insert_object(o); });
    for_each(objects.begin() + obj_num / 2, get<3>(s), [&n](const Object &o) { n->quad[2]->insert_object(o); });
    for_each(get<3>(s), objects.end(), [&n](const Object &o) { n->quad[3]->insert_object(o); });

    parent->assign_child(direction, move(n));
}

void Leaf::all_objects(vector<Object> &objects) {
    for (const auto &b : bucket_list)
        copy(b.objects, b.objects + b.number, back_inserter(objects));
}
