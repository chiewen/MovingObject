//
// Created by chiewen on 2015/8/18.
//

#ifndef MOVINGOBJECT_DATAGENERATOR_H
#define MOVINGOBJECT_DATAGENERATOR_H

#include <vector>
#include "../QuadTree/object.h"

using namespace std;

class DataGenerator {
public:
    static void generate_ordinary(size_t num, float width, float height, vector<Object> &objects);
};


#endif //MOVINGOBJECT_DATAGENERATOR_H
