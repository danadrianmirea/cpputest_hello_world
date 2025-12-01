#include "mock_example.h"
#include "external_discount.h"

int calculate_price_with_remote_discount(int basePrice)
{
    int discountPercent = fetch_remote_discount_percentage();
    return basePrice - (basePrice * discountPercent) / 100;
}