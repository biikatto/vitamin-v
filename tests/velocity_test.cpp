#include <limits.h>
#include "../src/velocity.h"
#include "gtest/gtest.h"

TEST(VelocityConstructorTest, Default){
  // Test the default velocity constructor.
  Velocity velocity;

  EXPECT_EQ(0xc0, velocity.value());
}

TEST(VelocityConstructorTest, NumConstructor){
  // Test the velocity(Velocity::t_velocity value) constructor.
  Velocity velocity(0x47);

  EXPECT_EQ(0x47, velocity.value());
}

TEST(VelocityConstructorTest, StringConstructor){
  // Test the velocity(string value) constructor.
  Velocity velocity("49");

  EXPECT_EQ(0x49, velocity.value());
}

TEST(VelocityValueTest, Methods){
  Velocity velocity;

  EXPECT_EQ(0xc0, velocity.value());

  velocity.value(0x39);
  EXPECT_EQ(0x39, velocity.value());

  velocity.value("2a");
  EXPECT_EQ(0x2a, velocity.value());

  velocity.value("b7");
  EXPECT_EQ(0xb7, velocity.value());

  velocity.value("0f");
  EXPECT_EQ(0x0f, velocity.value());

  velocity.value("fff");
  EXPECT_EQ(0xff, velocity.value());
}

TEST(VelocityStringTest, ToString){
  // Test the to_string(bool upper) method.
  Velocity velocity;

  // default 
  EXPECT_EQ(192, velocity.value());
  EXPECT_EQ(0xc0, velocity.value());
  EXPECT_EQ("c0", velocity.to_string());

  // set via .value(string new_value) method
  velocity.value("62");
  EXPECT_EQ("62", velocity.to_string());
  EXPECT_EQ("62", velocity.to_string(false));
  EXPECT_EQ("62", velocity.to_string(true));

  // set to value with alphabet digits
  velocity.value("6a");
  EXPECT_EQ("6a", velocity.to_string());
  EXPECT_EQ("6a", velocity.to_string(false));
  EXPECT_EQ("6A", velocity.to_string(true));

  velocity.value("db");
  EXPECT_EQ("db", velocity.to_string());
  EXPECT_EQ("db", velocity.to_string(false));
  EXPECT_EQ("DB", velocity.to_string(true));
}
