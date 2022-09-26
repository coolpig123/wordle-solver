#include "functions.h"
#include <string>
#include <map>
using namespace std;
bool checkGreenLetters(string word, map<int, char> greenLetters) {
	for (pair<int,char> greenLetter : greenLetters) {
		if (word.at(greenLetter.first) != greenLetter.second) {
			return false;
		}
	}
	return true;
}
bool checkYellowLetters(string word, map<int, char> yellowLetters) {
	bool yellowContains = false;
	for (pair<int, char> yellowLetter : yellowLetters) {
		yellowContains = false;
		if (word.at(yellowLetter.first) == yellowLetter.second) {
			return false;
		}
		for (int i = 0; i < word.size(); i++) {
			if (word.at(i) == yellowLetter.second && i != yellowLetter.first) {
				yellowContains = true;
				break;
			}
		}
		if (!yellowContains) {
			return false;
		}
	}
}
bool checkBlankLetters(string word, vector<char> blankLetters, map<int, char> yellowLetters, map<int, char> greenLetters) {
	int intendedChars = 0;
	int sumOfChars = 0;
	for (int i = 0; i < blankLetters.size(); i++) {
		intendedChars = 0;
		sumOfChars = 0;
		for (pair<int, char> yellowLetter : yellowLetters) {
			if (yellowLetter.second == blankLetters[i]) {
				intendedChars++;
			}
		}
		for (pair<int, char> greenLetter : greenLetters) {
			if (greenLetter.second == blankLetters[i]) {
				intendedChars++;
			}
		}
		for (int j = 0; j < word.size(); j++) {
			if (word[j] == blankLetters[i]) {
				sumOfChars++;
			}
		}
		if (sumOfChars != intendedChars) {
			return false;
		}
	}
	return true;
}