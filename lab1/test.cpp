//
// Created by Kirill on 14.11.2021.
//

#include <gtest/gtest.h>
#include "TritSet.h"

class TestTritSet : public ::testing::Test {
public:
    mylab1::TritSet set = mylab1::TritSet(2222);
    size_t allocLength;
    void SetUp(){

        allocLength = set.getSize();
    }
    void TearDown(){

    }
};


TEST(SuiteName, TestName) {
    EXPECT_EQ(1, 1);    // проверка на равенство
    //EXPECT_GT(1, 2);     // ожидается, что 1 > 2
}

TEST_F(TestTritSet, CapacityTest) {
    EXPECT_GE(allocLength, set.getSize());
}

TEST_F(TestTritSet, TritAssigmentTest) {
    const mylab1::Trit trit1 = mylab1::TRUE;
    set[20] = mylab1::TRUE;
    EXPECT_GE(trit1, static_cast<mylab1::Trit>(set[20]));
}

TEST_F(TestTritSet, CellAssigmentTest) {
    set[20] = mylab1::TRUE;
    set[21] = mylab1::TRUE;

    EXPECT_GE(static_cast<mylab1::Trit>(set[21]), static_cast<mylab1::Trit>(set[20]));
}

TEST_F(TestTritSet, TrimTest) {
    set[2000] = mylab1::TRUE;
    set.trim(1900);
    ASSERT_LE(set.getSize(), 2000);
}

TEST_F(TestTritSet, CardinalityAnorderedTest) {
    set[2000] = mylab1::TRUE;
    set[2001] = mylab1::TRUE;
    ASSERT_GE(set.cardinality()[mylab1::TRUE], 2);
    ASSERT_GE(set.cardinality()[mylab1::FALSE], 0);
    ASSERT_GE(set.cardinality()[mylab1::UNKNOWN], set.getSize() - 2);
}

TEST_F(TestTritSet, ShrinkTest) {
    int index = 1815;
    set[index] = mylab1::TRUE;
    set.shrink();
    ASSERT_GE((index - index%16) + 16, set.getSize());
}

TEST_F(TestTritSet, AllocTest) {
    //не выделяет никакой памяти
    set[1000000000] = mylab1::UNKNOWN;
    ASSERT_GE(allocLength, set.getSize());

// false, but no exception or memory allocation
    if(set[2000000000]==mylab1::TRUE){}
    assert(allocLength == set.getSize());

//выделение памяти
    set[1000000000] = mylab1::TRUE;
    assert(allocLength < set.getSize());

//no memory operations
    allocLength = set.getSize();
    set[1000000000] = mylab1::UNKNOWN;
    set[1000000] = mylab1::FALSE;
    assert(allocLength == set.getSize());
}

TEST_F(TestTritSet, LogicTest) {
    mylab1::TritSet setA(1000);
    mylab1::TritSet setB(2000);
    mylab1::TritSet setC = setA & setB;
    ASSERT_LE(setC.getSize(), setB.getSize());
}
