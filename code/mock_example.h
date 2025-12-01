#ifndef MOCK_EXAMPLE_H
#define MOCK_EXAMPLE_H

#include "discount_provider_interface.h"

// Very small example that conceptually needs mocking:
// we want to compute a price using a discount that normally would be
// fetched from some external system (database, HTTP service, etc.).
int calculate_price_with_remote_discount(int basePrice);

// Another example that uses a discount provider interface to calculate the price
// This example demonstrates the use of a mock for the discount provider interface via dependency injection
int calculate_price_with_provider(int basePrice, IDiscountProviderInterface& provider);


#endif // MOCK_EXAMPLE_H