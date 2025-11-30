#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"
#include "add.h"

TEST_GROUP(AddTest)
{
};

TEST(AddTest, AddTwoAndThreeShouldEqualFive)
{
    int32_t result = add(2, 3);
    CHECK_EQUAL(5, result);
}

// CppUTest main function
int main(int ac, char** av)
{
    return CommandLineTestRunner::RunAllTests(ac, av);
}

