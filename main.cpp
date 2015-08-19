#include "test/TestTree.h"
#include "gtest/gtest.h"
#include "QuadTree/quadtree.h"
#include "DataGenerator/DataGenerator.h"

using namespace std;


QuadTree qt;
vector<Object> data;

TEST (QuadTreeTest, Size) {
EXPECT_EQ (2000, qt.root.count_objects());
}


int main(int argc, char **argv) {
//    TestTree testTree;
//    testTree.test();
    DataGenerator::generate_ordinary(2000, QuadTree::WIDTH, QuadTree::HEIGHT, data);
    qt.root.insert_object_range(data.begin(), data.end());
    qt.root.balance_if_necessary();

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}