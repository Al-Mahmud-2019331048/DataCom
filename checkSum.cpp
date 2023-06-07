#include <bits/stdc++.h>

 
using namespace std;
 
unsigned int calculateChecksum( vector<unsigned int>& numbers,int numBits) {
    unsigned int sum = 0;
    for (unsigned int num : numbers)
        sum += num;
    unsigned int checksum=0,extraBits=0;

    do{
        // Keep only the least significant M bits
        unsigned int mask=(1<<numBits)-1;
        
        checksum=sum&mask;
        
        // Get the extra left bits
        extraBits=sum>>numBits;

         // Add the extra left bits to the checksum
        checksum+=extraBits;

        // Update the sum with the new checksum
        sum=checksum;
        // cout<<"ectra bits : "<<extraBits<<endl;
    }
    while(extraBits);

    return ~checksum;
}
 
int main() {
    int n,m;
    cout<<"How many number do you want to input:"<<endl;
    cin>>n;
    cout<<"How long is the largest number (in bits)"<<endl;
    cin>>m;
    vector<unsigned int> numbers(n);
    cout<<"Enter the numbers to calculate checksum:"<<endl;
    for(int i=0;i<n;i++) cin>>numbers[i];
    unsigned int checksum = calculateChecksum(numbers,m);

    unsigned int mask= (1<<m) -1;
 
    cout << "Generated checksum: " << bitset<4>(checksum).to_string() << endl;

    cout<<"Checksum: "<<(checksum & mask) <<endl;
    return 0;
}
 
 

/*
5
4
7 11 12 0 6

explanation:
1.
sum=36,100100
mask=15,1111
checksum=sum&mask=0100
extrabits=100100>>4=10
checksum=0100+10=0110=6
sum=6;
2.
sum=6,0110
mask=15,1111
checksum=sum&mask=0110
extrabits=0110>>4=0
checksum=0110+0=0110=6
sum=6;

~6(0110)=9(1001)
*/



/*
4
5
15 15 14 16

explanation:
1.
sum=60,111100
mask=31,11111
checksum=sum&mask=11100
extrabits=111100>>5=1
checksum=11100+1=11101=29
sum=29;
2.
sum=29,11101
mask=31,11111
checksum=sum&mask=11101
extrabits=11101>>5=0
checksum=11101+0=11101=29
sum=29;

~29(11101)=2(00010)
*/