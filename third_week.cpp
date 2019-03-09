#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <locale>
#include <map>


using namespace std;

void Print(const vector<int>& v, const string& title){
    cout << title << ": ";
    for (const auto& i: v){
        cout << i << " ";

    }
}

void Print_str(const vector<string>& v, const string& title){
    cout << title << ": ";
    for (const auto& i: v){
        cout << i << " ";

    }
}


void abs_sort() {
    int num, count = 0;
    cout << "count = ";
    cin >> count;
    vector<int> arr(count);
    for (int i = 0; i < count; ++i) {
        cin >> num;
        arr[i] = num;
    }
    sort(arr.begin(), arr.end());
    Print(arr, "abs sort");
}


void str_sort(){
    int count = 0;
    string word;
    cout << "count = ";
    cin >> count;
    vector<string> arr(count);
    for (int i = 0; i < count; ++i) {
        cin >> word;
        arr[i] = word;
    }



    sort(arr.begin(), arr.end());
    Print_str(arr, "abs sort");
}



class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        data.push_back(s);

    }
    vector<string> GetSortedStrings() {
        // получить набор из всех добавленных строк в отсортированном порядке
        sort(begin(data), end(data));
        return data;
    }
private:
    // приватные поля
    vector<string> data;
};


void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}

void testing_sortedstring() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

}




class Person {
public:

    Person(const string& first_name, const string& last_name, int year) {
        YearNameSoname[year] = { first_name, last_name };
        birth_year = year;
        for (auto& i : YearNameSoname) {
            if (i.first < year) YearNameSoname.erase(i.first);
        }
    }

    void ChangeFirstName(int year, const string& first_name) {
        for (auto& i : YearNameSoname) {
            if (year > i.first) {
                if (YearNameSoname.count(year) == 0) YearNameSoname[year].Soname = "";
                YearNameSoname[year].Name = first_name;
            }
            break;
        }
    }
    void ChangeLastName(int year, const string& last_name) {
        for (auto& i : YearNameSoname) {
            if (year > i.first) {
                if (YearNameSoname.count(year) == 0) YearNameSoname[year].Name = "";
                YearNameSoname[year].Soname = last_name;
            }
            break;
        }
    }
    string GetFullName(int year) const {
        if (birth_year != 0 && year < birth_year) return "No person";
        else if (YearNameSoname.size() == 0) {
            return "Incognito";
        }
        else {
            for (const auto& i : YearNameSoname) {
                if (year < i.first) return "Incognito";
                break;
            }
        }

        string nm = "";
        string sn = "";
        for (const auto& i : YearNameSoname) {
            if (i.first <= year && i.second.Soname != "") sn = i.second.Soname;
            if (i.first <= year && i.second.Name != "") nm = i.second.Name;
        }
        if (nm == "") return sn + " with unknown first name";
        else if (sn == "") return nm + " with unknown last name";
        else return nm + " " + sn;
    }

    string GetFullNameWithHistory(int year) const {
        if (birth_year != 0 && year < birth_year) return "No person";
        else if (YearNameSoname.size() == 0) {
            return "Incognito";
        }
        else {
            for (const auto& i : YearNameSoname) {
                if (year < i.first) return "Incognito";
                break; //сразу выходим из цикла
            }
        }

        string nm = "";
        string sn = "";
        vector<string> secondnames;
        vector<string> firstnames;
        for (const auto& i : YearNameSoname) {
            if (i.first <= year && i.second.Soname != "") {
                if (i.second.Soname != sn && sn != "") {
                    secondnames.push_back(sn);
                }
                sn = i.second.Soname;
            }
            if (i.first <= year && i.second.Name != "") {
                if (i.second.Name != nm && nm != "") {
                    firstnames.push_back(nm);
                }
                nm = i.second.Name;
            }
        }

        string secnames_string = "", firstnames_string = "";
        if (secondnames.size() > 0) {
            secnames_string += " (" + secondnames[secondnames.size() - 1];
            if (secondnames.size() > 1) {
                for (int i = secondnames.size() - 1; i > 0; --i) {
                    secnames_string += ", " + secondnames[i - 1];
                }
            }
            secnames_string += ")";
        }

        if (firstnames.size() > 0) {
            firstnames_string += " (" + firstnames[firstnames.size() - 1];
            if (firstnames.size() >1) {
                for (int i = firstnames.size() - 1; i > 0; --i) {
                    firstnames_string += ", " + firstnames[i - 1];
                }
            }
            firstnames_string += ")";
        }

        if (nm == "") return sn + secnames_string + " with unknown first name";
        else if (sn == "") return nm + firstnames_string + " with unknown last name";
        else return nm + firstnames_string + " " + sn + secnames_string;
    }
private:
    struct FullName {
        string Name;
        string Soname;
    };
    map<int, FullName> YearNameSoname;
    int birth_year = 0;
};


/*
void class_person() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

}
*/

class ReversibleString {
public:
    ReversibleString() {}
    ReversibleString(const string& s) {
        data = s;
    }
    void Reverse() {
        reverse(begin(data), end(data));
    }
    string ToString() const {
        return data;
    }
private:
    string data;
};


void callReversibleString(){
    {
        ReversibleString s("live");
        s.Reverse();
        cout << s.ToString() << endl;

        s.Reverse();
        const ReversibleString& s_ref = s;
        string tmp = s_ref.ToString();
        cout << tmp << endl;

        ReversibleString empty;
        cout << " " << empty.ToString() << " " << endl;
    }

}

void class_person3(){
    {
        Person person("Polina", "Sergeeva", 1960);
        for (int year : {1959, 1960}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }

        person.ChangeFirstName(1965, "Appolinaria");
        person.ChangeLastName(1967, "Ivanova");
        for (int year : {1965, 1967}) {
            cout << person.GetFullNameWithHistory(year) << endl;
        }
    }
}


struct Incognizable {
    int x = 0;
    int y = 0;
};

void outIncognizable(){
    Incognizable a;
    Incognizable b = {};
    Incognizable c = {0};
    Incognizable d = {0, 1};

}


int main() {
    // abs_sort();
    //str_sort();
    //testing_sortedstring();
    //class_person();
    //callReversibleString();
    //class_person3();
    outIncognizable();

    return 0;
}
