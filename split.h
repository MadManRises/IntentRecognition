#pragma once

#include <vector>
#include <string>

inline std::vector<std::string_view> split(std::string_view string, char token) {
	std::vector<std::string_view> tokens;

	size_t offset = 0;
	size_t nextOffset;

	do {
		nextOffset = string.find(token, offset);
		if (nextOffset == std::string_view::npos) {
			tokens.emplace_back(string.data() + offset);
		}
		else if (nextOffset - offset > 1) {
			tokens.emplace_back(string.data() + offset, nextOffset - offset);
		}
		offset = nextOffset + 1;
	} while (nextOffset != std::string_view::npos);

	return tokens;
}
