class Book:
    def __init__(self, book_id, title, author):
        self.id = book_id
        self.title = title
        self.author = author
        self.is_borrowed = False

    def display(self):
        status = "Borrowed" if self.is_borrowed else "Available"
        print(f"ID: {self.id}, Title: {self.title}, Author: {self.author}, Status: {status}")

class User:
    def __init__(self, name, user_id):
        self.id = user_id
        self.name = name

    def display(self):
        print(f"ID: {self.id}, Name: {self.name}")

class Transaction:
    def __init__(self, book_id, user_id, date):
        self.book_id = book_id
        self.user_id = user_id
        self.date = date

    def display(self):
        print(f"User ID: {self.user_id}, Book ID: {self.book_id}, Date: {self.date}")

books = []
users = []
transactions = []

def main_menu():
    print("\nCHUONG TRINH QUAN LY THU VIEN 0.2\n")
    print("1 - Quan ly sach")
    print("2 - Quan ly nguoi dung")
    print("3 - Quan ly giao dich")
    print("4 - Thoat")

    return int(input("\nLua chon: "))

def manage_books():
    while True:    
        print("\nQUAN LY SACH")
        print("1 - Them sach")
        print("2 - Xoa sach")
        print("3 - Hien thi tat ca sach")
        print("4 - Quay lai")
        choice = int(input("\nLua chon: "))

        if choice == 1:
            book_id = int(input("ID sach can them: "))
            title = input("Ten sach: ")
            author = input("Tac gia: ")
            books.append(Book(book_id, title, author))
            print("\nThanh cong\n")
        elif choice == 2:
            book_id = int(input("ID sach can xoa: "))
            for book in books:
                if book.id == book_id:
                    books.remove(book)
                    print("\nThanh cong\n")
                    break

        elif choice == 3:
            print("TAT CA SACH TRONG THU VIEN")
            for book in books:
                book.display()
        
        elif choice == 4:
            break

def manage_users():
    while True:    
        print("\nQUAN LY NGUOI DUNG")
        print("1 - Them nguoi dung")
        print("2 - Xoa nguoi dung")
        print("3 - Hien thi tat ca nguoi dung")
        print("4 - Quay lai")
        choice = int(input("\nLua chon: "))

        if choice == 1:
            user_id = int(input("ID nguoi dung: "))
            name = input("Ten nguoi dung: ")
            users.append(User(name, user_id))
            print("\nThanh cong\n")
        elif choice == 2:
            user_id = int(input("ID nguoi can xoa: "))
            for user in users:
                if user.user_id == user_id:
                    users.remove(user)
                    print("\nThanh cong\n")
                    break

        elif choice == 3:
            print("TAT CA SACH TRONG THU VIEN")
            for user in users:
                user.display()
        
        elif choice == 4:
            break 

def manage_transactions():
    while True:    
        print("\nQUAN LY GIAO DICH")
        print("1 - Muon sach")
        print("2 - Tra sach")
        print("3 - Hien thi lich su muon sach")
        print("4 - Quay lai")
        choice = int(input("\nLua chon: "))

        if choice == 1:
            user_id = int(input("ID nguoi muon sach: "))
            book_id = int(input("ID sach: "))
            date = input("Ngay muon sach: ")
            transactions.append(Transaction(book_id, user_id, date))
            for book in books:
                if book.id == book_id:
                    book.is_borrowed = True
            print("\nThanh cong\n")
        elif choice == 2:
            book_id = int(input("ID sach can tra: "))
            user_id = int(input("ID nguoi can tra sach: "))
            for transaction in transactions:
                if transaction.user_id == user_id and transaction.book_id == book_id:
                    transactions.remove(transaction)
                    for book in books:
                        if book.id == book_id:
                            book.is_borrowed = False
                            print("\nThanh cong\n")
                            break

        elif choice == 3:
            print("TAT CA SACH DANG DUOC MUON")
            for transaction in transactions:
                transaction.display()
        
        elif choice == 4:
            break


def main():
    while True:
        choice = main_menu()
        if choice == 1:
            manage_books()
        elif choice == 2:
            manage_users()
        elif choice == 3:
            manage_transactions()
        elif choice == 4:
            break


if __name__ == "__main__":
    main()