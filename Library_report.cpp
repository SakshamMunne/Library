#include<iostream>
using namespace std;

int books(){
    string name;
    int arr[100];
    int no;
    
    cout<<"HOW MANY NO OF BOOKS YOU WANT TO ISSUE"<<endl;   
    cin>>no;
    if(no<=0 || no>100){
        cout<<"ID ENTERED IS INVALID...!"<<endl;
        return 0;
    }
    cout<<"WRITE THE ID's OF THE  "<<no<<"  BOOKS ISSUED"<<endl;
    for(int i=0;i<no;i++){
        cout<<"ID of book "<<i+1<<": ";
        cin>>arr[i];
    }
   
    
    
    if (no<=0 || no>100) {
        cout << "ID ENTERED IS INVALID...!" << endl;
        return 0;
    } else {
        cout<<"WRITE THE NAMES OF THE  "<<no<<"  BOOKS ISSUED"<<endl;
        for(int i=0;i<no;i++){
        cout<<"ENTER THE NAMES OF BOOK "<<i+1<<": ";
        cin>>name;
        }
        cout<<endl<<endl;
        for(int i=0;i<no;i++){
            cout<<"THE NAME OF BOOK "<<i+1<<" IS: "<<name<<" AND IT's ID IS: "<<arr[i]<<endl;
        }
        cout<<endl;
    }   
    cout<<"BOOKS ISSUED SUCCESSFULLY...!"<<endl<<endl;
    return no;
}

void issue(){
    int no;    
    cout<<"ENTER THE NO OF DAYS YOU WANT TO ISSUE THE BOOKS (MAX 14 DAYS): "<<endl;
    if(no>14){
        cout<<"YOU CANNOT ISSUE THE BOOKS FOR MORE THAN 14 DAYS...!"<<endl;
        return;
    }
    cin>>no;
    cout<<"BOOKS ARE ISSUED FOR  "<<no<<"  DAYS FORM THE DATE OF ISSUE...! "<<endl<<endl;
}
void returnBook(){
    int no;
    cout<<"ENTER THE NO OF DAYS YOU HAVE KEPT THE BOOKS: "<<endl;
    cin>>no;
    if(no>14){
        cout<<"YOU HAVE KEPT THE BOOKS FOR  "<<no<<"  DAYS AND IT'S OVERDUE...!"<<endl;
        cout<<"YOU HAVE TO PAY FINE OF RS.  "<<(no-14)*5<<"  FOR THE OVERDUE BOOKS...!"<<endl<<endl;
    }
    else{
        cout<<"BOOKS RETURNED SUCCESSFULLY...!"<<endl<<endl;
    }
}
int main(){
    int choice;
    do{
        cout<<"WELCOME TO LIBRARY MANAGEMENT SYSTEM...!"<<endl;
        cout<<"1. ISSUE BOOKS"<<endl;
        cout<<"2. RETURN BOOKS"<<endl;
        cout<<"3. EXIT "<<endl;
        cout<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        switch(choice){
            case 1:
                books();
                issue();
                break;
            case 2:
                returnBook();
                break;
            case 3:
                cout<<"THANK YOU FOR USING LIBRARY MANAGEMENT SYSTEM...!"<<endl;
                break;
            default:
                cout<<"INVALID CHOICE...!"<<endl;
        }
    }
    while(choice!=3);    
    return 0;
}