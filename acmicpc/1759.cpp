// 암호 만들기 (https://www.acmicpc.net/problem/1759)
#include <iostream>
#include <algorithm>

using namespace std;

int L,C;
char A[15], P[16];
bool isVowel[26];

void backtrack(int pos, int prev, int consonant, int vowel){
    if(pos==L){
        if(consonant >=2 && vowel >= 1) cout << P << endl;
        return;
    }

    for(int i=prev+1; i<C; i++){
        P[pos]=A[i];
        backtrack(pos+1, i, consonant + !isVowel[A[i]-'a'], vowel + isVowel[A[i]-'a']);
    }
}

int main(void){
    cin >> L >> C;
    for(int i=0; i<C; i++){
        cin >> A[i];
    }
    sort(A,A+C);
    isVowel['a'-'a'] = isVowel['e'-'a'] = isVowel['i'-'a'] = isVowel['o'-'a'] = isVowel['u'-'a'] = true;
    backtrack(0,-1,0,0);
}