#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArugment(string guessNumber) {
		try {
			game.guess(guessNumber);
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballFixture, ThorwExceptionWhenInvalidCase) {
	assertIllegalArugment("12");
	assertIllegalArugment("12s");
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}