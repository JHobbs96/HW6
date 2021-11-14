//
// Created by Jeremiah Hobbs on 11/13/21.
//
#include "CaesarCipher.h"

CaesarCipher::CaesarCipher() {
    shift = getShift();
}

CaesarCipher::CaesarCipher(const CaesarCipher &) {

}

string CaesarCipher::encrypt(string s) {
    return encryptDecrypt(s, true);
}

string CaesarCipher::decrypt(string s) {
    return encryptDecrypt(s, false);
}

string CaesarCipher::encryptDecrypt(string s, bool encrypt) {
    //StringStream to act as a StringBuilder
    stringstream ss;
    int n = s.length();
    // declaring character array
    char char_array[n];
    // copying the contents of the
    // string to char array
    strcpy(char_array, s.c_str());
    for(char c: char_array){
        int indx = c,cpos;
        if(!isPositionInRange(indx)){
            throw std::invalid_argument("String to be encrypted has unrecognized character "+ to_string(c));
        }
        if(encrypt){
            cpos = indx + shift;
            if(cpos > OFFSET_MAX){
                cpos = OFFSET_MIN + (cpos - OFFSET_MAX);
            }
        }  else{
            cpos = indx - shift;
            if(cpos < OFFSET_MIN){
                cpos = OFFSET_MAX - (OFFSET_MIN - cpos);
            }
        }
        char j = cpos;
        ss<<(j);
    }
    return ss.str();
}

int CaesarCipher::getShift() {
    int low = 1;
    int high = OFFSET_MAX - OFFSET_MIN;
    return rand() % (high - low) + low;
}

bool CaesarCipher::isPositionInRange(int indx) {
    return indx >= OFFSET_MIN && indx <= OFFSET_MAX;
}

CaesarCipher &CaesarCipher::operator=(const CaesarCipher &other) {
    if(this != &other) {
        this->shift = other.shift;
    }
    return *this;
}

CaesarCipher CaesarCipher::operator+(const CaesarCipher &) {
    return CaesarCipher();
}

bool CaesarCipher::operator==(const CaesarCipher &other) {
    if(this == &other){
        return true;
    }
    if(this->shift == other.shift){
        return true;
    }
    return false;
}

bool CaesarCipher::operator<(const CaesarCipher &other) {
    if(this == &other){
        return false;
    }
    if(this->shift < other.shift){
        return true;
    }
    return false;
}

bool CaesarCipher::operator>(const CaesarCipher &other) {
    if(this == &other){
        return false;
    }
    if(this->shift > other.shift){
        return true;
    }
    return false;
}

//CaesarCipher &CaesarCipher::operator++() {
//    return <#initializer#>;
//}

CaesarCipher CaesarCipher::operator++(int) {
    return CaesarCipher();
}


