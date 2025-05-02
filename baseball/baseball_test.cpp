#include "baseball.cpp"
#include "gmock/gmock.h"
using namespace std;

TEST(BaseballGame, TryGameTest) {
	EXPECT_EQ(1, 1);
}

TEST(BaseballGame, ThorwExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}


int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}