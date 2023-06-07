//Determine the even parity codeword of a data word. Highlight the parity added. Determine if a codeword is corrupted using parity checking.

// if data word odd no of 1. make even adding parity bit 1. else add 0. 

#include<bits/stdc++.h>
using namespace std;

void calculateCodeword()
{
    string dataWord;
    cout<<"Enter the data word:"<<endl;
    cin>>dataWord;
    int noOfOne=0;
    for(int i=0;i<dataWord.length();i++)
        if(dataWord[i]=='1')
            noOfOne++;
    string codeWord= noOfOne%2? dataWord+"1":dataWord+"0";
    cout<<"Codeword is: " << codeWord<<endl;
}

void checkCodeword()
{
    string codeWord;
    cout<<"Enter the code word:"<<endl;
    cin>>codeWord;
    int noOfone=0;
    for(int i=0;i<codeWord.length();i++)
        if(codeWord[i]=='1')
            noOfone++;

    // if noOfone even return ok else not ok 
    cout<<"Code word is "<<(noOfone%2? "corrupted": "not corrupted")<<endl;
}

int main()
{
    int type;
    cout<<"1 : Calculate Code Word\n2 : Check Code Word"<<endl;
    cin>>type;
    if(type==1)
        calculateCodeword();
    else if(type==2)
        checkCodeword();

    return 0;
}