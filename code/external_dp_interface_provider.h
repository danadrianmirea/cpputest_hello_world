#ifndef EXTERNAL_DP_INTERFACE_PROVIDER_H
#define EXTERNAL_DP_INTERFACE_PROVIDER_H

#include "discount_provider_interface.h"

class ExternalDPInterfaceProvider : public IDiscountProviderInterface
{
public:
    int getDiscountPercent() override;
};

#endif