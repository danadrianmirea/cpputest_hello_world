#ifndef DISCOUNT_PROVIDER_INTERFACE_H
#define DISCOUNT_PROVIDER_INTERFACE_H

// discount_provider.h
struct IDiscountProviderInterface
{
    virtual ~IDiscountProviderInterface() = default;
    virtual int getDiscountPercent() = 0;
};

#endif