//
// Created by chiewen on 2015/8/14.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "entry.h"
#include "node.h"

void Entry::insert_object_range(vector<Object>::iterator b, vector<Object>::iterator e) {
    for_each(b, e, [&](const Object &o) { insert_object(o); });
};


//WARN! This operation invalidates the instance and reset the pointer in its parent
void Entry::balance() {
    size_t obj_num = count_objects();
    vector<Object> objects;

    objects.reserve(obj_num);
    all_objects(objects);

    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.x > o2.x; });
    float middle_x = objects[obj_num / 2].x - 0.1f;

    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.y > o2.y; });
    float middle_y = objects[obj_num / 2].y - 0.1f;

    auto p1 = partition(objects.begin(), objects.begin() + obj_num / 2,
                        [middle_x](const Object &o) { return o.x >= middle_x; });
    auto p2 = partition(objects.begin() + obj_num / 2, objects.end(),
                        [middle_x](const Object &o) { return o.x < middle_x; });

    unique_ptr<Node> n(new Node(parent, direction, middle_x, middle_y));

    n->quad[0]->insert_object_range(objects.begin(), p1);
    n->quad[1]->insert_object_range(p1, objects.begin() + obj_num / 2);
    n->quad[2]->insert_object_range(objects.begin() + obj_num / 2, p2);
    n->quad[3]->insert_object_range(p2, objects.end());

    for (auto &q :n->quad) { q->balance_if_necessary(); };

    parent->assign_child(direction, move(n));
}