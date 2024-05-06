#include <gtest/gtest.h>
#include "singleDirList.h"
#include <sstream>

TEST(ListTest, test_default_constructor){
    SDList testList = SDList<int>();
    ASSERT_TRUE(testList.empty());
}

TEST(ListTest, test_copy_constructor){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(2);
    SDList testList2 = testList;
    testList.pushFront(3);
    ASSERT_EQ(testList2.size(), 2);
}

TEST(ListTest, test_assign_operator){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(2);
    SDList<int> testList2;
    testList2 = testList;
    testList.pushFront(3);
    ASSERT_EQ(testList2.size(), 2);
}

TEST(ListTest, test_size){
    SDList testList = SDList<int>();
    ASSERT_EQ(testList.size(), 0);
    testList.pushFront(2);
    testList.pushFront(2);
    testList.pushFront(2);
    ASSERT_EQ(testList.size(), 3);
    testList.popFront();
    ASSERT_EQ(testList.size(), 2);
}

TEST(ListTest, test_pop_front_empty){
    SDList testList = SDList<int>();
    ASSERT_TRUE(testList.empty());
    testList.popFront();
    ASSERT_TRUE(testList.empty());
}

TEST(ListTest, test_clear){
    SDList testList = SDList<int>();
    testList.pushFront(2);
    testList.pushFront(2);
    testList.pushFront(2);
    ASSERT_EQ(testList.size(), 3);
    testList.clear();
    ASSERT_EQ(testList.size(), 0);
}

TEST(ListTest, test_move_constructor){
    SDList testList = SDList<int>(SDList<int>());
    ASSERT_EQ(testList.size(), 0);
}

TEST(ListTest, test_forward_iterator){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(2);
    testList.pushFront(3);
    int counter = 0;
    auto it = testList.begin();
    ASSERT_EQ(*it, 3);
    it++;
    ASSERT_EQ(*it, 2);
    it++;
    ASSERT_EQ(*it, 1);
}

TEST(ListTest, test_insert){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(2);
    testList.pushFront(4);
    int counter = 0;
    auto it = testList.begin();
    testList.insert(it, 3);
    ASSERT_EQ(testList.size(), 4);
    it++;
    ASSERT_EQ(*it, 3);
}

TEST(ListTest, test_remove_start){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(3);
    testList.pushFront(4);
    int counter = 0;
    auto it = testList.begin();
    testList.remove(it);
    ASSERT_EQ(testList.size(), 2);
    ASSERT_EQ(*testList.begin(), 3);
}

TEST(ListTest, test_remove){
    SDList testList = SDList<int>();
    testList.pushFront(1);
    testList.pushFront(3);
    testList.pushFront(4);
    int counter = 0;
    auto it = testList.begin();
    it++;
    testList.remove(it);
    ASSERT_EQ(testList.size(), 2);
    ASSERT_EQ(*testList.begin(), 4);
}