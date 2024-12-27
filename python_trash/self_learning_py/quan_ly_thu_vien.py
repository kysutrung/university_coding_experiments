class Book:
    def __init__ (self, book_id, title, author):
        self.id = book_id
        self.title = title
        self.author = author
        self.is_borrowed = False

    def display(self):
        status = "Borrowed" if self.is_borrowed else "Available"
        print(f"ID: {self.id}, Author: {self.author}, Title: {self.title}, Status: {status}")

class User:
    def __init__ (self, user_id, name):
        self.id = user_id
        self.name = name

    def display(self):
        print(f"Book ID: {self.id}, Name: {self.name}")

class Transaction:
    def __init__ (self, book_id, user_id, date):
        self.book_id = book_id
        self.user_id = user_id
        self.date = date
    
    def display(self):
        print(f"Book ID: {self.book_id}, User ID: {self.user_id}, Ngay muon: {self.date}")

books = []
users = []
transactions = []

def main_menu_display():
    print("\nCHUONG TRINH QUAN LY THU VIEN 0.2\n")
    print("1 - Quan ly sach")
    print("2 - Quan ly nguoi dung")
    print("3 - Quan ly muon tra sach")
    print("4 - Tro ve\n")
    print("Lua chon: ")

def manageBooks():
    while True:
        print("\nQUAN LY SACH\n")
        print("1 - Them sach")
        print("2 - Xoa sach")
        print("3 - Xem toan bo sach")
        print("4 - Tro ve")

        choice = int(input("\nLuu chon: "))

        if choice == 1:
            book_id = int(input("ID: "))
            title = input("Ten sach: ")
            author = input("Tac gia: ")
            books.append(Book(book_id, title, author))
            print("\nXong")
        else choice == 2;
            for book_id == book_id:
                if book.in = int(input(ID sach can xoa))
        



def main():
    manageBooks()
if __name__ == "__main__":
    main();