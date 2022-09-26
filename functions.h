#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;
bool checkGreenLetters(string word, map<int, char> greenLetters);
bool checkYellowLetters(string word, map<int, char> yellowLetters);
bool checkBlankLetters(string word, vector<char> blackLetters,map<int, char> yellowLetters, map<int, char> greenLetters);