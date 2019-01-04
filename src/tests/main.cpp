#include <gtest/gtest.h>
#include <jerboa/jerboa.h>

TEST(ExampleTests, FailTest)
{
    FAIL() << "The test has successfully failed.";
}

TEST(ExampleTests, SucceedTest)
{
    SUCCEED();
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
