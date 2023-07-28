#ifndef ELIGIBILITY_SERVICE_HPP
#define ELIGIBILITY_SERVICE_HPP

#include <string>

class EligibilityService {
public:
    enum Eligibility {
        CUSTOMER_ELIGIBLE,
        CUSTOMER_INELIGIBLE,
        TECHNICAL_FAILURE
    };

    virtual Eligibility checkEligibility(const std::string& accountNumber) const = 0;
};

#endif // ELIGIBILITY_SERVICE_HPP
