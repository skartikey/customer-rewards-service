#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "EligibilityService.hpp"
#include "RewardsService.hpp"

using namespace testing;

// Mock EligibilityService
class MockEligibilityService : public EligibilityService {
public:
    MOCK_CONST_METHOD1(checkEligibility, Eligibility(const std::string& accountNumber));
};

TEST(RewardsServiceTest, TestCustomerEligibleWithRewards) {
    MockEligibilityService mockEligibilityService;
    RewardsService rewardsService(mockEligibilityService);

    EXPECT_CALL(mockEligibilityService, checkEligibility("E123456")).WillOnce(Return(EligibilityService::CUSTOMER_ELIGIBLE));

    std::vector<std::string> subscriptions = {"SPORTS", "MUSIC", "MOVIES"};
    std::vector<RewardsService::Reward> rewards = rewardsService.getRewards("E123456", subscriptions);

    ASSERT_EQ(rewards.size(), 3);
    EXPECT_EQ(rewards[0], RewardsService::CHAMPIONS_LEAGUE_FINAL_TICKET);
    EXPECT_EQ(rewards[1], RewardsService::KARAOKE_PRO_MICROPHONE);
    EXPECT_EQ(rewards[2], RewardsService::PIRATES_OF_THE_CARIBBEAN_COLLECTION);
}

TEST(RewardsServiceTest, TestCustomerEligibleWithoutRewards) {
    MockEligibilityService mockEligibilityService;
    RewardsService rewardsService(mockEligibilityService);

    EXPECT_CALL(mockEligibilityService, checkEligibility("E654321")).WillOnce(Return(EligibilityService::CUSTOMER_ELIGIBLE));

    std::vector<std::string> subscriptions = {"KIDS", "NEWS"};
    std::vector<RewardsService::Reward> rewards = rewardsService.getRewards("E654321", subscriptions);

    ASSERT_EQ(rewards.size(), 0);
}

TEST(RewardsServiceTest, TestCustomerIneligible) {
    MockEligibilityService mockEligibilityService;
    RewardsService rewardsService(mockEligibilityService);

    EXPECT_CALL(mockEligibilityService, checkEligibility("C987654")).WillOnce(Return(EligibilityService::CUSTOMER_INELIGIBLE));

    std::vector<std::string> subscriptions = {"SPORTS", "MUSIC", "MOVIES"};
    std::vector<RewardsService::Reward> rewards = rewardsService.getRewards("C987654", subscriptions);

    ASSERT_EQ(rewards.size(), 0);
}

TEST(RewardsServiceTest, TestTechnicalFailure) {
    MockEligibilityService mockEligibilityService;
    RewardsService rewardsService(mockEligibilityService);

    EXPECT_CALL(mockEligibilityService, checkEligibility("T123456")).WillOnce(Return(EligibilityService::TECHNICAL_FAILURE));

    std::vector<std::string> subscriptions = {"SPORTS"};
    std::vector<RewardsService::Reward> rewards = rewardsService.getRewards("T123456", subscriptions);

    ASSERT_EQ(rewards.size(), 0);
}
