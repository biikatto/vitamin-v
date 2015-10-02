#include <limits.h>
#include "../src/pattern.h"
#include "gtest/gtest.h"

TEST(PatternConstructorTest, Default){
  // Test the default constructor.
  Pattern pattern;

  EXPECT_EQ(64, pattern.length());
}

TEST(PatternConstructorTest, CustomLength){
  // Test the constructor Pattern(int length)
  Pattern pattern(32);

  EXPECT_EQ(32, pattern.length());
}

TEST(PatternLengthTest, DefaultConstructorLength){
  // Test the length for the default constructor.
  Pattern pattern;

  EXPECT_EQ(64, pattern.length());
}

TEST(PatternLengthTest, ConstructorLength){
  // Test the length for the default constructor.
  Pattern pattern(53);

  EXPECT_EQ(53, pattern.length());
}

TEST(PatternLengthTest, LengthMethod){
  // Test the length(int new_length) method, where
  // the new length is greater than the previous length.
  Pattern pattern;
  pattern.length(76);

  EXPECT_EQ(76, pattern.length());
  EXPECT_EQ(76, pattern.vector_length());
}

TEST(PatternLengthTest, LengthMethodNondestructiveResize){
  // Test non-destructive resize behavior

  Pattern pattern;

  // default value
  EXPECT_EQ(64, pattern.length());

  pattern.length(42);

  // new value
  EXPECT_EQ(42, pattern.length()); 

  // vector length should remain at previous value
  EXPECT_EQ(64, pattern.vector_length()); 

  // set some note value toward the end of the pattern
  pattern[38].pitch().value("12");

  // set length so our note should no longer be accessible
  pattern.length(24);

  // our note should not be accessible
  EXPECT_THROW(pattern[38], std::out_of_range);

  // resize again
  pattern.length(64);

  // we can now access our intact note information again
  EXPECT_EQ("12", pattern[38].pitch().to_string());
}

TEST(PatternNoteAccessTest, ArrayAccessOperator){
  // Test the array access operator for accessing notes.
  Pattern pattern;

  Note note = pattern[0];

  EXPECT_EQ(0x00, note.pitch().value());

  for(Note note : pattern){
    EXPECT_EQ(0x00, note.pitch().value());
  }

  EXPECT_THROW(pattern[pattern.length()], std::out_of_range);
}

TEST(PatternNoteAccessTest, NoteReplace){
  // Test replacing a note in the pattern with a new note.
  Pattern pattern;

  pattern[0] = Note(0x72, 0xa8, 0x38, 0x00);

  EXPECT_EQ(0x72, pattern[0].pitch().value());
  EXPECT_EQ(0xa8, pattern[0].velocity().value());
  EXPECT_EQ(0x38, pattern[0].pan().value());
  EXPECT_EQ(0x00, pattern[0].delay());
  EXPECT_EQ(0x00, pattern[0].editor_fx_cmd());
}

TEST(PatternClearTest, ClearMethod){
  // Test the clear() method.
  Pattern pattern;

  for(unsigned int i=0;i<pattern.length();i++){
    pattern[i] = Note("3a");
    EXPECT_EQ("3a", pattern[i].pitch().to_string());
  }

  pattern.clear();

  for(unsigned int i=0;i<pattern.length();i++){
    EXPECT_EQ("00", pattern[i].pitch().to_string());
  }
}
