#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

enum class Type : int
{
    CREATE_TRAIN,
    TRAINS_FOR_TOWN,
    TOWNS_FOR_TRAIN,
    TRAINS
};

map<int, vector<string>> trains;
Type type;

void f_Create_Train(vector<string> word_in_s) {

    vector<string> address;

    for (size_t i = 2; i < word_in_s.size(); i++)
    {
        address.push_back(word_in_s[i]);
    }

    trains[std::stoi(word_in_s[1])] = address;
}

void f_Towns_For_Train(vector<string> word_in_s) {
    for (auto train : trains) {
        if (train.first == std::stoi(word_in_s[1])) {
            cout << train.first << ": ";
            for (string one_address : train.second) {
                cout << one_address << " ";
            }
        }
    }
    cout << endl;
}

void f_Trains(vector<string> word_in_s) {
    for (auto train : trains) {
        cout << train.first << " ";
    }
    cout << endl;
}

void f_Trains_For_Town(vector<string> word_in_s) {
    for (auto train : trains) {
        for (string one_address : train.second) {
            if (one_address == word_in_s[1]) {
                cout << train.first << " ";
            }
        }
    }
    cout << endl;
}
/// <summary>
/// Input string to string array
/// </summary>
/// <param name="word_in_s">input string array (separator is " ")</param>
void stringToArray(vector<string>* word_in_s) {
    string s;

    cin.clear();
    s = "";
    getline(cin, s);
    int past_ind = 0;
    for (auto i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            word_in_s->push_back(s.substr(0, s.find_first_of(s[i])));
            s = s.substr(s.find_first_of(s[i]) + 1);
            i = 0;
        }
    }
    word_in_s->push_back(s);
}

void do_it(vector<string> word_in_s) {
    switch (type) {
    case Type::CREATE_TRAIN: {
        f_Create_Train(word_in_s);
        break;
    }
    case Type::TOWNS_FOR_TRAIN: {
        f_Towns_For_Train(word_in_s);
        break;
    }
    case Type::TRAINS: {
        f_Trains(word_in_s);
        break;
    }
    case Type::TRAINS_FOR_TOWN: {
        f_Trains_For_Town(word_in_s);
        break;
    }
    default: {
        return;
    }
    }
}

/// <summary>
/// If in word_in_str be a any incorrect sym this thread will be terminated
/// </summary>
/// <param name="word_in_s"></param>
void check_str(vector<string> word_in_s) {
    if (!(word_in_s[0] == "CREATE_TRAIN" || word_in_s[0] == "TRAINS_FOR_TOWN"
        || word_in_s[0] == "TOWNS_FOR_TRAIN" || word_in_s[0] == "TRAINS")) {
        exit(0);
    }
}

void do_command() {

    vector<string> word_in_s;

    stringToArray(&word_in_s);

    check_str(word_in_s);

    type = word_in_s[0] == "CREATE_TRAIN" ? Type::CREATE_TRAIN :
        word_in_s[0] == "TRAINS_FOR_TOWN" ? Type::TRAINS_FOR_TOWN :
        word_in_s[0] == "TOWNS_FOR_TRAIN" ? Type::TOWNS_FOR_TRAIN : Type::TRAINS;
    do_it(word_in_s);
}