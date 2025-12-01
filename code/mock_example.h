#ifndef MOCK_EXAMPLE_H
#define MOCK_EXAMPLE_H

// Very small example that conceptually needs mocking:
// we want to compute a price using a discount that normally would be
// fetched from some external system (database, HTTP service, etc.).
int calculate_price_with_remote_discount(int basePrice);

#endif // MOCK_EXAMPLE_H


