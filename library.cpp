#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Book class
class Book {
private:
    string title;
    string author;
    int id;
    bool available;

public:
    Book(string title, string author, int id) : title(title), author(author), id(id), available(true) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getID() const { return id; }
    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }
};

// Library class
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        auto it = find_if(books.begin(), books.end(), [id](const Book& b) { return b.getID() == id; });
        if (it != books.end()) {
            books.erase(it);
            cout << "Book with ID " << id << " removed successfully." << endl;
        } else {
            cout << "Book with ID " << id << " not found." << endl;
        }
    }

    void displayBooks() {
        cout << "Library Catalog:" << endl;
        for (const auto& book : books) {
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ID: " << book.getID();
            if (book.isAvailable()) {
                cout << " (Available)" << endl;
            } else {
                cout << " (Not Available)" << endl;
            }
        }
    }

    Book* findBook(int id) {
        auto it = find_if(books.begin(), books.end(), [id](const Book& b) { return b.getID() == id; });
        if (it != books.end()) {
            return &(*it);
        } else {
            return nullptr;
        }
    }
};

int main() {
    Library library;

    // Adding books to the library
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 101));
    library.addBook(Book("1984", "George Orwell", 102));
    library.addBook(Book("Pride and Prejudice", "Jane Austen", 103));

    // Displaying books in the library
    library.displayBooks();

    // Removing a book
    library.removeBook(102);

    // Displaying updated catalog
    library.displayBooks();

    return 0;
}