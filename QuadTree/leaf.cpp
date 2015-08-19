//
// Created by chiewen on 2015/8/14.
//

#include <iostream>
#include <assert.h>
#include <algorithm>
#include "leaf.h"

using namespace std;

void Leaf::range_search(const Range &range, vector<Object> &result) {
    for (const auto &b : bucket_list) {
        copy_if(b.objects, b.objects + b.number, back_inserter(result), [&](const Object &o) {
            return (o.x >= range.x_lower && o.x <= range.x_upper && o.y >= range.y_lower && o.y <= range.y_upper);
        });
    }
}

bool Leaf::should_balance() { return count_objects() > MAX_LEAF_OBJECTS; }

void Leaf::insert_object(const Object &object) {
    assert(!bucket_list.empty());

    if (bucket_list.front().number == Bucket::BUCKET_LENGTH)
        bucket_list.emplace_front();

    bucket_list.front().objects[bucket_list.front().number++] = object;
}

size_t Leaf::count_objects() {
    return Bucket::BUCKET_LENGTH * (bucket_list.size() - 1) + bucket_list.front().number;
}

void Leaf::print() {
    cout << "{";
    for (const auto &b : bucket_list)
        for_each(b.objects, b.objects + b.number,
                 [](const Object &o) { cout << "(" << o.id << ", " << o.x << ", " << o.y << ") "; });
    cout << "}" << endl;
}

void Leaf::all_objects(vector<Object> &objects) {
    for (const auto &b : bucket_list)
        copy(b.objects, b.objects + b.number, back_inserter(objects));
}

void Leaf::balance_if_necessary() {
    if (should_balance()) balance();
}
