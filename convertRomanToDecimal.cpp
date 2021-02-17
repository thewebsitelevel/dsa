int romanToDecimal(string &str) {
    int number=0;
    int i=str.length()-1;
    if(str[i]== 'I'){
        number= 1;
    }else if(str[i]== 'V'){
        number= 5;
    }else if(str[i]== 'X'){
        number= 10;
    }else if(str[i]== 'L'){
        number= 50;
    }else if(str[i]== 'C'){
        number = 100;
    }else if(str[i]== 'D'){
        number = 500;
    }else if(str[i]== 'M'){
        number = 1000;
    }
    int prev= number;
    int curr;
    for( i=str.length()-2; i>=0; i--){
        
        if(str[i]== 'I'){
            curr= 1;
        }else if(str[i]== 'V'){
            curr= 5;
        }else if(str[i]== 'X'){
            curr= 10;
        }else if(str[i]== 'L'){
            curr= 50;
        }else if(str[i]== 'C'){
            curr = 100;
        }else if(str[i]== 'D'){
            curr = 500;
        }else if(str[i]== 'M'){
            curr = 1000;
        }
        if(curr < prev){
            number -= curr;
            prev=curr;
        }else{
            number+= curr;
            prev= curr;
        }
    }
    return number;
}