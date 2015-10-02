#include <limits.h>
#include "../src/pitch.h"
#include "gtest/gtest.h"

TEST(PitchConstructorTest, Default){
    // Test the default pitch constructor.
    Note note;

    EXPECT_EQ(0x48, note.pitch());
}

TEST(PitchConstructorTest, NumConstructor){
    // Test the pitch(Pitch::t_pitch value) constructor.
    Note note(0x47);

    EXPECT_EQ(0x47, note.pitch());
}

TEST(PitchConstructorTest, StringConstructor){
    // Test the pitch(string value) constructor.
    Note note(0x47);

    EXPECT_EQ(0x47, note.pitch());
}
