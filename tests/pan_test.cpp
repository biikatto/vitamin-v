#include <limits.h>
#include "../src/pan.h"
#include "gtest/gtest.h"

TEST(PanConstructorTest, Default){
  // Test the default pan constructor.
  Pan pan;

  EXPECT_EQ(0x70, pan.value());
}

TEST(PanConstructorTest, NumConstructor){
  // Test the pan(Pan::t_pan value) constructor.
  Pan pan(0x47);

  EXPECT_EQ(0x47, pan.value());
}

TEST(PanConstructorTest, StringConstructor){
  // Test the pan(string value) constructor.
  Pan pan("49");

  EXPECT_EQ(0x49, pan.value());
}

TEST(PanValueTest, Methods){
  Pan pan;

  EXPECT_EQ(0x70, pan.value());

  pan.value(0x39);
  EXPECT_EQ(0x39, pan.value());

  pan.value("2a");
  EXPECT_EQ(0x2a, pan.value());

  pan.value("b7");
  EXPECT_EQ(0xb7, pan.value());

  pan.value("0f");
  EXPECT_EQ(0x0f, pan.value());

  pan.value("fff");
  EXPECT_EQ(0xe0, pan.value());
}

TEST(PanStringTest, ToString){
  // Test the to_string(bool upper) method.
  Pan pan;

  // default 
  EXPECT_EQ(112, pan.value());
  EXPECT_EQ(0x70, pan.value());
  EXPECT_EQ("70", pan.to_string());

  // set via .value(string new_value) method
  pan.value("62");
  EXPECT_EQ("62", pan.to_string());
  EXPECT_EQ("62", pan.to_string(false));
  EXPECT_EQ("62", pan.to_string(true));

  // set to value with alphabet digits
  pan.value("6a");
  EXPECT_EQ("6a", pan.to_string());
  EXPECT_EQ("6a", pan.to_string(false));
  EXPECT_EQ("6A", pan.to_string(true));

  pan.value("db");
  EXPECT_EQ("db", pan.to_string());
  EXPECT_EQ("db", pan.to_string(false));
  EXPECT_EQ("DB", pan.to_string(true));
}

TEST(PanConstantsTest, Constants){
  // Test the constants in the Pan class.
  EXPECT_EQ(0x00, Pan::HARD_LEFT);
  EXPECT_EQ(0x38, Pan::HALF_LEFT);
  EXPECT_EQ(0x70, Pan::CENTER);
  EXPECT_EQ(0xa8, Pan::HALF_RIGHT);
  EXPECT_EQ(0xe0, Pan::HARD_RIGHT);

  Pan pan;
  EXPECT_EQ(Pan::CENTER, pan.value());
  
  pan.value(Pan::HARD_LEFT);
  EXPECT_EQ(Pan::HARD_LEFT, pan.value());

  pan.value(Pan::HALF_RIGHT);
  EXPECT_EQ(Pan::HALF_RIGHT, pan.value());
}
