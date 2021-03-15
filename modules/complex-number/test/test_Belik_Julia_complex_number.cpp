// Copyright 2021 Belik Julia

#include <gtest/gtest.h>

#include <tuple>
#include "include/complex_number.h"

TEST(Belik_Julia_ComplexNumberTest, Can_Copy) {
    // Arrange
    ComplexNumber a(15.0, -42.0);

    // Act
    ComplexNumber b(a);
    bool c = a == b;

    // Assert
    EXPECT_TRUE(c);
}
TEST(Belik_Julia_ComplexNumberTest, Conjugate_Numbers_Multiplication) {
    // Arrange
    ComplexNumber a(5, 1);
    ComplexNumber b(5, -1);

    // Act
    ComplexNumber c = a * b;

    // Assert
    EXPECT_EQ(c.getRe(), 26);
    EXPECT_EQ(c.getIm(), 0);
}
typedef testing::TestWithParam<std::tuple<double, double>>
Belik_Julia_ComplexNumberTest_Param;
TEST_P(Belik_Julia_ComplexNumberTest_Param, Test_Equal) {
    // Arrange
    double re = std::get<0>(GetParam());
    double im = std::get<1>(GetParam());
    ComplexNumber a(re, im);
    ComplexNumber b(re, im);

    // Act
    bool c = a == b;

    // Assert
    EXPECT_TRUE(c);
}
INSTANTIATE_TEST_CASE_P(/**/, Belik_Julia_ComplexNumberTest_Param,
    testing::Combine(
    testing::Values(-17.0, 2.0),
    testing::Values(8.0, -4.0)
));
