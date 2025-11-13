#include <gtest/gtest.h>
#include "../src/stringProcessor.h"

TEST(StringProcessorTest, UpperCase) {
    EXPECT_EQ(toUpperCase("abc"), "ABC");
    EXPECT_EQ(toUpperCase("HeLLo"), "HELLO");
    EXPECT_EQ(toUpperCase("Jenkins"), "JENKINS");
}
