#include "EligibilityService.hpp"

class MockEligibilityService : public EligibilityService {
public:
    Eligibility checkEligibility(const std::string& accountNumber) const override {
        // For simplicity, assume all accounts starting with 'E' are eligible,
        // and all others are not eligible.
        if (accountNumber.front() == 'E')
            return CUSTOMER_ELIGIBLE;
        else
            return CUSTOMER_INELIGIBLE;
    }
};
