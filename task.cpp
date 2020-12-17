/* Vividq coding test */
#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

//Q1
int SumEven(int one, int two){
    int sum = 0;
    bool one_even = one % 2 == 0 ? true : false;
    if (one_even){
        for (int i = one; i <= two; i = i+2){
            sum += i;
        } 
    }
    else {
        for (int i = one+1; i <= two; i = i+2){
            sum += i;
        }
    }
    return sum;
}

//Q2
bool is_Anagram(std::string Str1, std::string Str2){
    if (Str1.length() != Str2.length()){
        return false;
    }
    std::unordered_map<char, int> Letters1;
    for (char c : Str1) {
        Letters1[tolower(c)]++;  
    }
    for (char c : Str2) {
        Letters1[tolower(c)]--;   
    }
    for (auto &Pair : Letters1) {
        if (Letters1[Pair.first] != 0) {
            return false;
        }
    }
    return true;
}

int main(){
    //For Q3
    string line;
    ifstream textfile ("file.txt");
    std::unordered_map<int, int> storefreq;
    if (textfile.is_open()){
        while (getline (textfile,line))
        {
            int num = stoi(line);
            storefreq[num]++;
        }
        textfile.close();
    }
    //The idea here is to iterate through map, find the most frequently
    //occurring int, output and remove it from map and repeat 3 times
    int mynum;
    int maxfreq;
    for (int i=1; i<5; i++){
        maxfreq = 0;
        for (const auto &pair : storefreq){
            if (pair.second > maxfreq){
                maxfreq = pair.second;
                mynum = pair.first;
            }
        }
        storefreq.erase(mynum);
        std::cout<<mynum<<endl;
    }

    /*Some tests
    int a, b, c;
    a = 7, b = 30, c = -5;
    int sum = SumEven(a,b);
    std::cout<<sum<<endl;
    int sum2 = SumEven(a,c);
    std::cout<<sum2<<endl;
    std::string one = "Boom";
    std::string two = "Moob";
    bool p = is_Anagram(one,two);
    std::cout<<p<<endl;
    string three = "woWzeRs";
    string four = "bomgogm";
    string five = "Wowzres";
    bool n = is_Anagram(three, four);
    std::cout<<n<<endl;
    bool r = is_Anagram(three, five);
    std::cout<<r<<endl;
    */
}