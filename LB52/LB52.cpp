#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

enum class Type : int
{
    FRIENDS,
    COUNT,
    QUESTION
};

Type type;
map<string,vector<string>> friends;

void count_friends(vector<string> word_in_s) {
    int count=0;
    for (auto first_friend : friends) {
        for (auto second_friend : first_friend.second) {
            if (first_friend.first == word_in_s[1]) {
            count++;
            }
            if (second_friend == word_in_s[1]) {
                count++;
            }
        }
    }
    cout << count << endl;
}

void question_friends(vector<string> word_in_s) {
    for (auto question : friends) {
        for (auto second_friend : question.second) {
            if (((word_in_s[1] == question.first) && (word_in_s[2] == second_friend)) ||
                ((word_in_s[2] == question.first) && (word_in_s[1] == second_friend))) {
                cout << "Yes" << endl;
            }
        }
    }
}

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

void check_str(vector<string> word_in_s) {
    if (!(word_in_s[0] == "FRIENDS" || word_in_s[0] == "COUNT" || word_in_s[0] == "QUESTION")) {
        exit(0);
    }
}

void do_it(vector<string> word_in_s) {
    switch (type) {
    case Type::FRIENDS: {
        friends[word_in_s[1]].push_back(word_in_s[2]);
        break;
    }
    case Type::COUNT: {
        count_friends(word_in_s);
        break;
    }
    case Type::QUESTION: {
        question_friends(word_in_s);
        break;
    }
    default: {
        return;
    }
    }
}


int main()
{
    setlocale(LC_ALL, "Russian");
    while (1){
        vector<string> word_in_s;
        stringToArray(&word_in_s);
        check_str(word_in_s);
        type = word_in_s[0] == "FRIENDS" ? Type::FRIENDS :
            word_in_s[0] == "COUNT" ? Type::COUNT :
            Type::QUESTION;
        do_it(word_in_s);
    }
}
