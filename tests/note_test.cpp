#include <limits.h>
#include "../src/note.h"
#include "gtest/gtest.h"

TEST(NoteConstructorTest, Default){
    // Test the default note constructor.
    Note note;

    EXPECT_EQ(0x00, note.pitch().value());
    EXPECT_EQ(0x00, note.velocity().value());
    EXPECT_EQ(0x70, note.pan().value());
    EXPECT_EQ(0x00, note.delay());
    EXPECT_EQ(0x00, note.editor_fx_cmd());
}

TEST(NoteConstructorTest, CustomPitch){
    // Test the note(unsigned char pitch) constructor.
    Note note(0x47);

    EXPECT_EQ(0x47, note.pitch().value());
    EXPECT_EQ(0x00, note.velocity().value());
    EXPECT_EQ(0x70, note.pan().value());
    EXPECT_EQ(0x00, note.delay());
    EXPECT_EQ(0x00, note.editor_fx_cmd());
}

TEST(NoteConstructorTest, CustomVelocity){
    // Test the note(unsigned char pitch,
    //               unsigned char velocity) constructor.
    Note note(0x47, 0xd5);

    EXPECT_EQ(0x47, note.pitch().value());
    EXPECT_EQ(0xd5, note.velocity().value());
    EXPECT_EQ(0x70, note.pan().value());
    EXPECT_EQ(0x00, note.delay());
    EXPECT_EQ(0x00, note.editor_fx_cmd());
}

TEST(NoteConstructorTest, CustomPan){
    // Test the note(unsigned char pitch,
    //               unsigned char velocity,
    //               unsigned char pan) constructor.
    Note note(0x47, 0xd5, 0x38);

    EXPECT_EQ(0x47, note.pitch().value());
    EXPECT_EQ(0xd5, note.velocity().value());
    EXPECT_EQ(0x38, note.pan().value());
    EXPECT_EQ(0x00, note.delay());
    EXPECT_EQ(0x00, note.editor_fx_cmd());
}

TEST(NoteConstructorTest, CustomDelay){
    // Test the note(unsigned char pitch,
    //               unsigned char velocity,
    //               unsigned char pan,
    //               unsigned char delay) constructor.
    Note note(0x47, 0xd5, 0x38, 0x12);

    EXPECT_EQ(0x47, note.pitch().value());
    EXPECT_EQ(0xd5, note.velocity().value());
    EXPECT_EQ(0x38, note.pan().value());
    EXPECT_EQ(0x12, note.delay());
    EXPECT_EQ(0x00, note.editor_fx_cmd());
}


TEST(NotePitchTest, NumConstructor){
    // Test the pitch via the Note(unsigned char pitch) constructor.
    Note note(0x2b);

    EXPECT_EQ(0x2b, note.pitch().value());
}

TEST(NotePitchTest, StringConstructor){
    // Test the pitch via the Note(unsigned char pitch) constructor.
    Note note("62");

    EXPECT_EQ(0x4a, note.pitch().value());
}

TEST(NotePitchTest, NumMethod){
    // Test the pitch via the note(unsigned char new_pitch) method.
    Note note;
    note.pitch(0x28);

    EXPECT_EQ(0x28, note.pitch().value());
}

TEST(NotePitchTest, StringMethod){
    // Test the pitch via the note(string new_pitch) method.
    Note note;
    note.pitch("3a");

    EXPECT_EQ(0x2e, note.pitch().value());
}

TEST(NotePitchTest, StringMethodInvalidChars){
    // Test the pitch via the note(string new_pitch) method,
    // including invalid characters that should be handled
    // appropriately.
    Note note;
    note.pitch("3q");

    EXPECT_EQ(0x2f, note.pitch().value());

    note.pitch("pl");

    EXPECT_EQ(0x79, note.pitch().value());
}


TEST(NoteVelocityTest, Constructor){
    // Test the velocity via the 
    // Note(unsigned char pitch,
    //      unsigned char velocity) constructor.
    Note note(0x4b, 0xb5);

    EXPECT_EQ(0xb5, note.velocity().value());
}

TEST(NoteVelocityTest, Method){
    // Test the velocity via the 
    // velocity(unsigned char new_velocity) method.
    Note note;

    EXPECT_EQ(0x00, note.velocity().value());

    note.velocity(0xc2);

    EXPECT_EQ(0xc2, note.velocity().value());
}


TEST(NotePanTest, Constructor){
    // Test the pan via the 
    // Note(unsigned char pitch,
    //      unsigned char velocity,
    //      unsigned char pan) constructor.
    Note note(0x4b, 0x80, 0x38);

    EXPECT_EQ(0x38, note.pan().value());
}

TEST(NotePanTest, Method){
    // Test the pan via the 
    // pan(unsigned char new_pan) method.
    Note note;

    note.pan(0xc2);

    EXPECT_EQ(0xc2, note.pan().value());
}

TEST(NotePanTest, MethodInvalidValue){
    // Test the pan via the pan(unsigned char new_pan)
    // method, with a value higher than the maximum value.
    Note note;

    note.pan(0xff);

    EXPECT_EQ(0xe0, note.pan().value());
}


TEST(NoteDelayTest, Constructor){
    // Test the delay via the 
    // Note(unsigned char pitch,
    //      unsigned char velocity,
    //      unsigned char pan,
    //      unsigned char delay) constructor.
    Note note(0x4b, 0xb5, 0x70, 0x12);

    EXPECT_EQ(0x12, note.delay());
}

TEST(NoteDelayTest, Method){
    // Test the delay via the 
    // delay(unsigned char new_delay) method.
    Note note;

    note.delay(0xc2);

    EXPECT_EQ(0xc2, note.delay());
}
