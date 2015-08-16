//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_BUCKET_H
#define MOVINGOBJECT_BUCKET_H

#include "object.h"

struct Bucket {
    //TODO find proper objects number to make one bucket (along with an associated pointer?) fit in a word.
    static constexpr int BUCKET_LENGTH = 7;

    int number = 0;
    Object objects[BUCKET_LENGTH];
};

#endif //MOVINGOBJECT_BUCKET_H