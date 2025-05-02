#include <stdexcept>
using namespace std;
struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) : question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);
		
		return checkAnswer(guessNumber);
	}
	bool isCorrectAnswer(const std::string& guessNumber) {
		return guessNumber == question;
	}

	GuessResult checkAnswer(const std::string& guessNumber) {
		int strikes = 0;
		int balls = 0;
		if (isCorrectAnswer(guessNumber)) return { true,3,0 };
		for (char ch : guessNumber) {
			for (char answer : question) {
				if (ch == answer) {
					if (guessNumber.find(ch) == question.find(answer)) strikes++;
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
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
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
	string question;
};