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

//CaesarCipher &CaesarCipher::operator=(const CaesarCipher &other) {
//    this->shift = other.shift;
//    this->
//}

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


