
#include<bits/stdc++.h>

#include<conio.h>
 
using namespace std;

void train_del(int,string);

class login_creds{
    //int age;
    string username;
    string password;
    public:
    login_creds(){
        password="";
    }
    void getData(){
        //cin>>age;
        int i=0;
        cout<<"enter your username:";
        cin.ignore();
        getline(cin,username);
        char a;
        cout<<"enter you password(MAX 13 CHARECTERS):";
        while(i<13){
           a=getch();
           if(a=='\r'){
                cout<<'\n';
                break;
            }
            cout<<"*";
            password+=a;
            i++;
        }
    }
    
    
    
    
    string ret_username(){
        return username;
    }
        
    
    string ret_pass(){
         return password;
    }

};

class train_details{
    public:
    int tno;
    string t_name;
    string boarding_point;
    
    int no_of_stations;
    string state[10];
    string stations_in_between[20];
    
    string dest_point;

    int no_of_typecoaches;
    string typecoaches[10];
    
    int no_of_seats_per_coach[10];

    int no_of_wagons[10];


    
    void get_details(){
        cout<<"enter the tno:";
        cin>>tno;
        cout<<"enter the train name:";
        cin.ignore();
        getline(cin,t_name);
        cout<<"enter the state where the boarding station belongs to:";
        getline(cin,state[0]);
        cout<<"enter the boarding_point:";
        getline(cin,boarding_point);
        
        cout<<"enter the no of stations in between:";
        cin>>no_of_stations;
        cin.ignore();
        for(int i=0;i<no_of_stations;i++){
            cout<<"enter the state where the station belongs to:";
            getline(cin,state[i+1]);
            cout<<"enter the station:";
            getline(cin,stations_in_between[i]);
        }
        cout<<"enter the state where the dest station belongs to:";
        getline(cin,state[no_of_stations+1]);
        cout<<"enter the destination_point:";
        getline(cin,dest_point);
        cout<<"enter the no of type of coaches:";
        cin>>no_of_typecoaches;
        
        cin.ignore();
        for(int i=0;i<no_of_typecoaches;i++){
            cout<<"enter the type of coach:";
            getline(cin,typecoaches[i]);
        }
            
        

        for(int i=0;i<no_of_typecoaches;i++){
            cout<<"enter the no of seats of "<<typecoaches[i]<<" coach:";
            cin>>no_of_seats_per_coach[i];
        }

        
        

    }
    
    
};



class train_reserve_details{
    public:
    string t_name;
    string coach;
    string name[8];
    int age[8];
    int i;
    train_reserve_details(){
        i=0;
    }
    
    
    void get_detail(){
        cout<<"enter the train name:";
        getline(cin,t_name);
        cout<<"enter the coach you want to choose:";
        getline(cin,coach);
        char ch='y';
        int n=0;
        do{
            
            cout<<"enter the age:";
            cin>>age[i];
            if(age[i]>=6){
                n++;
                cout<<"enter the name of the passenger:";
                cin.ignore();
                getline(cin,name[i]);
            }
            else{
                cout<<"the passenger is infant no need of ticket\n";
            }

            if(i>6){
                cout<<"you have exceed limit of ticket reservation";
                break;
            }

            cout<<"do you want to add more passengers(press y for yes and n for no):";
            cin>>ch;
            i++;

            
                
        }while(ch=='y');
        

    }
};

class train_del_details{
    public:
    int pnr;
    string t_name;
    string coach;
    string name;
    int i;
    train_del_details(){
        i=0;
    }
    void get_details(){
        cin.ignore();
        cout<<"enter the train name:";
        getline(cin,t_name);
        cout<<"enter the coach:";
        getline(cin,coach);
        cout<<"enter pnr:";
        cin>>pnr;
        cin.ignore();
        char ch='y';
        
        do{
            cout<<"enter the name:";
            getline(cin,name);
            train_del(pnr,name);
            cout<<"do you want to delete more tickets(enter y for yes and n for no):";
            cin>>ch;
            cin.ignore();
            i++;
        }while(ch=='y');
    }



};




void writeData(char ch){
    
    login_creds s;
     
    ofstream file;
 
    //open file in write mode
    file.open("aaa.txt",ios::out|ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);
    }
   // cout<<"\nFile created successfully."<<endl;
    s.getData();
    file<<ch<<'\n';
    file<<s.ret_username()<<'\n';
    file<<s.ret_pass()<<'\n';
    cout<<'\n'<<"successfully created the login credentials\n";
 
    file.close();   //close the file
    //cout<<"\nFile saved and closed succesfully."<<endl;

}
 
string readData(string username,string pass){
    char ch;
    int flag=0;
    string userid,password,str;
    //re open file in input mode and read data
    //open file1
    ifstream file1;
    //again open file in read mode
    file1.open("aaa.txt",ios::in);
    if(!file1){
        cout<<"Error in opening file..";
        exit(EXIT_FAILURE);
    }
    //read data from file
    file1.seekg(0,ios::beg);
    while(!file1.eof()){
        file1>>ch;
        file1.ignore();
        if(!file1.eof()){
            getline(file1,userid);
            getline(file1,password);
            if(username==userid && password==pass && ch=='a'){
                
                flag=1;
                str="false";
                
            }
            else if(username==userid && password==pass){
                
                flag=2;
                str=="true";
            }
        }
    }
    file1.close();

    if(flag==0){
        return "pass/userid wrong";
    }
    else if(flag==1){
        return "false";
    }

    else if(flag==2){
        return "true";
    }    
 
    
} 

void writeData1(){
    
    train_details t;
     
    ofstream file;
 
    //open file in write mode
    file.open("aaa1.txt",ios::out|ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);
    }
    
 
    //write into file
    t.get_details();    //read from user
    file<<t.tno<<'\n';
    file<<t.t_name<<'\n';
    file<<t.state[0]<<':';
    file<<t.boarding_point<<'\n';
    file<<t.no_of_stations<<'\n';
    for(int i=0;i<t.no_of_stations;i++){
        file<<t.state[i+1]<<':'<<t.stations_in_between[i]<<'\n';
    }
    file<<t.state[t.no_of_stations+1]<<':'<<t.dest_point<<'\n';
    file<<t.no_of_typecoaches<<'\n';
    for(int i=0;i<t.no_of_typecoaches;i++){
        file<<t.typecoaches[i]<<':'<<t.no_of_seats_per_coach[i]<<'\n';
    }

 
    file.close();   //close the file
    
}

void readData1(string b_point,string d_point){
    cout<<"details of the train are:\n";
    train_details t;
    int no;
    string name;
    string states[10];
    string b_pt;
    string in_bt_st[10];
    string d_pt;
    int nost;
    int noc;
    string coach[10];
    int nos[10];

    //re open file in input mode and read data
    //open file1
    ifstream file1;
    //again open file in read mode
    file1.open("aaa1.txt",ios::in);
    if(!file1){
        cout<<"Error in opening file..";
        exit(EXIT_FAILURE);
    }
    //read data from file
    file1.seekg(0,ios::beg);
    while(!file1.eof()){
        file1>>no;
        if(!file1.eof()){
            file1.ignore();
            getline(file1,name);
            getline(file1,states[0],':');
            getline(file1,b_pt);
            file1>>nost;
            file1.ignore();
            for(int i=0;i<nost;i++){
                getline(file1,states[i+1],':');
                getline(file1,in_bt_st[i]);
            }
            getline(file1,states[nost+1],':');
            getline(file1,d_pt);
            file1>>noc;
            file1.ignore();

            for(int i=0;i<noc;i++){
                getline(file1,coach[i],':');
                file1>>nos[i];
                file1.ignore();

            }
            if((b_pt==b_point)&&(d_pt==d_point)){
                cout<<"TRAIN_NO:"<<no<<'\n';
                cout<<"TRAIN_NAME:"<<name<<'\n';
                cout<<"stations:\n";
                cout<<states[0]<<':'<<b_pt<<'\n';
                for(int i=0;i<nost;i++){
                    cout<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                cout<<states[nost+1]<<':'<<d_pt<<'\n';
                for(int i=0;i<noc;i++){
                    cout<<coach[i]<<':';
                    if(nos[i]>=0){
                        cout<<"available "<<nos[i]<<'\n';
                    }
                    else
                        cout<<"WL "<<abs(nos[i])<<'\n';
                }

            }



        }

    }
 
    //close the file
    file1.close();

} 

void modify_details(int t_no,string caoch,int n){
    ifstream file1("aaa1.txt",ios::in);
    ofstream file("temp.txt",ios::out|ios::app);
    train_details t;
    int no;
    string name;
    string states[10];
    string b_pt;
    string in_bt_st[10];
    string d_pt;
    int nost;
    int noc;
    string coach[10];
    int nos[10];
    if(!file||!file1){
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);

    }

    file1.seekg(0);
    while(!file1.eof()){
        
        file1>>no;
        if(!file1.eof()){
            file1.ignore();
            getline(file1,name);
            getline(file1,states[0],':');
            getline(file1,b_pt);
            file1>>nost;
            file1.ignore();
            for(int i=0;i<nost;i++){
                getline(file1,states[i+1],':');
                getline(file1,in_bt_st[i]);
            }
            getline(file1,states[nost+1],':');
            getline(file1,d_pt);
            file1>>noc;
            file1.ignore();

            for(int i=0;i<noc;i++){
                getline(file1,coach[i],':');
                file1>>nos[i];
                file1.ignore();

            }

            if(t_no==no){
                
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
                    if(caoch==coach[i]){
                        file<<coach[i]<<':'<<nos[i]+n<<'\n';


                    }
                    else{
                        file<<coach[i]<<':'<<nos[i]<<'\n';
                    }
                    
                }
            }
            else{
                
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
        
                    file<<coach[i]<<':'<<nos[i]<<'\n';
                }
                
            }
                
            
        }
    }
    file.close();
    file1.close();
    remove("aaa1.txt");
    rename("temp.txt","aaa1.txt");
    
    
}




void seat_allocation(){
    ifstream file1("aaa2.txt",ios::in);
    ifstream file("seat.txt",ios::in);
    ofstream file2("temp3.txt",ios::out|ios::app);
    if(!file1||!file||!file2){
        cout<<"couldnt open the file";
        exit(EXIT_FAILURE);
    }
    int pnr;
    string t_name;
    string bpt;
    string dpt;
    string p_name;
    string p_coach;
    int n,s;
    int age;
    while((!file1.eof()) || (!file.eof())){
        file>>s;
        file.ignore();
        file1>>pnr;
        file1.ignore();
        getline(file1,t_name);
        if(!file1.eof() || !file.eof()){
            getline(file1,bpt);
            getline(file1,dpt);
            getline(file1,p_coach);
            file1>>n;
            file1.ignore();
            file2<<pnr<<'\n';
            file2<<t_name<<'\n';
            file2<<bpt<<'\n';
            file2<<dpt<<'\n';
            file2<<p_coach<<'\n';
            file2<<n<<'\n';
            for(int i=0;i<n;i++){
                getline(file1,p_name,':');
                file1>>age;
                file1.ignore();
                file2<<p_name<<':'<<age<<' ';
                if(s>0){
                    file2<<"confirm "<<s<<'\n';
                }   
                else{
                    file2<<"WL "<<abs(s-1)<<'\n';
                }
                file>>s;
                file.ignore();

            }
        }
        
    }
    file.close();
    file1.close();
    file2.close();
    remove("aaa2.txt");
    remove("seat.txt");
    rename("temp3.txt","aaa2.txt");
    
}

void seat_reallocation(string d_status[10],int d_seat[10],string d_t_name,string d_bpt,string d_dpt,string d_pcoach,int k){
    ifstream file("aaa2.txt",ios::in);
    ofstream file1("temp4.txt",ios::out|ios::app);
    int pnr;
    string t_name;
    string bpt,dpt;
    string p_coach;
    string p_name[10];
    string status[10];
    int n;
    int age[10];
    int seat[10];
    file.seekg(0);
    while(!file.eof()){
        file>>pnr;
        file.ignore();
        if(!file.eof()){
            getline(file,t_name);
            getline(file,bpt);
            getline(file,dpt);
            getline(file,p_coach);
            file>>n;
            file.ignore();
            if(t_name==d_t_name && bpt==d_bpt && dpt==d_dpt && p_coach==d_pcoach){
                file1<<pnr<<'\n';
                file1<<t_name<<'\n';
                file1<<bpt<<'\n'<<dpt<<'\n';
                file1<<p_coach<<'\n';
                file1<<n<<'\n';

                for(int i=0;i<k;i++){
                    for(int j=0;j<n;j++){
                        getline(file,p_name[j],':');
                        file>>age[j];
                        file.ignore();
                        getline(file,status[j],' ');
                        file>>seat[j];
                        file.ignore();
                        if(d_status[i]=="confirm" && status[j]=="WL" && seat[j]==1){
                            file1<<p_name[j]<<':';
                            file1<<age[j]<<' ';
                            file1<<d_status[i]<<' '<<d_seat[i]<<'\n';
                        }
                        else if(status[j]=="WL" && seat[j]>1){
                            file1<<p_name[j]<<':';
                            file1<<age[j]<<' ';
                            file1<<status[j]<<' '<<seat[j]-1<<'\n';

                        }
                        else if(d_status[i]=="WL" && status[j]=="WL" && seat[j]>d_seat[i]){
                            file1<<p_name[j]<<':';
                            file1<<age[j]<<' ';
                            file1<<status[j]<<' '<<seat[j]-1<<'\n';

                        }
                        else{
                            file1<<p_name[j]<<':';
                            file1<<age[j]<<' ';
                            file1<<status[j]<<' '<<seat[j]<<'\n';


                        }
                    }

                }

            }
            
            
        }
    }
    file.close();
    file1.close();
    remove("aaa2.txt");
    rename("temp4.txt","aaa2.txt");
}

    



void ticket_del(string t_name,string caoch,int n){
    ifstream file1("aaa1.txt",ios::in);
    ofstream file("temp.txt",ios::out|ios::app);
    train_details t;
    int no;
    string name;
    string states[10];
    string b_pt;
    string in_bt_st[10];
    string d_pt;
    int nost;
    int noc;
    string coach[10];
    int nos[10];
    if(!file||!file1){
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);

    }

    file1.seekg(0);
    while(!file1.eof()){
        
        file1>>no;
        if(!file1.eof()){
            file1.ignore();
            getline(file1,name);
            getline(file1,states[0],':');
            getline(file1,b_pt);
            file1>>nost;
            file1.ignore();
            for(int i=0;i<nost;i++){
                getline(file1,states[i+1],':');
                getline(file1,in_bt_st[i]);
            }
            getline(file1,states[nost+1],':');
            getline(file1,d_pt);
            file1>>noc;
            file1.ignore();

            for(int i=0;i<noc;i++){
                getline(file1,coach[i],':');
                file1>>nos[i];
                file1.ignore();

            }

            if(t_name==name){
                
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
                    if(caoch==coach[i]){
                        file<<coach[i]<<':'<<nos[i]+n<<'\n';


                    }
                    else{
                        file<<coach[i]<<':'<<nos[i]<<'\n';
                    }
                    
                }
            }
            else{
                
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
        
                    file<<coach[i]<<':'<<nos[i]<<'\n';
                }
                
            }
                
            
        }
    }
    file.close();
    file1.close();
    remove("aaa1.txt");
    rename("temp.txt","aaa1.txt");
    
    


}

void ticket_reserve(string t_name,string caoch,int n,string bd_pt,string dest_pt){
    ifstream file1("aaa1.txt",ios::in);
    ofstream file("temp.txt",ios::out|ios::app);
    ofstream file2("seat.txt",ios::out|ios::app);
    int no;
    string name;
    string states[10];
    string b_pt;
    string in_bt_st[10];
    string d_pt;
    int nost;
    int noc;
    string coach[10];
    int nos[10];
    if(!file||!file1||!file2){
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);

    }

    file1.seekg(0);
    while(!file1.eof()){
        
        file1>>no;
        if(!file1.eof()){
            file1.ignore();
            getline(file1,name);
            getline(file1,states[0],':');
            getline(file1,b_pt);
            file1>>nost;
            file1.ignore();
            for(int i=0;i<nost;i++){
                getline(file1,states[i+1],':');
                getline(file1,in_bt_st[i]);
            }
            getline(file1,states[nost+1],':');
            getline(file1,d_pt);
            file1>>noc;
            file1.ignore();

            for(int i=0;i<noc;i++){
                getline(file1,coach[i],':');
                file1>>nos[i];
                file1.ignore();

            }

            if(t_name==name && b_pt==bd_pt && d_pt==dest_pt){
                
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
                    if(caoch==coach[i]){
                        file<<coach[i]<<':'<<nos[i]-n<<'\n';
                        for(int j=0;j<n;j++){
                            
                            file2<<nos[i]-j;
                            file2<<'\n';

                        }
                        file2.close();
                        
                    }
                    else{
                        file<<coach[i]<<':'<<nos[i]<<'\n';
                    }
                    
                }
            }
            else{
                file<<no<<'\n';
                file<<name<<'\n';
                file<<states[0]<<':'<<b_pt<<'\n';
                file<<nost<<'\n';
                for(int i=0;i<nost;i++){
                    file<<states[i+1]<<":"<<in_bt_st[i]<<'\n';
                }
                file<<states[nost+1]<<':'<<d_pt<<'\n';
                file<<noc<<'\n';
                for(int i=0;i<noc;i++){
                    file<<coach[i]<<':'<<nos[i];
                }

            }
                
            
        }
    }
    file.close();
    file1.close();
    remove("aaa1.txt");
    rename("temp.txt","aaa1.txt");
    
    


}

void show_ticket_status(int pass_no){
    cout<<"your ticket details are:\n";
    ifstream file("aaa2.txt",ios::in);
    int pnr;
    string t_name;
    string b_pt;
    string d_pt;
    string coach;
    int n;
    string p_name[10];
    int age[10];
    string status[10];
    int seat[10];
    file.seekg(0);
    while(!file.eof()){
        file>>pnr;
        file.ignore();
        if(!file.eof()){
            getline(file,t_name);
            getline(file,b_pt);
            getline(file,d_pt);
            getline(file,coach);
            file>>n;
            file.ignore();
            for(int i=0;i<n-1;i++){
                getline(file,p_name[i],':');
                file>>age[i];
                file.ignore();
                getline(file,status[i],' ');
                file>>seat[i];
                file.ignore();
            }
            getline(file,p_name[n-1],':');
            file>>age[n-1];
            file.ignore();
            getline(file,status[n-1],' ');
            file>>seat[n-1];

            if(pnr==pass_no){
                cout<<"PNR:"<<pnr<<'\n'<<"TRAIN NAME:"<<t_name<<'\n'<<"BOARDING POINT:"<<
                b_pt<<'\n'<<"DESTINATION POINT:"<<d_pt<<'\n'<<"COACH:"<<coach<<'\n'<<
                "No of tickets reserved:"<<n<<'\n'<<"NAME\tAGE\tTICKET STATUS\tSEAT_NO\n";
                for(int i=0;i<n;i++){
                    cout<<p_name[i]<<'\t'<<age[i]<<'\t'<<status[i]<<'\t';
                    if(status[i]=="confirm"){
                        cout<<'\t'<<seat[i]<<'\n';
                    }
                    else{
                        cout<<'\t'<<"WL_NO."<<seat[i]<<'\n';
                    }
                }

            }

        }
    }
    file.close();
}




void train_reserve(string b_pt,string d_pt){
    train_reserve_details tr;
     
    ofstream file;
 
    //open file in write mode
    file.open("aaa2.txt",ios::out|ios::app);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      exit(EXIT_FAILURE);
    }
    
 
    //write into file
    tr.get_detail();    //read from user
      //write into file
    static int pnr=999;
    pnr+=1;
    file<<pnr<<'\n';
    file<<tr.t_name<<'\n';
    file<<b_pt<<'\n';
    file<<d_pt<<'\n';
    file<<tr.coach<<'\n';
    file<<tr.i<<'\n';
    for(int i=0;i<tr.i;i++){
        
        file<<tr.name[i]<<':'<<tr.age[i]<<'\n';
        
    }
    file.close();
    ticket_reserve(tr.t_name,tr.coach,tr.i,b_pt,d_pt);
    seat_allocation();
    cout<<"you have successfully reserved\n";
    show_ticket_status(pnr);

}

void train_del(int pass_no,string name){
    ifstream file2("aaa2.txt",ios::in);
    ofstream file3("temp1.txt",ios::app|ios::out);
    if(!file2){
        cout<<"Error in creating file.."<<endl;
        exit(EXIT_FAILURE);
    }
    
    int pnr;
    string t_name;
    string del_t_name;
    string b_pt;
    string del_b_pt;
    string d_pt;
    string del_d_pt;
    string p_name[10];
    string p_coach;
    string del_p_coach;
    string status[10];
    string del_status[10];
    int del_seat[10];
    int n;
    int age[10];
    int seat[10];
    int k=0;
    file2.seekg(0);
    
    while(!file2.eof()){
        file2>>pnr;
        file2.ignore();
        getline(file2,t_name);
        if(!file2.eof()){
            getline(file2,b_pt);
            getline(file2,d_pt);
            getline(file2,p_coach);
            file2>>n;
            file2.ignore();
            if(pnr==pass_no){
                file3.seekp(0);
                file3<<pnr<<'\n';
                del_t_name=t_name;
                file3<<t_name<<'\n';
                file3<<b_pt<<'\n'<<d_pt<<'\n';
                del_b_pt=b_pt;
                del_d_pt=d_pt;
                file3<<p_coach<<'\n';
                del_p_coach=p_coach;
                file3<<n-1<<'\n';
                
                for(int j=0;j<n;j++){
                    getline(file2,p_name[j],':');
                    file2>>age[j];
                    file2.ignore();
                    getline(file2,status[j],' ');
                    file2>>seat[j];
                    file2.ignore();
                    if(name!=p_name[j]){
                        file3<<p_name[j]<<':'<<age[j]<<' '<<status[j]<<' '<<seat[j]<<'\n';
                    }
                    else{
                        del_status[k]=status[j];
                        del_seat[k]=seat[j];
                        k++;
                    }
                    
                }
            }
            
            ticket_del(t_name,p_coach,1);
            
            
        }
        
        
        
    }

    file2.close();
    file3.close();
    remove("aaa2.txt");
    rename("temp1.txt","aaa2.txt");
    seat_reallocation(del_status,del_seat,del_t_name,del_b_pt,del_d_pt,del_p_coach,k);
    cout<<"you have successfully deleted the tickets\n";

}





int main(){
    cout<<"\t\tWELCOME TO INDIAN RAILWAYS\n\n";
    string user;
    int choice,pass_no,id=1234,flag1=0;
    char ch='y',ch1,ch2,ch3='y';
    string username,b_point,d_point,password="";
    while(ch3=='y'){
        cout<<"ADMIN OR USER:(enter a for admin and any other letter for user):";
        cin>>ch1;
        cout<<"NEW USER OR EXISTING USER(enter y for new user,any letter for existing user):";
        cin>>ch2;
        //cin.ignore();
        

        if(ch1=='a'&& ch2=='y'){
            cout<<"enter the password to create an account:";
            cin>>id;
            if(id==1234){
                writeData(ch1);
            }
            cout<<"Do you want to go to the main menu(y for Yes and any letter for No):";
            cin>>ch3;
            if(ch3!='y'){
                cout<<"\nThank you for choosing Indian Railways";
                exit(EXIT_FAILURE);

            }
        }
        else if(ch2=='y'){
            writeData(ch1);
            cout<<"Do you want to go to the main menu(y for Yes and any letter for No):";
            cin>>ch3;
            if(ch3!='y'){
                cout<<"\nThank you for choosing Indian Railways";
                exit(EXIT_FAILURE);

            }
        }
 

        else{
            int i=0,flag=0;

            while(i<3){
               
                cout<<"enter the username:";
                cin.ignore();
                getline(cin,username);
                cout<<"enter the password:";
                char a;
                while(i<13){
                    a=getch();
                        if(a=='\r'){
                        cout<<'\n';
                        break;
                    }
                    cout<<"*";
                    password+=a;
                    i++;
                }
                user=readData(username,password);
                if(user=="pass/userid wrong"){
                    cout<<"entered a wrong password or userid\n";
                    cout<<"please try again\n";
                    i++;
                }
                else{
                    flag=1;
                    flag1=1;
                    break;
                }

            }
            if(flag==0){
                cout<<"\nSorry exceded the no of attempts";
                exit(EXIT_FAILURE);
            }

        

        }
        if(flag1==1){
            break;
        }

    }
        
    
    if(user=="false"){
        while(ch=='y'){
            cout<<"please enter your choice\n";
            cout<<"1.add train information\n";
            cout<<"2.add no of seats in a coach of the train\n";
            cout<<"3.exit\n";
            cin>>choice;
            if(choice==1){
                cout<<"enter the details of the train:\n";
                writeData1();
                cout<<"Do you want to go to main menu:(y for Yes and any letter for No) ";
                cin>>ch;
                cin.ignore();
                if(ch!='y'){
                    cout<<"Thank you for choosing Indian Railways";
                    exit(EXIT_FAILURE);
                    
                }
            }
            else if(choice==2){
                int t_no,n;
                string coach;
                cout<<"enter the t_no";
                cin>>t_no;
                cin.ignore();
                cout<<"enter the coach:";
                getline(cin,coach);
                cout<<"enter the no of seats:";
                cin>>n;
                modify_details(t_no,coach,n);
                cout<<"Do you want to go to main menu:(y for Yes and any letter for No) ";
                cin>>ch;
                cin.ignore();
                if(ch!='y'){
                    cout<<"Thank you for choosing Indian Railways";
                    exit(EXIT_FAILURE);
                    
                }
            }
            
        }
        
    }
    

    



    else if(user=="true"){
        
        while(ch=='y'){
            cout<<"please enter you choice\n";
            cout<<"1.Reserve ticket\n";
            cout<<"2.Delete ticket\n";
            cout<<"3.Get ticket status\n";
            cout<<"4.Exit\n";
            cin>>choice;
            
            if(choice==1){
                
                cout<<"enter the boarding point:";
                cin.ignore();
                getline(cin,b_point);
                cout<<"enter the destination point:";
                getline(cin,d_point);
                readData1(b_point,d_point);
                train_reserve(b_point,d_point);
                cout<<"Do you want to go to main menu:(y for Yes and any letter for No) ";
                cin>>ch;
                cin.ignore();
                if(ch!='y'){
                    
                    cout<<"Thank you for choosing Indian Railways";
                    exit(EXIT_FAILURE);
                    
                }

            }

            else if(choice==2){
                
                train_del_details tr;
                tr.get_details();
                cout<<"Do you want to go to main menu:(y for Yes and any letter for No) ";
                cin>>ch;
                cin.ignore();
                if(ch!='y'){
                    
                    cout<<"Thank you for choosing Indian Railways";
                    exit(EXIT_FAILURE);
                    
                }


            }

            else if(choice==3){

                cout<<"enter the pnr:";
                cin>>pass_no;
                show_ticket_status(pass_no);
                cout<<"Do you want to go to main menu:(y for Yes and any letter for No) ";
                cin>>ch;
                cin.ignore();
                if(ch!='y'){
                    
                    cout<<"Thank you for choosing Indian Railways";
                    exit(EXIT_FAILURE);
                    
                }

            }

            else if(choice==4){
                cout<<"Thank you for choosing Indian Railways";
                exit(EXIT_FAILURE);
            }

        }
        
        
        
    }
    
    
    return 0;

}





