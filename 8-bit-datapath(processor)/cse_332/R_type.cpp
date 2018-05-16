#include "R_type.h"




R_type::R_type(){
}

R_type::R_type(vector<string> a){
    v=a;
}
string to_string(long long a){

    stringstream ss;
    ss<<a;
    string n=ss.str();
return n;
}
int toInt(string s){
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
}
string binaryToHex(string s)
{
    long long a = toInt(s);
    //cout << "int " << a << endl;
    //long long a2 = toInt(s.substr(5,4));
    long long res = 0;
    //long long res2;
    long long rem;
    //long long res2;
    string str_hex = "";
    //string s2;
    long long base = 1;

    while (a > 0)
    {
        rem = a % 10;
        res =  res  + rem * base;
        base = base * 2;
        a /= 10;
    }
    //cout << "bin to dec " << res << endl;
    while (res > 0) {
        rem = res % 16;
        if (rem > 9) {
            switch (rem) {
               case 10: str_hex += "a"; break;
               case 11: str_hex += "b"; break;
               case 12: str_hex += "c"; break;
               case 13: str_hex += "d"; break;
               case 14: str_hex += "e"; break;
               case 15: str_hex += "f"; break;
            }
        }
        else {
            str_hex += to_string(rem);
        }
        res = res / 16;
    }


    if(str_hex.length()==1)
    {
        //cout << "0"+str_hex;
        str_hex += "0";
        reverse(str_hex.begin(), str_hex.end());
        return str_hex;
    }
    else{
        reverse(str_hex.begin(), str_hex.end());
        return str_hex;
    }

}

// special function specifically written to deal with sll and slr
void R_type:: shift(){
    if (toInt(v[2])>2){
        errorMessage+="ERROR: shifting can not be done more than 2 times";
        return;
    }
    if (toInt(v[2])<0){
        errorMessage+="ERROR: shift amount can not be negative";
        return;
    }

    //translated=toBinary(5,4)+" "+m[v[1]]+" "+toBinary(toInt(v[2]),2)+" ";
     translated=binaryToHex( toBinary(5,4)+m[v[1]]+toBinary(toInt(v[2]),2));



}


void R_type::solve(){

     if (v.size()<3){
        errorMessage+="ERROR: Not enough data fields. ";
        return;
    }
    else if (v.size()>3){
        errorMessage+="ERROR: Too much data fields. ";
        return;
    }



    int vecsize = v.size();


    if (v[0]=="add"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        //translated+=toBinary(0,4)+" "+m[v[1]]+" "+m[v[2]];
        translated+=binaryToHex(toBinary(0,4)+m[v[1]]+m[v[2]]);
    }

    else if (v[0]=="sub"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
       // translated+=toBinary(2,4)+" "+m[v[1]]+" "+m[v[2]];
        translated+=binaryToHex(toBinary(2,4)+m[v[1]]+m[v[2]]);
    }

     else if (v[0]=="and"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
       // translated+=toBinary(8,4)+" "+m[v[1]]+" "+m[v[2]];
        translated+=binaryToHex(toBinary(8,4)+m[v[1]]+m[v[2]]);
    }

      else if (v[0]=="xor"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
      // translated+=toBinary(9,4)+" "+m[v[1]]+" "+m[v[2]];
       translated+=binaryToHex(toBinary(9,4)+m[v[1]]+m[v[2]]);
    }

       else if (v[0]=="nand"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        //translated+=toBinary(10,4)+" "+m[v[1]]+" "+m[v[2]];
        translated+=binaryToHex(toBinary(10,4)+m[v[1]]+m[v[2]]);
    }

       else if (v[0]=="slt"){
        for(int i=1;i<vecsize;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
       // translated+=toBinary(11,4)+" "+m[v[1]]+" "+m[v[2]];
       translated+=binaryToHex(toBinary(11,4)+m[v[1]]+m[v[2]]);
    }


    else if (v[0]=="sll"){
        for(int i=1;i<vecsize-1;i++){
           if (m.find(v[i])==m.end()){
                errorMessage+="ERROR: Register number "+v[i]+" is not valid";
                return;
           }
        }
        return shift();
    }


}
