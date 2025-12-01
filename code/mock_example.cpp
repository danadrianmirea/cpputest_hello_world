#include "mock_example.h"
#include "external_discount.h"

int calculate_price_with_remote_discount(int basePrice)
{
    int discountPercent = fetch_remote_discount_percentage();
    return basePrice - (basePrice * discountPercent) / 100;
}

int calculate_price_with_provider(int basePrice, IDiscountProviderInterface& provider)
{
    int discountPercent = provider.getDiscountPercent();
    return basePrice - (basePrice * discountPercent) / 100;
}