#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string bookId;
    string title;
    string author;
    bool isAvailable;

public:
    Book(string id, string title, string author)
        : bookId(id), title(title), author(author), isAvailable(true) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool checkAvailability() { return isAvailable; }

    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }
};

class User {
private:
    string userId;
    string name;
    vector<Book*> borrowedBooks;

public:
    User(string id, string name) : userId(id), name(name) {}

    void borrowBook(Book* book) {
        borrowedBooks.push_back(book);
        book->borrowBook();
    }

    void returnBook(Book* book) {
        book->returnBook();
        // Tìm và xóa sách khỏi danh sách mượn
        borrowedBooks.erase(
            remove(borrowedBooks.begin(), borrowedBooks.end(), book),
            borrowedBooks.end()
        );
    }
};

class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayAvailableBooks() {
        for (const auto& book : books) {
            if (book.checkAvailability()) {
                cout << "Book Title: " << book.getTitle() << endl;
            }
        }
    }
};
