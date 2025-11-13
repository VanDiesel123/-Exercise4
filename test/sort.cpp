#include <gtest/gtest.h>
#include "../src/sort.h"

TEST(SortTest, CorrectOrder) {
    int arr[] = {3, 1, 2};
    sortArray(arr, 3);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}
