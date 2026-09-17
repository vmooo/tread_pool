#include <gtest/gtest.h>

extern "C" {
    #include "tread_pool.h"
}

TEST(test, test1) {
    ASSERT_TRUE(test() == 1);
}
