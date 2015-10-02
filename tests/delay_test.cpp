#include <limits.h>
#include "../src/delay.h"
#include "gtest/gtest.h"

TEST(DelayConstructorTest, Default){
  // Test the default delay constructor.
  Delay delay;

  EXPECT_EQ(0xc0, delay.value());
}

TEST(DelayConstructorTest, NumConstructor){
  // Test the delay(Delay::t_delay value) constructor.
  Delay delay(0x47);

  EXPECT_EQ(0x47, delay.value());
}

TEST(DelayConstructorTest, StringConstructor){
  // Test the delay(string value) constructor.
  Delay delay("49");

  EXPECT_EQ(0x49, delay.value());
}

TEST(DelayValueTest, Methods){
  Delay delay;

  EXPECT_EQ(0xc0, delay.value());

  delay.value(0x39);
  EXPECT_EQ(0x39, delay.value());

  delay.value("2a");
  EXPECT_EQ(0x2a, delay.value());

  delay.value("b7");
  EXPECT_EQ(0xb7, delay.value());

  delay.value("0f");
  EXPECT_EQ(0x0f, delay.value());

  delay.value("fff");
  EXPECT_EQ(0xff, delay.value());
}

TEST(DelayStringTest, ToString){
  // Test the to_string(bool upper) method.
  Delay delay;

  // default 
  EXPECT_EQ(192, delay.value());
  EXPECT_EQ(0xc0, delay.value());
  EXPECT_EQ("c0", delay.to_string());

  // set via .value(string new_value) method
  delay.value("62");
  EXPECT_EQ("62", delay.to_string());
  EXPECT_EQ("62", delay.to_string(false));
  EXPECT_EQ("62", delay.to_string(true));

  // set to value with alphabet digits
  delay.value("6a");
  EXPECT_EQ("6a", delay.to_string());
  EXPECT_EQ("6a", delay.to_string(false));
  EXPECT_EQ("6A", delay.to_string(true));

  delay.value("db");
  EXPECT_EQ("db", delay.to_string());
  EXPECT_EQ("db", delay.to_string(false));
  EXPECT_EQ("DB", delay.to_string(true));
}
