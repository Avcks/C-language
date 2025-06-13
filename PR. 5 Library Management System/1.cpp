#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;
class LibraryItem
{
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(const string &title, const string &author)
        : title(title), author(author), dueDate("Not checked out") {}

    virtual ~LibraryItem() {}

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getDueDate() const { return dueDate; }

    void setTitle(const string &newTitle) { title = newTitle; }
    void setAuthor(const string &newAuthor) { author = newAuthor; }
    void setDueDate(const string &newDueDate) { dueDate = newDueDate; }
};

class Book : public LibraryItem
{
private:
    string ISBN;
    int quantity;

public:
    Book(const string &title, const string &author, const string &ISBN, int quantity)
        : LibraryItem(title, author), ISBN(ISBN), quantity(quantity)
    {
        if (quantity < 0)
        {
            cout << "Error: Quantity cannot be negative. Setting to 0." << endl;
            this->quantity = 0;
        }
        if (ISBN.length() != 10 && ISBN.length() != 13)
        {
            cout << "Warning: ISBN should be 10 or 13 characters long." << endl;
        }
    }

    void checkOut()
    {
        if (quantity > 0)
        {
            quantity--;
            dueDate = "Due in 14 days";
            cout << "Book checked out successfully." << endl;
        }
        else
        {
            cout << "Error: No copies available for checkout." << endl;
        }
    }

    void returnItem()
    {
        quantity++;
        dueDate = "Returned";
        cout << "Book returned successfully." << endl;
    }

    void displayDetails() const override
    {
        cout << "Type: Book" << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Available Quantity: " << quantity << endl;
        cout << "Status: " << dueDate << endl;
    }

    string getISBN() const { return ISBN; }
    int getQuantity() const { return quantity; }
};

class DVD : public LibraryItem
{
private:
    int duration;

public:
    DVD(const string &title, const string &author, int duration)
        : LibraryItem(title, author), duration(duration) {}

    void checkOut() override
    {
        if (dueDate == "Not checked out")
        {
            dueDate = "Due in 7 days";
            cout << "DVD checked out successfully." << endl;
        }
        else
        {
            cout << "Error: DVD is already checked out." << endl;
        }
    }

    void returnItem()
    {
        dueDate = "Returned";
        cout << "DVD returned successfully." << endl;
    }

    void displayDetails() const
    {
        cout << "Type: DVD" << endl;
        cout << "Title: " << title << endl;
        cout << "Director: " << author << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Status: " << dueDate << endl;
    }

    int getDuration() const { return duration; }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(const string &title, const string &author, int issueNumber)
        : LibraryItem(title, author), issueNumber(issueNumber) {}

    void checkOut()
    {
        if (dueDate == "Not checked out")
        {
            dueDate = "Due in 3 days";
            cout << "Magazine checked out successfully." << endl;
        }
        else
        {
            cout << "Error: Magazine is already checked out." << endl;
        }
    }

    void returnItem() override
    {
        dueDate = "Returned";
        cout << "Magazine returned successfully." << endl;
    }

    void displayDetails() const override
    {
        cout << "Type: Magazine" << endl;
        cout << "Title: " << title << endl;
        cout << "Publisher: " << author << endl;
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Status: " << dueDate << endl;
    }

    int getIssueNumber() const { return issueNumber; }
};

class LMS
{
private:
    LibraryItem *items[MAX_ITEMS];
    int itemCount;

public:
    LMS() : itemCount(0)
    {
        for (int i = 0; i < MAX_ITEMS; i++)
        {
            items[i] = nullptr;
        }
    }

    ~LMS()
    {
        for (int i = 0; i < itemCount; i++)
        {
            delete items[i];
        }
    }

    void addItem(LibraryItem *item)
    {
        if (itemCount < MAX_ITEMS)
        {
            items[itemCount++] = item;
            cout << "Item added successfully." << endl;
        }
        else
        {
            cout << "Error: Library catalog is full." << endl;
            delete item;
        }
    }

    void displayAllItems() const
    {
        if (itemCount == 0)
        {
            cout << "No items in the library." << endl;
            return;
        }

        cout << "\nLibrary Catalog:\n";
        for (int i = 0; i < itemCount; i++)
        {
            items[i]->displayDetails();
            cout << "-----------------------" << endl;
        }
    }

    void checkOutItem(int n)
    {
        if (n >= 0 && n < itemCount)
        {
            items[n]->checkOut();
        }
        else
        {
            cout << "Error: Invalid item index." << endl;
        }
    }

    void returnItem(int n)
    {
        if (n >= 0 && n < itemCount)
        {
            items[n]->returnItem();
        }
        else
        {
            cout << "Error: Invalid item index." << endl;
        }
    }

    int getItemCount() const { return itemCount; }
};

void displayMenu()
{
    cout << "\nLibrary Management System\n";
    cout << "1. Add Book\n";
    cout << "2. Add DVD\n";
    cout << "3. Add Magazine\n";
    cout << "4. Display All Items\n";
    cout << "5. Check Out Item\n";
    cout << "6. Return Item\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void addBook(LMS &library)
{
    string title, author, ISBN;
    int quantity;
    string dummy;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);
    cout << "Enter quantity: ";
    cin >> quantity;
    getline(cin, dummy);

    library.addItem(new Book(title, author, ISBN, quantity));
}

void addDVD(LMS &library)
{
    string title, author;
    int duration;
    string dummy;

    cout << "Enter DVD title: ";
    getline(cin, title);
    cout << "Enter director: ";
    getline(cin, author);
    cout << "Enter duration (minutes): ";
    cin >> duration;
    getline(cin, dummy);

    library.addItem(new DVD(title, author, duration));
}

void addMagazine(LMS &library)
{
    string title, author;
    int issueNumber;
    string dummy;

    cout << "Enter magazine title: ";
    getline(cin, title);
    cout << "Enter publisher: ";
    getline(cin, author);
    cout << "Enter issue number: ";
    cin >> issueNumber;
    getline(cin, dummy);

    library.addItem(new Magazine(title, author, issueNumber));
}

int main()
{
    LMS library;
    int choice = 0;
    int n;
    string dummy;

    while (choice != 7)
    {
        displayMenu();
        cin >> choice;
        getline(cin, dummy);

        switch (choice)
        {
        case 1:
            addBook(library);
            break;
        case 2:
            addDVD(library);
            break;
        case 3:
            addMagazine(library);
            break;
        case 4:
            library.displayAllItems();
            break;
        case 5:
            if (library.getItemCount() > 0)
            {
                cout << "Enter item index (0-" << library.getItemCount() - 1 << "): ";
                cin >> n;
                getline(cin, dummy);
                library.checkOutItem(n);
            }
            else
            {
                cout << "No items available for checkout." << endl;
            }
            break;
        case 6:
            if (library.getItemCount() > 0)
            {
                cout << "Enter item index (0-" << library.getItemCount() - 1 << "): ";
                cin >> n;
                getline(cin, dummy);
                library.returnItem(n);
            }
            else
            {
                cout << "No items available to return." << endl;
            }
            break;
        case 7:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    };
}


/*

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 1
Enter book title: as
Enter author: avc
Enter ISBN: 1234567890
Enter quantity: 12
Item added successfully.

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 2
Enter DVD title: asd
Enter director: qwer
Enter duration (minutes): 12
Item added successfully.

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 3
Enter magazine title: asdf
Enter publisher: qwery
Enter issue number: 1234
Item added successfully.

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 4

Library Catalog:
Type: Book
Title: as
Author: avc
ISBN: 1234567890
Available Quantity: 12
Status: Not checked out
-----------------------
Type: DVD
Title: asd
Director: qwer
Duration: 12 minutes
Status: Not checked out
-----------------------
Type: Magazine
Title: asdf
Publisher: qwery
Issue Number: 1234
Status: Not checked out
-----------------------

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 5
Enter item index (0-2): 2
Magazine checked out successfully.

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 6
Enter item index (0-2): 2
Magazine returned successfully.

Library Management System
1. Add Book
2. Add DVD
3. Add Magazine
4. Display All Items
5. Check Out Item
6. Return Item
7. Exit
Enter your choice: 7
Exiting program.
*/