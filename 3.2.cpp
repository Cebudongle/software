class student1:public student{
    public:
        string RandomNum(){
            return to_string (random()%10000);
        }
        string RandomOp(){
            string str1="+",str2="-",str3="*",str4="/";
            switch(random()%4){
                case 0:
                    return str1;
                case 1:
                    return str2;
                case 2:
                    return str3;
                case 3:
                    return str4;
                default:
                    break;
            }
        }
};
