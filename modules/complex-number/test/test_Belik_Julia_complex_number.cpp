// Copyright 2021 Belik Julia

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Belik_Julia_ComplexNumberTest, Can_SetGet_Im) {
    // Arrange
    ComplexNumber z;

    // Act
    z.setIm(15);

    // Assert
    EXPECT_EQ(15, z.getIm());
}
TEST(Belik_Julia_ComplexNumberTest, Conjugate_Numbers_Multiplication) {
    // Arrange
    ComplexNumber a(5, 1);
    ComplexNumber b(5, -1);

    // Assert
    EXPECT_EQ((a * b).getRe(), 26);
    EXPECT_EQ((a * b).getIm(), 0);
}
TEST(Belik_Julia_ComplexNumberTest, Test_Equal) {
    // Arrange
    double re1 = 5;
    double im1 = 7;
    double re2 = 5;
    double im2 = 7;
    ComplexNumber a(re1, im1);
    ComplexNumber b(re2, im2);

    // Assert
    EXPECT_TRUE(a == b);
}
