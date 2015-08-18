//
// Created by chiewen on 2015/8/18.
//

#include <random>
#include "DataGenerator.h"

vector<Object> DataGenerator::generate_ordinary(size_t num, float width, float height) {
    vector<Object> objects;
    objects.reserve(num);

    default_random_engine dre;
    uniform_real_distribution<float> dr_x(0, width);
    uniform_real_distribution<float> dr_y(0, height);

    for (size_t i = 0; i < num; i++)
        objects.push_back({i, dr_x(dre), dr_y(dre)});

    return objects;
}
