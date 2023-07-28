# Customer Rewards Service

The Customer Rewards Service is a C++ application that provides rewards to eligible customers based on their channel subscriptions. It interacts with an `EligibilityService` to determine the customer's eligibility and then offers appropriate rewards if the customer is eligible.

## Table of Contents
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [License](#license)

## Requirements

To build and run this project, you need the following tools and libraries:

- CMake (version 3.10 or higher)
- C++ compiler that supports C++17
- GoogleTest and GoogleMock (included as FetchContent in the CMakeLists.txt)

## Installation

1. Clone the repository to your local machine:

```
git clone git clone https://oauth2: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@github.com/skartikey/customer-rewards-service.git
cd customer-rewards-service
```

2. Build the project using CMake:

```
mkdir build
cd build
cmake ..
make
```

This will generate the `CustomerRewardsService` executable.

## Usage

1. Run the `CustomerRewardsService` executable:

```
./CustomerRewardsService
```

2. The application will prompt you to enter the customer's account number and channel subscriptions.

3. Based on the eligibility determined by the `EligibilityService`, the application will display the rewards available to the customer.

## Testing

The project includes unit tests for the `RewardsService` using GoogleTest and GoogleMock. To run the tests, use the following command:

```
./RewardsServiceTest
```

## Contributing

Contributions to this project are welcome. If you find any issues or want to add new features, feel free to open an issue or create a pull request.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use, modify, and distribute it as per the terms of the license.