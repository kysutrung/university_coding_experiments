#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book{
public:
    int id;
    string author;
    string title;
    bool isBorrowed;

    Book(int id, string title, string author)
        :id(id), title(title), author(author), isBorrowed(false){}

    void display(){
        cout<<"ID: "<<id<<", Author: "<<author<<", Title: "<<title<<", Status: "<<(isBorrowed ? "Borrowed" : "Available")<<endl; 
    }
};

class User{
public:
    int id;
    string name;

    User(int id, string name)
        :id(id), name(name){}

    void display(){
        cout<<"ID: "<<id<<", Name: "<<name<<endl;
    }
};

class Transaction{
public:
    int bookID;
    int userID;
    string date;

    Transaction(int bookID, int userID, string date)
        :bookID(bookID), userID(userID), date(date){}

    void display(){
        cout<<"Book ID: "<<bookID<<", User ID: "<<userID<<", Borrow Date: "<<date<<endl;
    }
};

vector<Book> books;
vector<Transaction> transactions;
vector<User> users;

void mainMenuDisplay(){
    cout<<"\nCHUONG TRINH QUAN LY THU VIEN 0.1\n"<<endl;
    cout<<"1 - Quan ly sach"<<endl;
    cout<<"2 - Quan ly nguoi dung"<<endl;
    cout<<"3 - Quan ly muon tra"<<endl;
    cout<<"4 - Thoat"<<endl;
    cout<<"\nLua chon: ";
}

void manageBooks(){
    int choice;
    do{
        cout<<"\nQUAN LY SACH\n"<<endl;
        cout<<"1 - Them sach"<<endl;
        cout<<"2 - Xoa sach"<<endl;
        cout<<"3 - Hien thi tat ca sach"<<endl;
        cout<<"4 - Quay lai"<<endl;
        cout<<"\nLua chon: ";
        cin>>choice;
        
        if(choice == 1){
            int id;
            string title;
            string author;

            cout<<"ID: ";
            cin>>id;
            cin.ignore();
            cout<<"Ten sach: ";
            getline(cin, title);
            cout<<"Tac gia: ";
            getline(cin, author);
            books.emplace_back(id, title, author);
            cout<<"\nDone\n";
        }
        else if(choice == 2){
            int id;
            bool done_a = 0;
            cout<<"ID sach can xoa: ";
            cin>>id;

            for(size_t u = 0; u < books.size(); u++){
                if(books[u].id == id){
                    books.erase(books.begin() + u);
                    done_a = 1;
                }
                if(done_a == 1){
                    cout<<"Done\n";
                }
                else{
                    cout<<"Wrong ID\n";
                }
            }
        }
        else if(choice == 3){
            cout<<"\nTAT CA SACH TRONG THU VIEN\n";
            for(auto &Book : books){
                Book.display();
            }
        }
    }while (choice != 4);
}

void manageUsers(){
    int choice;
    do{
        cout<<"\nQUAN LY NGUOI DUNG\n"<<endl;
        cout<<"1 - Them nguoi dung"<<endl;
        cout<<"2 - Xoa nguoi dung"<<endl;
        cout<<"3 - Hien thi tat ca nguoi dung"<<endl;
        cout<<"4 - Quay lai"<<endl;
        cout<<"\nLua chon: ";
        cin>>choice;
        
        if(choice == 1){
            int id;
            string name;

            cout<<"ID: ";
            cin>>id;
            cin.ignore();
            cout<<"Ten nguoi dung: ";
            getline(cin, name);
            users.emplace_back(id, name);
            cout<<"\nDone\n";
        }
        else if(choice == 2){
            int id;
            bool done_a = 0;
            cout<<"ID nguoi can xoa: ";
            cin>>id;

            for(size_t u = 0; u < users.size(); u++){
                if(users[u].id == id){
                    users.erase(users.begin() + u);
                    done_a = 1;
                }
                if(done_a == 1){
                    cout<<"Done\n";
                }
                else{
                    cout<<"Wrong ID\n";
                }
            }
        }
        else if(choice == 3){
            cout<<"\nTAT CA NGUOI DUNG THU VIEN\n";
            for(auto &User : users){
                User.display();
            }
        }
    }while (choice != 4);
}

void manageTransaction(){
    int choice;
    do{
        cout<<"\nQUAN LY MUON TRA SACH\n"<<endl;
        cout<<"1 - Muon sach"<<endl;
        cout<<"2 - Tra sach"<<endl;
        cout<<"3 - Hien thi tat ca sach dang duoc muon"<<endl;
        cout<<"4 - Quay lai"<<endl;
        cout<<"\nLua chon: ";
        cin>>choice;
        
        if(choice == 1){
            int bookID;
            int userID;
            string date;

            cout<<"User ID: ";
            cin>>userID;
            cin.ignore();
            cout<<"Book ID: ";
            cin>>bookID;
            cin.ignore();
            cout<<"Ngay muon sach: ";
            getline(cin, date);

            for(size_t y = 0; y < books.size(); y++){
                if(books[y].id == bookID){
                    books[y].isBorrowed = true;
                    transactions.emplace_back(bookID, userID, date);
                    cout<<"\nDone\n";
                }
                else{
                    cout<<"\nWrong ID\n";
                }
            }
        }
        else if(choice == 2){
            int id_a;
            int id_b;
            bool done_a = 0;
            cout<<"ID nguoi tra sach: ";
            cin>>id_a;
            cout<<"ID sach can tra: ";
            cin>>id_b;


            for(size_t u = 0; u < transactions.size(); u++){
                if(transactions[u].userID == id_a){
                    for(size_t i = 0; i < transactions.size(); i++){
                        if(transactions[u].bookID == id_b){
                            transactions.erase(transactions.begin() + u);
                            for(size_t y = 0; y < books.size(); y++){
                                if(books[y].id == id_b){
                                    books[y].isBorrowed = false;
                                    cout<<"\nDone\n";
                                }
                            }
                            done_a = 1;
                        }
                    }
                }
                if(done_a == 1){
                    cout<<"Done\n";
                }
                else{
                    cout<<"Wrong ID\n";
                }
            }
        }
        else if(choice == 3){
            cout<<"\nTAT CA SACH DANG DUOC MUON\n";
            for(auto &Transaction : transactions){
                Transaction.display();
            }
        }
    }while (choice != 4);
}

int main(){
    int choice_a;
    do{
        mainMenuDisplay();
        cin>>choice_a;
        if(choice_a == 1){
            manageBooks();
        }
        else if(choice_a == 2){
            manageUsers();
        }
        else if(choice_a == 3){
            manageTransaction();
        }
    }while(choice_a != 4);
}