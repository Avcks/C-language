#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 100;

class LibItem
{
protected:
    string t; // title
    string a; // author
    string d; // dueDate

public:
    LibItem(const string &title, const string &author) 
        : t(title), a(author), d("Not checked out") {}

    virtual ~LibItem() {}

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;

    string getTitle() const { return t; }
    string getAuthor() const { return a; }
    string getDueDate() const { return d; }

    void setTitle(const string &newTitle) { t = newTitle; }
    void setAuthor(const string &newAuthor) { a = newAuthor; }
    void setDueDate(const string &newDueDate) { d = newDueDate; }
};

class Book : public LibItem 
{
private:
    string isbn; // ISBN
    int qty; // quantity

public:
    Book(const string &title, const string &author, const string &ISBN, int quantity)
        : LibItem(title, author), isbn(ISBN), qty(quantity)
    {
        if (qty < 0)
        {
            cout << "Error: Quantity cannot be negative. Setting to 0." << endl;
            this->qty = 0;
        }
        if (isbn.length() != 10 && isbn.length() != 13)
        {
            cout << "Warning: ISBN should be 10 or 13 characters long." << endl;
        }
    }

    void checkOut() 
    {
        if (qty > 0)
        {
            qty--;
            d = "Due in 14 days";
            cout << "Book checked out successfully." << endl;
        } 
        else
        {
            cout << "Error: No copies available for checkout." << endl;
        }
    }

    void returnItem()
    {
        qty++;
        d = "Returned";
        cout << "Book returned successfully." << endl;
    }

    void displayDetails() const override
    {
        cout << "Type: Book" << endl;
        cout << "Title: " << t << endl;
        cout << "Author: " << a << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Available Quantity: " << qty << endl;
        cout << "Status: " << d << endl;
    }

    string getISBN() const { return isbn; }
    int getQuantity() const { return qty; }
};

class DVD : public LibItem
{
private:
    int dur; // duration

public:
    DVD(const string& title, const string& author, int duration)
        : LibItem(title, author), dur(duration) {}

    void checkOut() override
    {
        if (d == "Not checked out")
        {
            d = "Due in 7 days";
            cout << "DVD checked out successfully." << endl;
        } 
        else
        {
            cout << "Error: DVD is already checked out." << endl;
        }
    }

    void returnItem() 
    {
        d = "Returned";
        cout << "DVD returned successfully." << endl;
    }

    void displayDetails() const 
    {
        cout << "Type: DVD" << endl;
        cout << "Title: " << t << endl;
        cout << "Director: " << a << endl;
        cout << "Duration: " << dur << " minutes" << endl;
        cout << "Status: " << d << endl;
    }

    int getDuration() const { return dur; }
};

class Magazine : public LibItem 
{
private:
    int issue; // issueNumber

public:
    Magazine(const string& title, const string& author, int issueNumber)
        : LibItem(title, author), issue(issueNumber) {}

    void checkOut()
    {
        if (d == "Not checked out") 
        {
            d = "Due in 3 days";
            cout << "Magazine checked out successfully." << endl;
        } 
        else
        {
            cout << "Error: Magazine is already checked out." << endl;
        }
    }

    void returnItem() override
    {
        d = "Returned";
        cout << "Magazine returned successfully." << endl;
    }

    void displayDetails() const override
    {
        cout << "Type: Magazine" << endl;
        cout << "Title: " << t << endl;
        cout << "Publisher: " << a << endl;
        cout << "Issue Number: " << issue << endl;
        cout << "Status: " << d << endl;
    }

    int getIssueNumber() const { return issue; }
};

class LMS 
{
private:
    LibItem* items[MAX_ITEMS];
    int count; // itemCount

public:
    LMS() : count(0)
    {
        for (int i = 0; i < MAX_ITEMS; i++) 
        {
            items[i] = nullptr;
        }
    }

    ~LMS()
    {
        for (int i = 0; i < count; i++) 
        {
            delete items[i];
        }
    }

    void addItem(LibItem* item) 
    {
        if (count < MAX_ITEMS)
        {
            items[count++] = item;
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
        if (count == 0) 
        {
            cout << "No items in the library." << endl;
            return;
        }

        cout << "\nLibrary Catalog:\n";
        for (int i = 0; i < count; i++)
        {
            items[i]->displayDetails();
            cout << "-----------------------" << endl;
        }
    }

    void checkOutItem(int index) 
    {
        if (index >= 0 && index < count)
        {
            items[index]->checkOut();
        } 
        else 
        {
            cout << "Error: Invalid item index." << endl;
        }
    }

    void returnItem(int index) 
    {
        if (index >= 0 && index < count)
        {
            items[index]->returnItem();
        } 
        else 
        {
            cout << "Error: Invalid item index." << endl;
        }
    }

    int getItemCount() const { return count; }
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

void addBook(LMS& lib)
{
    string title, author, isbn;
    int qty;

    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, isbn);
    cout << "Enter quantity: ";
    cin >> qty;
    cin.ignore();

    lib.addItem(new Book(title, author, isbn, qty));
}

void addDVD(LMS& lib)
{
    string title, author;
    int dur;

    cout << "Enter DVD title: ";
    getline(cin, title);
    cout << "Enter director: ";
    getline(cin, author);
    cout << "Enter duration (minutes): ";
    cin >> dur;
    cin.ignore(); 

    lib.addItem(new DVD(title, author, dur));
}

void addMagazine(LMS& lib)
{
    string title, author;
    int issue;

    cout << "Enter magazine title: ";
    getline(cin, title);
    cout << "Enter publisher: ";
    getline(cin, author);
    cout << "Enter issue number: ";
    cin >> issue;
    cin.ignore(); 

    lib.addItem(new Magazine(title, author, issue));
}

int main() 
{
    LMS lib;
    int choice = 0;
    int index;

    while (choice != 7)
    {
        displayMenu();
        cin >> choice;
        cin.ignore(); 

        switch (choice) 
        {
            case 1:
                addBook(lib);
                break;
            case 2:
                addDVD(lib);
                break;
            case 3:
                addMagazine(lib);
                break;
            case 4:
                lib.displayAllItems();
                break;
            case 5:
                if (lib.getItemCount() > 0) 
                {
                    cout << "Enter item index (0-" << lib.getItemCount() - 1 << "): ";
                    cin >> index;
                    cin.ignore();
                    lib.checkOutItem(index);
                } 
                else 
                {
                    cout << "No items available for checkout." << endl;
                }
                break;
            case 6:
                if (lib.getItemCount() > 0) 
                {
                    cout << "Enter item index (0-" << lib.getItemCount() - 1 << "): ";
                    cin >> index;
                    cin.ignore();
                    lib.returnItem(index);
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
    }
}
