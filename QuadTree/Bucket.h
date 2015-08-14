//
// Created by chiewen on 2015/8/14.
//

#ifndef MOVINGOBJECT_BUCKET_H
#define MOVINGOBJECT_BUCKET_H

#include "object.h"

struct Bucket {
//TODO find proper number of objects to make one slot fit in a word.
    Object objects[6];

};

#endif //MOVINGOBJECT_BUCKET_H