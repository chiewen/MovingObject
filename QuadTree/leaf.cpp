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

    if (need_balance()) balance();
}

bool Leaf::need_balance() { return count_objects() > QuadTree::MAX_LEAF_OBJECTS; }

size_t Leaf::count_objects() {
    return Bucket::BUCKET_LENGTH * (bucket_list.size() - 1) + bucket_list.front().number;
}

void Leaf::print() {
    cout << "{";
    for (const auto &b : bucket_list)
        for_each(b.objects, b.objects + b.number, [](const Object &o) { cout << "(" << o.x << ", " << o.y << ") "; });
    cout << "}";
}

void Leaf::balance() {
    size_t obj_num = count_objects();
    assert(obj_num > 4);

    vector<Object> objects;
    objects.reserve(obj_num);

    for (const auto &b : bucket_list)
        copy(b.objects, b.objects + b.number, back_inserter(objects));

    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.x > o2.x; });
    float middle_x = objects[obj_num / 2].x - 0.1f;

    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.y > o2.y; });
    float middle_y = objects[obj_num / 2].y - 0.1f;

    auto p1 = partition(objects.begin(), objects.begin() + obj_num / 2,
                        [middle_x](const Object &o) { return o.x > middle_x; });
    auto p2 = partition(objects.begin() + obj_num / 2, objects.end(),
                        [middle_x](const Object &o) { return o.x < middle_x; });

    unique_ptr<Node> n(new Node(parent, direction, middle_x, middle_y));

    for_each(objects.begin(), p1, [&n](const Object &o) { n->quad[0]->insert_object(o); });
    for_each(p1, objects.begin() + obj_num / 2, [&n](const Object &o) { n->quad[1]->insert_object(o); });
    for_each(objects.begin() + obj_num / 2, p2, [&n](const Object &o) { n->quad[2]->insert_object(o); });
    for_each(p2, objects.end(), [&n](const Object &o) { n->quad[3]->insert_object(o); });

    parent->assign_child(direction, move(n));
}
