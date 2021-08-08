#include "recognizer.h"
#include "split.h"

#include <set>
#include <map>
#include <ranges>
#include <algorithm>

enum TokenType {
	IntentParameter,
	IntentGet,
	IntentCity
};

std::set<std::string_view> sTokensToSkip = {
	"a", "an", "the", "is", "me", "in", "like", "today", "interesting"
};

std::map<std::string_view, TokenType> sRecognizedKeywords = {
	{"tell", IntentGet},
	{"what", IntentGet},
	{"paris", IntentCity}
};

TokenType getTokenType(std::string_view token) {
	auto it = sRecognizedKeywords.find(token);
	if (it != sRecognizedKeywords.end()) {
		return it->second;
	}
	else {
		return IntentParameter;
	}
}


std::vector<std::string> recognizeIntents(const std::string& input) {

	std::string lowerInput;
	std::transform(input.begin(), input.end(), std::back_inserter(lowerInput), tolower);

	std::erase_if(lowerInput, ispunct);

	std::vector<std::string_view> tokens = split(lowerInput, ' ');

	std::erase_if(tokens, [](std::string_view token) {
		return sTokensToSkip.count(token) > 0;
		});

	std::vector<std::string> intents;
	intents.reserve(tokens.size());

	std::transform(tokens.begin(), tokens.end(), std::back_inserter(intents),
		[](std::string_view token) -> std::string {
			TokenType type = getTokenType(token);
			switch (type) {
			case IntentParameter:
			{
				std::string result{ token };
				result[0] = toupper(result[0]);
				return result;
			}
			case IntentGet:
				return "Get";
			case IntentCity:
				return "City";
			default:
				return "Unknown";
			}
		});

	return intents;
}