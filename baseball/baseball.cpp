#include <stdexcept>
using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& answer) : answer(answer) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		
		return checkAnswer(guessNumber);
	}
	bool isCorrectAnswer(const std::string& guessNumber) {
		return guessNumber == answer;
	}

	GuessResult checkAnswer(const std::string& guessNumber) {
		if (isCorrectAnswer(guessNumber)) return { true,3,0 };
		int strikes = 0;
		int balls = 0;
		for (char guessNum : guessNumber) {
			for (char answerNum : answer) {
				if (guessNum == answerNum) {
					if (guessNumber.find(guessNum) == answer.find(answerNum)) strikes++;
					else balls++;
					break;
				}
			}
		}
		return { false,strikes,balls };
	}

	void assertIllegalArgument(const std::string& guessNumber)
	{
		if (guessNumber.length() != 3) {
			throw length_error("Must be three letters.");
		}
		for (char guessNum : guessNumber) {
			if (guessNum >= '0' && guessNum <= '9') continue;
			throw invalid_argument("Must be number");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw invalid_argument("Must not have the same number");
		}
	}
	bool isDuplicatedNumber(const std::string& guessNumber)
	{
		return guessNumber[0] == guessNumber[1]
			|| guessNumber[0] == guessNumber[2]
			|| guessNumber[1] == guessNumber[2];
	}
private:
	string answer;
};