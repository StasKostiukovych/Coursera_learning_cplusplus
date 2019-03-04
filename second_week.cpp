#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>


using namespace std;


int Factorial(int num){
    int rez = 1;
    for (int i = 1; i <= num; i++){
        rez *= i;
    }
    return rez;
}


bool pallindrome(string str){
    string str2;
    int i, len, flag;
    len = str.size();
    for(int i=0 ;i < len ;i++){
        if(str[i] != str[len-i-1]){
            flag = 1;
            break;
        }
    }
    
    if (flag == 1)
        return false;
    
    else
        return true;   
}


vector<string> PalindromFilter(vector<string> array, int minLength){
    vector <string> rez_array;
    for (int i=0; i < array.size(); i++){
        if (pallindrome(array[i]) == true && array[i].size() >= minLength){
            rez_array.push_back(array[i]);
           
        }
    }
    return rez_array;
}

void returnFactorial(){
    int n, rez1 ;
    cout << "Enter num: ";
    cin >> n;
    rez1 = Factorial(n);
    cout << rez1;
}


void returnPallindrome(){
    string str;
    cout << "Enter string: ";
    cin >> str; 
    bool rez;
    rez = pallindrome(str);
    cout << rez;
    
}


void returnPalindromFilter(){
    int minlen = 3;
    vector <string> array = {"s","lol", "kek", "asdwqdqw"};
    vector <string> rez_array;
    rez_array = PalindromFilter(array, minlen);
    for (auto i: rez_array){
        cout <<i<<", ";
    }
    
}


void maximizator(int& a , int& b){
    int rez;
    if (a > b){
        b = a;
    }
}
    
void returnmaximizator(){
    int a = 12;
    int b = 4;
    maximizator(a, b);
    cout << b;
}




void MoveString(vector <string>& source, vector <string>& destination){
    for (auto word: source){
        destination.push_back(word);
    }
    source.clear();
}


void returnMoveString(){
    vector <string> source = {"bitches"};
    vector <string> destination = {"Hello", "freack"} ;
    MoveString(source, destination);
    cout << "source: ";
    for (auto word: destination){
        cout << word<< " ";
    }
    cout << "\n destination: ";
    for (auto word: source){
        cout << word << " ";
    }
}


void reverseVector(vector<int> &numbers){
    vector <int> temp(numbers.size());
    for (int i = 0; i <= numbers.size();i++){
        temp[i] = numbers[numbers.size()- i-1];
    }
    numbers = temp;
    
}


void returnRevereseVector(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    reverseVector(numbers);
    for (auto num: numbers){
        cout << num;
    }
}

void PrintVector(const vector<string>& v){
    for (string s: v){
        cout<< s <<endl;
    }
}

vector <int> AddVector(int n){
    vector <int> v;
    for (int i = 0; i < n; ++i) {
        int s;
        cin >> s;
        v.push_back(s);
    }
    return v;
}

// map

void outAnagrama(){
    string str1 = "master";
    string str2 = "stream";

    map <char, int> map1;
    map <char, int> map2;
    for (auto item :str1){
        ++map1[item];
    }
    for (auto item :str2){
        ++map2[item];
    }

    if (map1 == map2){
        cout << "yes";
    }else{
        cout << "no";
    }

}


void capitals_guide(){
    int count;
    cout << "count: ";
    cin >> count;
    map<string, string> country_to_capital;

    for (int i = 0; i < count; ++i) {
        string operation_code;
        cin >> operation_code;

        if (operation_code == "CHANGE_CAPITAL") {

            string country, new_capital;
            cin >> country >> new_capital;
            if (country_to_capital.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                const string& old_capital = country_to_capital[country];
                if (old_capital == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << " has changed its capital from " << old_capital << " to " << new_capital << endl;
                }
            }
            country_to_capital[country] = new_capital;

        } else if (operation_code == "RENAME") {

            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if (old_country_name == new_country_name || country_to_capital.count(old_country_name) == 0 || country_to_capital.count(new_country_name) == 1) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << country_to_capital[old_country_name] <<
                     " has been renamed to " << new_country_name << endl;
                country_to_capital[new_country_name] = country_to_capital[old_country_name];
                country_to_capital.erase(old_country_name);
            }

        } else if (operation_code == "ABOUT") {

            string country;
            cin >> country;
            if (country_to_capital.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << country_to_capital[country] << endl;
            }

        } else if (operation_code == "DUMP") {

            if (country_to_capital.empty()) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& country_item : country_to_capital) {
                    cout << country_item.first << "/" << country_item.second << " ";
                }
                cout << endl;
            }

        }

    }
}

// set

void unique_lines() {
    int count;

    set<string> words;
    cout << "count: ";
    cin >> count;

    for (int i = 0; i < count; ++i) {
        string word;
        cin >> word;
        words.insert(word);
    }
        cout << "count: " << words.size();


}


set<string> BuildMapValuesSet(map<int, string> m){
    set<string> rez;
    for(const auto& [key, value]: m){
        rez.insert(value);
    }
    return rez;
}


void returnSet(){
    set<string> values = BuildMapValuesSet({{1, "odd"},
                                            {2, "even"},
                                            {3, "odd"},
                                            {4, "even"},
                                            {5, "odd"}
                                           });

    for (const string& value : values) {
        cout << value << endl;
    }

}


int main(int argc, char** argv) {
    //returnFactorial();
    //returnPallindrome();
    //returnPalindromFilter();
    //returnmaximizator();
    //returnMoveString();
    //returnRevereseVector();
    //outAnagrama();
    //capitals_guide();
    //unique_lines();
    //returnSet();
    return 0;
}

