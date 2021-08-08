#include <gtest/gtest.h>

#include "../recognizer.h"

TEST(RecognizerTest, Samples) {
	using Intents = std::vector<std::string>;

	ASSERT_EQ(
		recognizeIntents("What is the weather like today?"),
		Intents({ "Get", "Weather" })
	);
	ASSERT_EQ(
		recognizeIntents("What is the weather like in Paris today?"),
		Intents({ "Get", "Weather", "City" })
	);
	ASSERT_EQ(
		recognizeIntents("Tell me an interesting fact."),
		Intents({ "Get", "Fact" })
	);
}

TEST(RecognizerTest, SamplesModified) {
	using Intents = std::vector<std::string>;

	ASSERT_EQ(
		recognizeIntents("What is   the weather like today !"),
		Intents({ "Get", "Weather" })
	);
	ASSERT_EQ(
		recognizeIntents("What is the Temperature like in Paris today?"),
		Intents({ "Get", "Temperature", "City" })
	);
	ASSERT_EQ(
		recognizeIntents("Tell interesting fact."),
		Intents({ "Get", "Fact" })
	);
}

TEST(RecognizerTest, Miscellanious) {
	using Intents = std::vector<std::string>;

	ASSERT_EQ(
		recognizeIntents(""),
		Intents()
	);
	ASSERT_EQ(
		recognizeIntents("."),
		Intents()
	);
	ASSERT_EQ(
		recognizeIntents(" "),
		Intents()
	);
}

