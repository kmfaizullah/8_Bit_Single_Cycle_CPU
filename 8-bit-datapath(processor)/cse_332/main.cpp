#include <bits/stdc++.h>
#include <iostream>
#include<sstream>
#include<string>


using namespace std;


//this function converts a string to number
 /*  int toInt(string s){
    int tmp1=0;
    int multiplier=1;

    for(int i=s.length()-1;i>=0;i--){
        if (s[i]=='-')
            break;
        tmp1+=(s[i]-'0')*multiplier;
        multiplier*=10;
    }

    if (s[0]=='-')
        tmp1*=-1;

    return tmp1;
} */

// this function converts the decimal number "num" to a binary string with "noOfBits" bits
string toBinary(int num, int noOfBits){
    string s="";
    for(int i=0;i<noOfBits;i++){
        if ((num & (1<<i))!=0){
            s+="1";
        }
        else {
            s+="0";
        }
    }

    reverse(s.begin(),s.end());


    return s;

}


map<string,string> m; //this map relates register names with their corresponding binary codes

/* this function initializes the map which establishes the relation between register name and it's
corresponding binary expression */
void help(){
    string tmp1="$ac";
        m[tmp1]=toBinary(0,2);


    tmp1="$s1";
    for(int i=0;i<=3;i++){
        tmp1[2]=(char)(i+'0');
        m[tmp1]=toBinary(i,2);
    }
}


#include "R_type.cpp"
#include "I_type.cpp"


// converts all the characters to lowercase
void toLower(string& instruction){
    for(int i=0;i<instruction.length();i++){
        if (instruction[i]>='A' && instruction[i]<='Z'){
            instruction[i]+=8;
        }
    }
}


//splits the input string into to tokens
vector<string> split(string& instruction){
    string s="";
    vector<string> v;
    int start=0;
    for(int i=0;i<instruction.length();i++){
        if (instruction[i]==' ')
            continue;
        if (instruction[i]=='$'){
            start=i;
            break;
        }
        s+=instruction[i];
    }

    v.push_back(s);
    s="";
    for(int i=start;i<instruction.length();i++){
        if (instruction[i]==' ')
            continue;
        if (instruction[i]==','){
            if (!s.empty()){
                v.push_back(s);
                s="";
            }
            continue;
        }
        s+=instruction[i];
    }

    if (!s.empty()){
        v.push_back(s);
    }

    return v;

}


//prints the output string
void printCode(string s, bool spaces){
    for(int i=0;i<s.length();i++){
        if (s[i]==' ' &&!spaces)
            continue;
        cout<<s[i];
    }
    cout<<endl;
}

int main()
{
    /* if you want to both read the input MIPS instructions and write the output binary codes in files then keep both the
    the freopen fuction call open. If you wnat to take the input from the file and print the output in console then keep
    the first freopen and the second one closed .. and so on.....*/


    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    help();

    string instruction;
    while(getline(cin,instruction)){
        toLower(instruction);
        vector<string> v=split(instruction);

        // condition to eliminate empty or any other invalid string
        if (v.size()<2){
            continue;
        }

        bool spaces=true; //if spaces is true there will be spaces in the output string separating the data fields otherwise not


        /*if you want to see the mips instruction be along with the binary code in the output file keep this line*/
        //cout<<instruction<<endl;

        // In total 11 different instructions are supported by this program
        if (v[0]=="add" || v[0]=="sub" || v[0]=="and" || v[0]=="nand" || v[0]=="xor" || v[0]=="sll" || v[0]=="slt"){
            R_type data(v);
            data.solve();
            if (data.errorMessage.empty()){
                printCode(data.translated,spaces);
            }
            else {
                cout<<data.errorMessage<<endl;
            }

        }
        else if (v[0]=="lw" || v[0]=="sw" || v[0]=="beq" || v[0]=="addi"|| v[0]=="njmp" || v[0]=="pjmp" || v[0]=="slti" || v[0]=="disp" || v[0]=="la" || v[0]== "lai"){
            Itype data(v);
            data.solve();
            if (data.errorMessage.empty()){
                 printCode(data.translated,spaces);

            }
            else {
               cout<<data.errorMessage<<endl;
            }

        }
        else {
            cout<<"ERROR: Can't recognize the instruction "<<v[0]<<endl;
        }

    }


    return 0;
}
