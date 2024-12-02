#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Lop Sach
class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    Book(int id, string title, string author) 
        : id(id), title(title), author(author), isBorrowed(false) {}

    void display() {
        cout << "ID: " << id << ", Ten sach: " << title 
             << ", Tac gia: " << author 
             << ", Trang thai: " << (isBorrowed ? "Da muon" : "Co san") << endl;
    }
};

// Lop Nguoi dung
class User {
public:
    int id;
    string name;

    User(int id, string name) : id(id), name(name) {}

    void display() {
        cout << "ID: " << id << ", Ten nguoi dung: " << name << endl;
    }
};

// Lop Giao dich
class Transaction {
public:
    int bookId;
    int userId;
    string date;

    Transaction(int bookId, int userId, string date) 
        : bookId(bookId), userId(userId), date(date) {}

    void display() {
        cout << "Sach ID: " << bookId << ", Nguoi dung ID: " << userId 
             << ", Ngay muon: " << date << endl;
    }
};

// Danh sach luu tru
vector<Book> books;
vector<User> users;
vector<Transaction> transactions;

// Ham hien thi menu chinh
void displayMenu() {
    cout << "\n============================================" << endl;
    cout << "       CHUONG TRINH QUAN LY THU VIEN        " << endl;
    cout << "============================================" << endl;
    cout << "1. Quan ly sach                             " << endl;
    cout << "2. Quan ly nguoi dung                       " << endl;
    cout << "3. Quan ly giao dich                        " << endl;
    cout << "4. Tim kiem                                 " << endl;
    cout << "5. Thoat chuong trinh                       " << endl;
    cout << "============================================" << endl;
    cout << "Vui long nhap lua chon cua ban (1-5): ";
}

// Ham quan ly sach
void manageBooks() {
    int choice;
    do {
        cout << "\n============================================" << endl;
        cout << "               QUAN LY SACH                 " << endl;
        cout << "============================================" << endl;
        cout << "1. Them sach moi                            " << endl;
        cout << "2. Xoa sach                                 " << endl;
        cout << "3. Hien thi danh sach sach                  " << endl;
        cout << "4. Quay lai menu chinh                      " << endl;
        cout << "============================================" << endl;
        cout << "Vui long nhap lua chon cua ban (1-4): ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Nhap ID sach: ";
            cin >> id;
            cin.ignore(); // Loai bo ky tu xuong dong
            cout << "Nhap ten sach: ";
            getline(cin, title);
            cout << "Nhap ten tac gia: ";
            getline(cin, author);
            books.emplace_back(id, title, author);
            cout << "Da them sach thanh cong!\n";
        } else if (choice == 2) {
            int id;
            cout << "Nhap ID sach can xoa: ";
            cin >> id;
            auto it = find_if(books.begin(), books.end(), [id](Book &b) { return b.id == id; });
            if (it != books.end()) {
                books.erase(it);
                cout << "Da xoa sach thanh cong!\n";
            } else {
                cout << "Khong tim thay sach voi ID nay.\n";
            }
        } else if (choice == 3) {
            cout << "\nDanh sach sach trong thu vien:\n";
            for (auto &book : books) {
                book.display();
            }
        }
    } while (choice != 4);
}

// Ham quan ly nguoi dung
void manageUsers() {
    int choice;
    do {
        cout << "\n============================================" << endl;
        cout << "             QUAN LY NGUOI DUNG             " << endl;
        cout << "============================================" << endl;
        cout << "1. Them nguoi dung moi                      " << endl;
        cout << "2. Hien thi danh sach nguoi dung            " << endl;
        cout << "3. Quay lai menu chinh                      " << endl;
        cout << "============================================" << endl;
        cout << "Vui long nhap lua chon cua ban (1-3): ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Nhap ID nguoi dung: ";
            cin >> id;
            cin.ignore(); // Loai bo ky tu xuong dong
            cout << "Nhap ten nguoi dung: ";
            getline(cin, name);
            users.emplace_back(id, name);
            cout << "Da them nguoi dung thanh cong!\n";
        } else if (choice == 2) {
            cout << "\nDanh sach nguoi dung:\n";
            for (auto &user : users) {
                user.display();
            }
        }
    } while (choice != 3);
}

// Ham quan ly giao dich
void manageTransactions() {
    int choice;
    do {
        cout << "\n============================================" << endl;
        cout << "            QUAN LY GIAO DICH               " << endl;
        cout << "============================================" << endl;
        cout << "1. Muon sach                                " << endl;
        cout << "2. Hien thi lich su giao dich               " << endl;
        cout << "3. Quay lai menu chinh                      " << endl;
        cout << "============================================" << endl;
        cout << "Vui long nhap lua chon cua ban (1-3): ";
        cin >> choice;

        if (choice == 1) {
            int bookId, userId;
            string date;
            cout << "Nhap ID sach: ";
            cin >> bookId;
            cout << "Nhap ID nguoi dung: ";
            cin >> userId;
            cin.ignore(); // Loai bo ky tu xuong dong
            cout << "Nhap ngay muon (dd/mm/yyyy): ";
            getline(cin, date);

            auto bookIt = find_if(books.begin(), books.end(), [bookId](Book &b) { return b.id == bookId; });
            if (bookIt != books.end() && !bookIt->isBorrowed) {
                bookIt->isBorrowed = true;
                transactions.emplace_back(bookId, userId, date);
                cout << "Da ghi nhan giao dich muon sach!\n";
            } else {
                cout << "Sach khong kha dung hoac khong ton tai.\n";
            }
        } else if (choice == 2) {
            cout << "\nLich su giao dich:\n";
            for (auto &tran : transactions) {
                tran.display();
            }
        }
    } while (choice != 3);
}

// Ham chinh
int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            manageBooks();
            break;
        case 2:
            manageUsers();
            break;
        case 3:
            manageTransactions();
            break;
        case 4:
            cout << "Chuc nang tim kiem dang duoc phat trien.\n";
            break;
        case 5:
            cout << "Thoat chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long thu lai.\n";
        }
    } while (choice != 5);

    return 0;
}
