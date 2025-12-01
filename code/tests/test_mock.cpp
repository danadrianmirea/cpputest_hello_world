#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

#include "mock_example.h"

// Test-side implementation of the external dependency.
// This is what production code will call during tests.
int fetch_remote_discount_percentage()
{
    return mock().actualCall("fetch_remote_discount_percentage").returnIntValue();
}

TEST_GROUP(MockExampleGroup)
{
    void teardown() override
    {
        // Verify that all expectations were met and clear the mock state
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(MockExampleGroup, AppliesRemoteDiscountFromMock)
{
    // Arrange: remote system is expected to be queried once and returns 20% discount
    mock().expectOneCall("fetch_remote_discount_percentage")
          .andReturnValue(20);

    // Act
    int result = calculate_price_with_remote_discount(100);

    // Assert
    LONGS_EQUAL(80, result);
}


