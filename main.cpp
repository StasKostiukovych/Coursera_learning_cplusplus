#include <iostream>
#include <string>  
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;


void min_string(){
    string min_str, str1, str2, str3;
    cout << "Enter word n1: ";
    getline(cin, str1);
    
    cout << "Enter word n1: ";
    getline(cin, str2);
    
    cout << "Enter word n1: ";
    getline(cin, str3);
    
    if (str1 < str2){
        min_str = str1;
    }
    else{
        min_str = str2;
    }
    
    if (min_str> str3){
        min_str = str3;
    }
    
    cout << min_str << '\n';
}

void roots_of_equation(){
    double c, d, x1, x2, x;
    int a, b;
    a = 1;
    b = 3;
    c = 1;
    d = b*b-4*a*c;
    
    if(a==0){
        x = -c/b;
        cout<< "x = " << x ; 
    }
    
    else{
        
        if (d >= 0){
        x1 = (-b+pow(d, 0.5))/(2*a);
        x2 = (-b-pow(d, 0.5))/(2*a);
        cout << "x1 = "<< x1<<" x2 = "<<x2;
        }
        else{
            cout << " ???";
        }
    }
}

void even_numbers(){
    int a = 2;
    int b = 10;
    
    
    for (auto i = a; i < b+1; i++){
        if (i % 2 ==0 ){
            cout << i << ", ";
        }
        
    }
   
}

void second_entry(){
    string my_str;
    char to_find;
    to_find = 'f';
    int counter= 0;
    my_str = "comfort";
    
    for (int i=0; i < my_str.size(); i++){
        if (my_str[i] == 'f'){
            counter +=1;
            if (counter == 2){
                cout << i << endl;
                break;
            } 
        }
    }
    
    if (counter == 1){
        cout << -1;
    }
    
    if (counter == 0){
        cout << -2;
    }
            
}


void greatest_common_divisor(){
    int a, b, gcd;
    a = 13;
    b = 13;
    gcd = 1;
    
    for (int i = a; i>0; --i){
        if (a % i == 0){
            if (b % i == 0){
                gcd = i;
                break;
                
            }
        }  
    }
    
    cout << gcd;
}


void to_binary(){

    int num,arr[64];
    cin>>num;
    int i=0 ,r;
    
    while(num!=0){
        r = num%2;
        arr[i++] = r;
        num /= 2;
    }

   for(int j=i-1; j>=0; j--)
    cout<<arr[j];
}
    
    
int main() {
    //min_string();
    //roots_of_equation(); 
    //even_numbers();
    //second_entry();
    //greatest_common_divisor();
    //to_binary();
    
    return 0;
}


