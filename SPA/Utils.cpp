#include "Utils.h"

using namespace std;

string Utils::sanitise(string str)
{
	for (size_t i = 0; i < strlen(UtilsConstants::SANITISED_CHAR); i++) {
		char sanitisedChar = UtilsConstants::SANITISED_CHAR[i];
		str.erase(remove(str.begin(), str.end(), sanitisedChar), str.end());
	}
	return str;
}

/* Split string into a vector of tokens, depending on delim_string and delimiters */
vector<string> Utils::explode(const string &str, const string delim_string, const vector<char> delimiters)
{
	vector<string> ele;
	int pos;
	int prev = 0;

	while ((pos = str.find_first_of(delim_string, prev)) != string::npos) {
		if (pos > prev) {
			ele.push_back(str.substr(prev, pos - prev));
		}
		if (find(begin(delimiters), end(delimiters), str[pos]) != end(delimiters)) {
			ele.push_back(string(1, str[pos]));
		}
		prev = pos + 1;
	}
	return ele;
}

bool Utils::isValidName(string name)
{
	if (!isalpha(name[0])) {
		return false;
	}
	else {
		for (size_t i = 1; i < name.size(); i++) {
			if (!isalnum(name[i])) {
				return false;
			}
		}
		return true;
	}
}
