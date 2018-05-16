#include "I_type.h"


Itype::Itype(){
}

Itype::Itype(vector<string> a){
    v=a;
}


// deals with the lw and sw type instruction
void Itype::memAccess(){
    if (v.size()<3){
        errorMessage+="ERROR: Not enough data fields. ";
        return;
    }
    else if (v.size()>3){
        errorMessage+="ERROR: Too much data fields. ";
        return;
    }

    if (m.find(v[1])==m.end()){
        errorMessage="ERROR: Register number "+v[1]+" is not valid";
        return;
    }

    if (v[0]=="lw"){
        translated=toBinary(3,4);
    }
    else {
        translated=toBinary(4,4);
    }

    if (toInt(v[2])>3){
        errorMessage="ERROR: Offset value can not be more than 3";
        return;
    }
    if (toInt(v[2])<0){
        errorMessage="ERROR: Offset value can not be negative";
    }

  //  translated+=" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
  translated=translated+m[v[1]]+toBinary(toInt(v[2]),2);
     translated=binaryToHex(translated);


}

// deals with beq and bne type instruction
void Itype::decision(){



    if(v[0]=="beq"){

        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (toInt(v[2])>3){
            errorMessage="ERROR: jump value can not be more than 3";
            return;
        }

        if (toInt(v[2])<0){
            errorMessage="ERROR: jump value can not be less than 0";
            return;
        }

        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }
    }
    else if(v[0]=="addi")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }


            if (toInt(v[2])>3){
                errorMessage="ERROR: constant value can not be more than 7";
                return;
            }

            if (toInt(v[2])<0){
                errorMessage="ERROR: constant value can not be less than 0";
                return;
            }



        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }

      else if(v[0]=="pjmp")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }


        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }


         else if(v[0]=="njmp")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }


        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }

      else if(v[0]=="lai")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }


            if (toInt(v[2])>3){
                errorMessage="ERROR: constant value can not be more than 3";
                return;
            }

            if (toInt(v[2])<0){
                errorMessage="ERROR: constant value can not be less than 0";
                return;
            }



        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }


      else if(v[0]=="disp")
    {
        if (v.size()<2){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>2){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }

       else if(v[0]=="la")
    {
        if (v.size()<2){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>2){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }

    else if(v[0]=="slti")
    {
        if (v.size()<3){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>3){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (toInt(v[2])>3){
                errorMessage="ERROR: constant value can not be more than 3";
                return;
            }

            if (toInt(v[2])<0){
                errorMessage="ERROR: constant value can not be less than 0";
                return;
            }

        if (m.find(v[1])==m.end()){
            errorMessage="ERROR: Register number "+v[1]+" is not valid";
            return;
        }

    }


    else{
        if (v.size()<2){
            errorMessage+="ERROR: Not enough data fields. ";
            return;
        }
        else if (v.size()>2){
            errorMessage+="ERROR: Too much data fields. ";
            return;
        }

        if (toInt(v[1])>3){
            errorMessage="ERROR: jump value can not be more than 3";
            return;
        }

        if (toInt(v[1])<0){
            errorMessage="ERROR: jump value can not be less than 0";
            return;
        }
    }



    if (v[0]=="beq"){
       // translated=toBinary(6,4);
      //  translated+=" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
      translated=toBinary(6,4);
        translated=translated+m[v[1]]+toBinary(toInt(v[2]),2);
           translated=binaryToHex(translated);


    }
    else if(v[0]=="addi")
    {
         //translated+=toBinary(1,4)+" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
         translated+=binaryToHex( toBinary(1,4)+m[v[1]]+toBinary(toInt(v[2]),2));
    }

     else if(v[0]=="disp")
    {
         //translated+=toBinary(13,4)+" "+m[v[1]]+" "+toBinary(0,2);
          translated+=binaryToHex(toBinary(13,4)+m[v[1]]+toBinary(0,2));
    }

     else if(v[0]=="la")
    {
        // translated+=toBinary(14,4)+" "+toBinary(0,2)+" "+m[v[1]];
        //translated+=binaryToHex(toBinary(14,4)+m[v[1]]+toBinary(0,2));
        translated+=binaryToHex(toBinary(14,4)+ m[v[1]]+toBinary(0,2));
    }

    else if(v[0]=="lai")
    {
          //translated+=toBinary(15,4)+" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
           translated+=binaryToHex(toBinary(15,4)+m[v[1]]+toBinary(toInt(v[2]),2));
    }

     else if(v[0]=="slti")
    {
         //translated+=toBinary(12,4)+" "+m[v[1]]+" "+toBinary(toInt(v[2]),2);
          translated+=binaryToHex(toBinary(12,4)+m[v[1]]+toBinary(toInt(v[2]),2));
    }

     else if(v[0]=="pjmp")
    {
            //translated+=binaryToHex(toBinary(7,4)+toBinary(0,2)+toBinary(toInt(v[2]),2));
             translated+=binaryToHex(toBinary(7,4)+toBinary(0,2)+toBinary(toInt(v[2]),2));
    }

       else if(v[0]=="njmp")
    {
            //translated+=binaryToHex(toBinary(7,4)+toBinary(0,2)+toBinary(toInt(v[2]),2));
             translated+=binaryToHex(toBinary(9,4)+toBinary(0,2)+toBinary(toInt(v[2]),2));
    }


}






void Itype::solve(){


    if (v[0]=="lw" || v[0]=="sw"){
        return memAccess();
    }
    else if (v[0]=="beq" || v[0]=="pjmp" || v[0]=="njmp" ){
        return decision();
    }
    else if (v[0]=="addi"){
        return decision();
    }
    else if (v[0]=="slti"){
        return decision();
    }
     else if (v[0]=="disp"){
        return decision();
    }

    else if (v[0]=="la"){
        return decision();
    }
      else if (v[0]=="lai"){
        return decision();
    }
}
