#include "gtest/gtest.h"
#include "bridge_util.h"

TEST (UtilTest, getRandom_basic)
{
    for (int i = 0; i < 100; ++i)
    {
        auto r = getRandom();
        EXPECT_LE(r, CARD_COUNT);
    }
}

TEST (UtilTest, getRandom_in_range_basic)
{
    int low =  13;
    int high = 37;

    for (int i = 0; i < 100; ++i)
    {
        auto r = getRandom(low, high);
        EXPECT_LE(r, high);
        EXPECT_GE(r, low);
    }
}

TEST (UtilTest, getRandom_is_really_random)
{
    int prev = -1;
    for (int i = 0; i < 10; ++i)
    {
        auto r = getRandom();
        EXPECT_NE(r, prev);
        prev = r;
    }
}
