#include <iostream>
#include <string>

class InvalidInputException : public std::exception {
public:
    InvalidInputException(const std::string& message) : message_(message) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

class LibraryItem {
private:
    std::string title;
    std::string author;
    std::string dueDate;

public:
    LibraryItem(const std::string& title, const std::string& author) : title(title), author(author), dueDate("") {}

    virtual ~LibraryItem() {}

    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    std::string getDueDate() const { return dueDate; }

    void setTitle(const std::string& newTitle) { title = newTitle; }
    void setAuthor(const std::string& newAuthor) { author = newAuthor; }
    void setDueDate(const std::string& newDueDate) { dueDate = newDueDate; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    virtual std::string getItemType() const = 0;
};

class Book : public LibraryItem {
private:
    std::string isbn;
    int numPages;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn, int numPages)
        : LibraryItem(title, author), isbn(isbn) {
        if (numPages <= 0) {
            throw InvalidInputException("Number of pages must be positive.");
        }
        this->numPages = numPages;
    }

    void checkOut() override {
        if (getDueDate().empty()) {
            std::cout << "Checking out book: " << getTitle() << std::endl;
            setDueDate("2024-12-31");
            std::cout << "Due date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Book is already checked out. Due date: " << getDueDate() << std::endl;
        }
    }

    void returnItem() override {
        std::cout << "Returning book: " << getTitle() << std::endl;
        setDueDate("");
    }

    void displayDetails() const override {
        std::cout << "Type: Book" << std::endl;
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "ISBN: " << isbn << std::endl;
        std::cout << "Number of Pages: " << numPages << std::endl;
        if (!getDueDate().empty()) {
            std::cout << "Due Date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Not checked out." << std::endl;
        }
    }

    std::string getItemType() const override {
        return "Book";
    }
};

class DVD : public LibraryItem {
private:
    int duration;

public:
    DVD(const std::string& title, const std::string& author, int duration)
        : LibraryItem(title, author) {
        if (duration <= 0) {
            throw InvalidInputException("Duration must be positive.");
        }
        this->duration = duration;
    }

    void checkOut() override {
        if (getDueDate().empty()) {
            std::cout << "Checking out DVD: " << getTitle() << std::endl;
            setDueDate("2024-12-25");
            std::cout << "Due date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "DVD is already checked out. Due date: " << getDueDate() << std::endl;
        }
    }

    void returnItem() override {
        std::cout << "Returning DVD: " << getTitle() << std::endl;
        setDueDate("");
    }

    void displayDetails() const override {
        std::cout << "Type: DVD" << std::endl;
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "Duration: " << duration << " minutes" << std::endl;
        if (!getDueDate().empty()) {
            std::cout << "Due Date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Not checked out." << std::endl;
        }
    }

    std::string getItemType() const override {
        return "DVD";
    }
};

class Magazine : public LibraryItem {
private:
    int issueNumber;

public:
    Magazine(const std::string& title, const std::string& author, int issueNumber)
        : LibraryItem(title, author) {
        if (issueNumber <= 0) {
            throw InvalidInputException("Issue number must be positive.");
        }
        this->issueNumber = issueNumber;
    }

    void checkOut() override {
        if (getDueDate().empty()) {
            std::cout << "Checking out Magazine: " << getTitle() << std::endl;
            setDueDate("2024-12-20"); // Example due date
            std::cout << "Due date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Magazine is already checked out. Due date: " << getDueDate() << std::endl;
        }
    }

    void returnItem() override {
        std::cout << "Returning Magazine: " << getTitle() << std::endl;
        setDueDate("");
    }

    void displayDetails() const override {
        std::cout << "Type: Magazine" << std::endl;
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "Issue Number: " << issueNumber << std::endl;
        if (!getDueDate().empty()) {
            std::cout << "Due Date: " << getDueDate() << std::endl;
        }
        else {
            std::cout << "Not checked out." << std::endl;
        }
    }

    std::string getItemType() const override {
        return "Magazine";
    }
};


void displayMenu() {
    std::cout << "\nLibrary Management System Menu:" << std::endl;
    std::cout << "1. Add Item" << std::endl;
    std::cout << "2. Search Item" << std::endl;
    std::cout << "3. Check Out Item" << std::endl;
    std::cout << "4. Return Item" << std::endl;
    std::cout << "5. Display All Items" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
} 

LibraryItem* addItem() {
    int itemType;
    std::string title, author, isbn;
    int numPages, duration, issueNumber;

    std::cout << "\nAdd Item Menu:" << std::endl;
    std::cout << "1. Book" << std::endl;
    std::cout << "2. DVD" << std::endl;
    std::cout << "3. Magazine" << std::endl;
    std::cout << "Enter item type: ";
    std::cin >> itemType;
    std::cin.ignore(1000, '\n');

    std::cout << "Enter title: ";
    std::getline(std::cin, title);
    std::cout << "Enter author: ";
    std::getline(std::cin, author);

    try {
        switch (itemType) {
        case 1:
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter number of pages: ";
            std::cin >> numPages;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw InvalidInputException("Invalid input for number of pages. Please enter a number.");
            }
            std::cin.ignore(1000, '\n');
            return new Book(title, author, isbn, numPages);
        case 2:
            std::cout << "Enter duration (minutes): ";
            std::cin >> duration;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw InvalidInputException("Invalid input for duration. Please enter a number.");
            }
            std::cin.ignore(1000, '\n');
            return new DVD(title, author, duration);
        case 3:
            std::cout << "Enter issue number: ";
            std::cin >> issueNumber;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                throw InvalidInputException("Invalid input for issue number. Please enter a number.");
            }
            std::cin.ignore(1000, '\n');
            return new Magazine(title, author, issueNumber);
        default:
            std::cout << "Invalid item type." << std::endl;
            return nullptr;
        }
    }
    catch (const InvalidInputException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return nullptr;
    }
    catch (const std::exception& e) {
        std::cerr << "General exception caught: " << e.what() << std::endl;
        return nullptr;
    }
    catch (...) {
        std::cerr << "Unknown exception caught!" << std::endl;
        return nullptr;
    }
}

LibraryItem* searchItem(LibraryItem** catalog, int size, const std::string& title) {
    for (int i = 0; i < size; ++i) {
        if (catalog[i] != nullptr && catalog[i]->getTitle() == title) {
            return catalog[i];
        }
    }
    return nullptr;
}

int main() {
    const int MAX_ITEMS = 100;
    LibraryItem* libraryCatalog[MAX_ITEMS] = { nullptr };
    int itemCount = 0;

    int choice;
    std::string searchTitle;
    LibraryItem* foundItem = nullptr;

    do {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(1000, '\n');

        switch (choice) {
        case 1: {
            if (itemCount < MAX_ITEMS) {
                LibraryItem* newItem = addItem();
                if (newItem != nullptr) {
                    libraryCatalog[itemCount] = newItem;
                    itemCount++;
                    std::cout << "Item added successfully." << std::endl;
                }
                else {
                    std::cout << "Failed to add item." << std::endl;
                }
            }
            else {
                std::cout << "Catalog is full. Cannot add more items." << std::endl;
            }
            break;
        }
        case 2:
            std::cout << "Enter title to search: ";
            std::getline(std::cin, searchTitle);
            foundItem = searchItem(libraryCatalog, itemCount, searchTitle);
            if (foundItem != nullptr) {
                std::cout << "Item found:" << std::endl;
                foundItem->displayDetails();
            }
            else {
                std::cout << "Item not found." << std::endl;
            }
            break;
        case 3:
            std::cout << "Enter title to check out: ";
            std::getline(std::cin, searchTitle);
            foundItem = searchItem(libraryCatalog, itemCount, searchTitle);
            if (foundItem != nullptr) {
                foundItem->checkOut();
            }
            else {
                std::cout << "Item not found." << std::endl;
            }
            break;
        case 4:
            std::cout << "Enter title to return: ";
            std::getline(std::cin, searchTitle);
            foundItem = searchItem(libraryCatalog, itemCount, searchTitle);
            if (foundItem != nullptr) {
                foundItem->returnItem();
            }
            else {
                std::cout << "Item not found." << std::endl;
            }
            break;
        case 5:
            std::cout << "\n--- Library Catalog ---" << std::endl;
            if (itemCount == 0) {
                std::cout << "Catalog is empty." << std::endl;
            }
            else {
                for (int i = 0; i < itemCount; ++i) {
                    libraryCatalog[i]->displayDetails();
                    std::cout << "-----------------------" << std::endl;
                }
            }
            break;
        case 6: // Exit
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 6);

    for (int i = 0; i < itemCount; ++i) {
        delete libraryCatalog[i];
    }

}
