//
// Created by chiewen on 2015/8/14.
//

#include <vector>
#include <iostream>
#include <algorithm>
#include "entry.h"

Entry::~Entry() {
}

tuple<float, float, vector<Object>::iterator, vector<Object>::iterator>
Entry::split_four(size_t obj_num, vector<Object> &objects) const {
    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.x > o2.x; });
    float middle_x = objects[obj_num / 2].x - 0.1f;

    nth_element(objects.begin(), objects.begin() + obj_num / 2, objects.end(),
                [](const Object &o1, const Object &o2) { return o1.y > o2.y; });
    float middle_y = objects[obj_num / 2].y - 0.1f;

    return make_tuple(middle_x, middle_y,
                      partition(objects.begin(), objects.begin() + obj_num / 2,
                                [middle_x](const Object &o) { return o.x > middle_x; }),
                      partition(objects.begin() + obj_num / 2, objects.end(),
                                [middle_x](const Object &o) { return o.x < middle_x; }));
}