//Simple program for determining the minimum hamming distance in a set of codeword

#include<bits/stdc++.h>
using namespace std;

// Function to calculate Hamming distance between two strings
int hammingDistance(string word1,string word2)
{
    if(word1.length() != word2.length()){
        cout<<"The two word must have equal size"<<endl;
        return -1;
    }
    
    int distance=0;
    for(int i=0;i<word1.length();i++){
        if(word1[i]!=word2[i])
            distance++;
    }
    return distance;
}


// Function to calculate minimum Hamming distance in a set of codewords
int calcMinHamDis(vector<string>&codewords)
{
    cout<<"Hamming distance for all pair of combinations:"<<endl;
    int sz=codewords.size();
    if(sz<2){
        cout<<"At least two codewords are required"<<endl;
    }

    int minDistance=INT_MAX;

    for(int i=0;i<sz;i++){
        for(int j=i+1;j<sz;j++){
            int distance=hammingDistance(codewords[i],codewords[j]);
            cout<<codewords[i]<<" "<<codewords[j]<<" : "<<distance<<endl;
            minDistance=min(distance,minDistance);
        }
    }

    return minDistance;
}

int main()
{
    int numCodewords;
    cout<<"Enter the number of codewords:"<<endl;
    cin>>numCodewords;
    vector<string>codewords;
    cout<<"Enter the codewords:"<<endl;
    string inp;
    for (int i = 0; i < numCodewords; i++){
        cin>>inp;
        codewords.push_back(inp);
    }

    // for taking input till newline 
    // while(1){
    //     getline(cin,inp);
    //     if(inp.empty()) break;
    //     dataWord.push_back(inp);
    // }

    int minDistance=calcMinHamDis(codewords);

    cout << "Minimum Hamming Distance is: " << minDistance <<endl;
    return 0;
}

/*
4
1000001
1110010
1010101
1001001
*/