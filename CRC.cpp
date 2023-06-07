// Determine CRC (cyclic redundancy check) codeword for a given dataword and a divisor. Determine if the code is corrupted usinf CRC checker.

#include <bits/stdc++.h>
using namespace std;

string doCRC(int dataLen, string divisor,string augment)
{
    // Check if the dataword size is too small
    if (augment.size() < divisor.size())
    {
        cout << "Error! Dataword size is too small." << endl;
        return ""; // Return empty string as error indication
    }
    
    for (int i = 0; i < dataLen; i++)
    {
        if (augment[i] == '1')
        {
            for (int j = 0; j < divisor.length(); j++)
            {
                augment[i + j] = (augment[i + j] == divisor[j] ? '0' : '1');
            }
        }
    }
    return augment.substr(dataLen);
}

void calculateCodeword()
{
    string dataWord, divisor;
    cout << "Enter The data word:" << endl;
    cin >> dataWord;
    cout << "Enter the divisor:" << endl;
    cin >> divisor;
    // perfrom CRC 
    cout<<"Performing CRC at sender side"<<endl;
    string paddedData = dataWord + string(divisor.length() - 1, '0');
    string remainder=doCRC(dataWord.length(), divisor,paddedData);
    cout<<"Remainder is: "<<remainder<<endl;
    string codeWord = dataWord + remainder;
    cout<<"Codeword is: "<<codeWord<<endl;
}

void checkCodeword()
{
    // checkCorrupted 
    string codeWord,divisor;
    cout<<"Enter the codeword:"<<endl;
    cin>>codeWord;
    cout<<"Enter the divisor:"<<endl;
    cin>>divisor;

    cout<<"Checking for the code is corrupted or not at receiver side"<<endl;
    string remainder=doCRC( codeWord.length()-divisor.length()+1,  divisor, codeWord);
    cout<<"Remainder is: "<<remainder<<endl;

    for(int i=0;i<remainder.length();i++)
        if(remainder[i]!='0'){
            cout<<"Code is corrupted"<<endl;
            return;
        }
    cout<<"Code is not corrupted"<<endl;
}

int main()
{
    int type;
    cout<<"1- Calculate Code Word\n2-Check Code Word"<<endl;
    cin>>type;
    if(type==1)
        calculateCodeword();
    else if(type==2)
        checkCodeword();

    return 0;
}

/*
1
1001
1011

2
1001001
1011
----------
1
101001111
10111
2
1010011110101
10111
-----------
1
100100
1101
2
100100001
1101
*/