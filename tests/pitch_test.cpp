#include <limits.h>
#include "../src/pitch.h"
#include "gtest/gtest.h"

TEST(PitchConstructorTest, Default){
  // Test the default pitch constructor.
  Pitch pitch;

  EXPECT_EQ(0x48, pitch.value());
}

TEST(PitchConstructorTest, NumConstructor){
  // Test the pitch(Pitch::t_pitch value) constructor.
  Pitch pitch(0x47);

  EXPECT_EQ(0x47, pitch.value());
}

TEST(PitchConstructorTest, StringConstructor){
  // Test the pitch(string value) constructor.
  Pitch pitch("47");

  EXPECT_EQ(0x37, pitch.value());
}

TEST(PitchValueTest, Methods){
  Pitch pitch;

  EXPECT_EQ(0x48, pitch.value());

  pitch.value(0x39);
  EXPECT_EQ(0x39, pitch.value());

  pitch.value("2a");
  EXPECT_EQ(0x22, pitch.value());

  pitch.value("2a");
  EXPECT_EQ(0x22, pitch.value());

  pitch.value("ff");
  EXPECT_EQ(0x79, pitch.value());
}

TEST(PitchStringTest, ToString){
  // Test the to_string(bool upper) method.
  Pitch pitch;

  // default 
  EXPECT_EQ(72, pitch.value());
  EXPECT_EQ(0x48, pitch.value());
  EXPECT_EQ("60", pitch.to_string()); // duodecimal notation
                                      // 6x12 == 72 == 0x48

  // set via .value(string new_value) method
  pitch.value("62");
  EXPECT_EQ("62", pitch.to_string());
  EXPECT_EQ("62", pitch.to_string(false));
  EXPECT_EQ("62", pitch.to_string(true));

  // set to value with alphabet digits
  pitch.value("6a");
  EXPECT_EQ("6a", pitch.to_string());
  EXPECT_EQ("6a", pitch.to_string(false));
  EXPECT_EQ("6A", pitch.to_string(true));

  pitch.value("ab");
  EXPECT_EQ("ab", pitch.to_string());
  EXPECT_EQ("ab", pitch.to_string(false));
  EXPECT_EQ("AB", pitch.to_string(true));
}
