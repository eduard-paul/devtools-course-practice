// Copyright 2014 Paul Eduard

#include <gtest/gtest.h>
#include <stdint.h>
#include <vector>
#include <climits>


#include "include/merge-sort.h"

TEST(MergeSortTest, Zero_Elements_For_Sort) {
    // Arrange
    std::vector<int64_t> a(5);
    for (unsigned int i = 0; i < 5; i++) {
        a[i] = static_cast<int64_t>(i);
    }
    // Act
    a = Merge_Sort(a, 0, 0);
    // Assert
    EXPECT_EQ(0, a[0]);
    EXPECT_EQ(1, a[1]);
    EXPECT_EQ(2, a[2]);
    EXPECT_EQ(3, a[3]);
    EXPECT_EQ(4, a[4]);
}
TEST(MergeSortTest, Swapped_Left_Right_Borders) {
    // Arrange
    std::vector<int64_t> a(5);
    for (unsigned int i = 0; i < 5; i++) {
        a[i] = static_cast<int64_t>(i);
    }
    // Act
    a = Merge_Sort(a, 3, 1);
    // Assert
    EXPECT_EQ(0, a[0]);
    EXPECT_EQ(1, a[1]);
    EXPECT_EQ(2, a[2]);
    EXPECT_EQ(3, a[3]);
    EXPECT_EQ(4, a[4]);
}
TEST(MergeSortTest, Partial_Sort) {
    // Arrange
    std::vector<int64_t> a(5);
    for (unsigned int i = 0; i < 5; i++) {
        a[i] = static_cast<int64_t>(5 - i);
    }
    // Act
    a = Merge_Sort(a, 1, 3);
    // Assert
    EXPECT_EQ(5, a[0]);
    EXPECT_EQ(2, a[1]);
    EXPECT_EQ(3, a[2]);
    EXPECT_EQ(4, a[3]);
    EXPECT_EQ(1, a[4]);
}
TEST(MergeSortTest, Full_Sort) {
    // Arrange
    const int N = 1000;
    std::vector<int64_t> a(N);
    for (unsigned int i = 0; i < N; i++) {
        a[i] = static_cast<int64_t>(N - i);
    }
    // Act
    a = Merge_Sort(a, 0, N-1);
    // Assert
    for (unsigned int i = 0; i < N; i++) EXPECT_EQ(i+1, a[i]);
}
TEST(MergeSortTest, GreetingsFromSergei) {
    // Arrange
    std::vector<int64_t> a(5);

    a[0] = INT_MAX;
    a[1] = INT_MAX;
    a[2] = INT_MAX;
    a[3] = INT_MAX;
    a[4] = INT_MAX;

    // Act
    a = Merge_Sort(a, 0, 4);
    // Assert
    EXPECT_EQ(INT_MAX, a[0]);
    EXPECT_EQ(INT_MAX, a[1]);
    EXPECT_EQ(INT_MAX, a[2]);
    EXPECT_EQ(INT_MAX, a[3]);
    EXPECT_EQ(INT_MAX, a[4]);
}
