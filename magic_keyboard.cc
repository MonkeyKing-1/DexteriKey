#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>

std::map<int, std::vector<char> > fingers;
std::vector<int> char_to_finger(26); 
std::string sequence;
int total_words = 0;
std::vector<std::string> words;
std::multimap<std::string, std::string> combo_to_string;
std::map<std::string, std::vector<std::string> > combo_to_strv;
std::vector<std::string> all_combos;
std::vector<std::string> valid_combos;

int matsizes[8598];
int matlens[8598];
char* words2[8598][27];

void read_input() {
    for (int i = 1; i <= 8; i++) {
        std::vector<char> empty;
        fingers.insert(std::pair<int, std::vector<char> >(i, empty));
    }
    fingers[1].push_back('q');
    fingers[1].push_back('a');
    fingers[1].push_back('z');
    fingers[2].push_back('w');
    fingers[2].push_back('s');
    fingers[2].push_back('x');
    fingers[3].push_back('e');
    fingers[3].push_back('d');
    fingers[3].push_back('c');
    fingers[4].push_back('r');
    fingers[4].push_back('f');
    fingers[4].push_back('v');
    fingers[4].push_back('t');
    fingers[4].push_back('g');
    fingers[4].push_back('b');
    fingers[5].push_back('y');
    fingers[5].push_back('h');
    fingers[5].push_back('n');
    fingers[5].push_back('u');
    fingers[5].push_back('j');
    fingers[5].push_back('m');
    fingers[6].push_back('i');
    fingers[6].push_back('k');
    fingers[7].push_back('o');
    fingers[7].push_back('l');
    fingers[8].push_back('p');
    for (int i = 1; i <= 8; i++){
        for (int j = 0; j < fingers[i].size(); j++){
            char_to_finger[(int) fingers[i][j] - 'a'] = i;
        }
    }
    std::cin >> sequence;
    std::cin >> total_words;
    for (int i = 0; i < total_words; i++) {
        std::string cum = "";
        std::string word;
        std::cin >> word;
        words.push_back(word);
        for (int j = 0; j < word.size(); j++){
            cum += (char) (48 + char_to_finger[word[j] - 'a']);
        }
        //std::cout << cum << " " << word << "\n";
        combo_to_string.insert(std::pair<std::string, std::string>(cum, word));
        if(combo_to_strv.find(cum) == combo_to_strv.end()){
            std::vector<std::string> empty;
            combo_to_strv.insert(std::pair<std::string, std::vector<std::string> >(cum, empty));
        }
        combo_to_strv[cum].push_back(word);
    }
}

void hardcode(){
    for (int i = 1; i <= 8; i++) {
        std::vector<char> empty;
        fingers.insert(std::pair<int, std::vector<char> >(i, empty));
    }
    fingers[1].push_back('q');
    fingers[1].push_back('a');
    fingers[1].push_back('z');
    fingers[2].push_back('w');
    fingers[2].push_back('s');
    fingers[2].push_back('x');
    fingers[3].push_back('e');
    fingers[3].push_back('d');
    fingers[3].push_back('c');
    fingers[4].push_back('r');
    fingers[4].push_back('f');
    fingers[4].push_back('v');
    fingers[4].push_back('t');
    fingers[4].push_back('g');
    fingers[4].push_back('b');
    fingers[5].push_back('y');
    fingers[5].push_back('h');
    fingers[5].push_back('n');
    fingers[5].push_back('u');
    fingers[5].push_back('j');
    fingers[5].push_back('m');
    fingers[6].push_back('i');
    fingers[6].push_back('k');
    fingers[7].push_back('o');
    fingers[7].push_back('l');
    fingers[8].push_back('p');
    for (int i = 1; i <= 8; i++){
        for (int j = 0; j < fingers[i].size(); j++){
            char_to_finger[(int) fingers[i][j] - 'a'] = i;
        }
    }
    std::cin >> total_words;
}
// sequence = 4331523
// index = 0

void recurse(std::string sequence, int index, std::string current) {
    if (index != sequence.length()) {
        int digit = sequence[index] - '0';
        for (unsigned int i = 0; i < fingers[digit].size(); i++) {
            char letter = fingers[digit][i];
            std::string append = current;
            append.push_back(letter);
            recurse(sequence, index + 1, append);
        }
    }
    else {
        all_combos.push_back(current);
    }
}

int main () {
	freopen("words.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    read_input();
    for (auto it = combo_to_strv.begin(); it != combo_to_strv.end(); it++){
        std::cout << "\"" << it->first << 
        "\", {";
        for (int j = 0; j < it->second.size(); j++){
            std::cout << "\"" << it->second[j] << "\"";
            if (j < it->second.size()-1){
                std::cout << ", ";
            }
        }
        std::cout << "};\n";
    }
    return 0;
}
