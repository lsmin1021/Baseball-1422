#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

class BaseballFixture : public testing::Test {
public:
	Baseball game{ "123" };
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
	assertIllegalArugment("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
	GuessResult result = game.guess("123");

	EXPECT_TRUE(result.solved);
	EXPECT_EQ(3, result.strikes);
	EXPECT_EQ(0, result.balls);

}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}