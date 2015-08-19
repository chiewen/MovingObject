//
// Created by chiewen on 2015/8/18.
//

#include <random>
#include <algorithm>
#include "DataGenerator.h"

void DataGenerator::generate_ordinary(size_t num, float width, float height, vector<Object> &objects) {
    objects.reserve(num);

    default_random_engine dre;
    uniform_real_distribution<float> dr_x(0, width);
    uniform_real_distribution<float> dr_y(0, height);

    generate_n(back_inserter(objects), num, [&]() {
        static size_t i = 0;
        return Object{i++, dr_x(dre), dr_y(dre)};
    });
}
