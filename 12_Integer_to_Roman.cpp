class Solution {
public:
    string intToRoman(int num) {
        string s;
        int n1=num/1000;
        int n2=(num%1000)/100;
        int n3=((num%1000)%100)/10;
        int n4=((num%1000)%100)%10;
        for(int i=0;i<n1;i++){
            s.append("M");
        }
        switch(n2){
            case 1:
                s.append("C");
                break;
            case 2:
                s.append("CC");
                break;
            case 3:
                s.append("CCC");
                break;
            case 4:
                s.append("CD");
                break;
            case 5:
                s.append("D");
                break;
            case 6:
                s.append("DC");
                break;
            case 7:
                s.append("DCC");
                break;
            case 8:
                s.append("DCCC");
                break;
            case 9:
                s.append("CM");
                break;
        }
        switch(n3){
            case 1:
                s.append("X");
                break;
            case 2:
                s.append("XX");
                break;
            case 3:
                s.append("XXX");
                break;
            case 4:
                s.append("XL");
                break;
            case 5:
                s.append("L");
                break;
            case 6:
                s.append("LX");
                break;
            case 7:
                s.append("LXX");
                break;
            case 8:
                s.append("LXXX");
                break;
            case 9:
                s.append("XC");
                break;
        }
        switch(n4){
            case 1:
                s.append("I");
                break;
            case 2:
                s.append("II");
                break;
            case 3:
                s.append("III");
                break;
            case 4:
                s.append("IV");
                break;
            case 5:
                s.append("V");
                break;
            case 6:
                s.append("VI");
                break;
            case 7:
                s.append("VII");
                break;
            case 8:
                s.append("VIII");
                break;
            case 9:
                s.append("IX");
                break;
        }
        return s;
    }
};