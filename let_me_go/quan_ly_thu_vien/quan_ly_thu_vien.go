package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Book struct {
	ID         int
	Author     string
	Title      string
	IsBorrowed bool
}

type User struct {
	ID   int
	Name string
}

type Transaction struct {
	BookID int
	UserID int
	Date   string
}

var books []Book
var users []User
var transactions []Transaction

func mainMenuDisplay() {
	fmt.Println("\nCHUONG TRINH QUAN LY THU VIEN 0.1\n")
	fmt.Println("1 - Quan ly sach")
	fmt.Println("2 - Quan ly nguoi dung")
	fmt.Println("3 - Quan ly muon tra")
	fmt.Println("4 - Thoat")
	fmt.Print("\nLua chon: ")
}

func manageBooks() {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println("\nQUAN LY SACH\n")
		fmt.Println("1 - Them sach")
		fmt.Println("2 - Xoa sach")
		fmt.Println("3 - Hien thi tat ca sach")
		fmt.Println("4 - Quay lai")
		fmt.Print("\nLua chon: ")
		choice, _ := strconv.Atoi(readInput(reader))

		if choice == 1 {
			fmt.Print("ID: ")
			id, _ := strconv.Atoi(readInput(reader))
			fmt.Print("Ten sach: ")
			title := readInput(reader)
			fmt.Print("Tac gia: ")
			author := readInput(reader)
			books = append(books, Book{ID: id, Title: title, Author: author})
			fmt.Println("\nDone")
		} else if choice == 2 {
			fmt.Print("ID sach can xoa: ")
			id, _ := strconv.Atoi(readInput(reader))
			found := false
			for i, book := range books {
				if book.ID == id {
					books = append(books[:i], books[i+1:]...)
					found = true
					break
				}
			}
			if found {
				fmt.Println("Done")
			} else {
				fmt.Println("Wrong ID")
			}
		} else if choice == 3 {
			fmt.Println("\nTAT CA SACH TRONG THU VIEN")
			for _, book := range books {
				status := "Available"
				if book.IsBorrowed {
					status = "Borrowed"
				}
				fmt.Printf("ID: %d, Author: %s, Title: %s, Status: %s\n", book.ID, book.Author, book.Title, status)
			}
		} else if choice == 4 {
			break
		}
	}
}

func manageUsers() {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println("\nQUAN LY NGUOI DUNG\n")
		fmt.Println("1 - Them nguoi dung")
		fmt.Println("2 - Xoa nguoi dung")
		fmt.Println("3 - Hien thi tat ca nguoi dung")
		fmt.Println("4 - Quay lai")
		fmt.Print("\nLua chon: ")
		choice, _ := strconv.Atoi(readInput(reader))

		if choice == 1 {
			fmt.Print("ID: ")
			id, _ := strconv.Atoi(readInput(reader))
			fmt.Print("Ten nguoi dung: ")
			name := readInput(reader)
			users = append(users, User{ID: id, Name: name})
			fmt.Println("\nDone")
		} else if choice == 2 {
			fmt.Print("ID nguoi can xoa: ")
			id, _ := strconv.Atoi(readInput(reader))
			found := false
			for i, user := range users {
				if user.ID == id {
					users = append(users[:i], users[i+1:]...)
					found = true
					break
				}
			}
			if found {
				fmt.Println("Done")
			} else {
				fmt.Println("Wrong ID")
			}
		} else if choice == 3 {
			fmt.Println("\nTAT CA NGUOI DUNG THU VIEN")
			for _, user := range users {
				fmt.Printf("ID: %d, Name: %s\n", user.ID, user.Name)
			}
		} else if choice == 4 {
			break
		}
	}
}

func manageTransaction() {
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Println("\nQUAN LY MUON TRA SACH\n")
		fmt.Println("1 - Muon sach")
		fmt.Println("2 - Tra sach")
		fmt.Println("3 - Hien thi tat ca sach dang duoc muon")
		fmt.Println("4 - Quay lai")
		fmt.Print("\nLua chon: ")
		choice, _ := strconv.Atoi(readInput(reader))

		if choice == 1 {
			fmt.Print("User ID: ")
			userID, _ := strconv.Atoi(readInput(reader))
			fmt.Print("Book ID: ")
			bookID, _ := strconv.Atoi(readInput(reader))
			fmt.Print("Ngay muon sach: ")
			date := readInput(reader)
			for i, book := range books {
				if book.ID == bookID {
					books[i].IsBorrowed = true
					transactions = append(transactions, Transaction{BookID: bookID, UserID: userID, Date: date})
					fmt.Println("\nDone")
					break
				}
			}
		} else if choice == 2 {
			fmt.Print("ID nguoi tra sach: ")
			userID, _ := strconv.Atoi(readInput(reader))
			fmt.Print("ID sach can tra: ")
			bookID, _ := strconv.Atoi(readInput(reader))
			found := false
			for i, transaction := range transactions {
				if transaction.UserID == userID && transaction.BookID == bookID {
					transactions = append(transactions[:i], transactions[i+1:]...)
					for j, book := range books {
						if book.ID == bookID {
							books[j].IsBorrowed = false
							fmt.Println("\nDone")
							found = true
							break
						}
					}
					break
				}
			}
			if !found {
				fmt.Println("Wrong ID")
			}
		} else if choice == 3 {
			fmt.Println("\nTAT CA SACH DANG DUOC MUON")
			for _, transaction := range transactions {
				fmt.Printf("Book ID: %d, User ID: %d, Borrow Date: %s\n", transaction.BookID, transaction.UserID, transaction.Date)
			}
		} else if choice == 4 {
			break
		}
	}
}

func readInput(reader *bufio.Reader) string {
	input, _ := reader.ReadString('\n')
	return strings.TrimSpace(input)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		mainMenuDisplay()
		choice, _ := strconv.Atoi(readInput(reader))
		if choice == 1 {
			manageBooks()
		} else if choice == 2 {
			manageUsers()
		} else if choice == 3 {
			manageTransaction()
		} else if choice == 4 {
			break
		}
	}
}
