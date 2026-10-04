#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Book
{

public:
    int id;
    string title;
    bool isIssued;

    Book(int bookId, string bookTitle)
    {
        id = bookId;
        title = bookTitle;
        isIssued = false;
    }
};

class User
{
public:
    int id;
    string name;
    vector<int> issuedBookIds;

    User(int userId, string userName)
    {
        id = userId;
        name = userName;
    }
};

class LibrarySystem
{

private:
    vector<Book> books;
    vector<User> users;
    // string adminEmail = "admin123@gmail.com";
    // string adminPassword = "admin@123";

public:
    LibrarySystem()
    {
        books.push_back(Book(101, "C++ Programming"));
        books.push_back(Book(102, "Data Structure and Algorithm"));
        books.push_back(Book(103, "Database Management"));
    }
    // bool adminLogin=false;

    void displayAllBooks()
    {
        // cout<<"Displaying All Books...\n";
        cout << "\n------ BOOK CATALOG -----\n";
        if (books.empty())
        {
            cout << "No books currently in system.\n";
            return;
        }

        for (const auto &b : books)
        {
            cout << "ID : " << b.id << " | Title : " << b.title << " | Status : " << (b.isIssued ? "Issued" : "Available") << endl;
        }
    }

    void issueBooks(User &user)
    {
        displayAllBooks();
        cout << "Issue Books...\n";
        int bookId;

        int count;
        cout<<"How many books do you want to issue? ";
        cin>>count;
        if(count<=0)
        {
            cout<<"Invalid count!\n";
            return;

        }
        int issuedCount = 0;
        for(int i=0;i<count;i++)
        {
            cout<<"Enter the book ID "<<i+1<<": ";
            cin>>bookId;
            bool found=false;
            for(auto &b:books)
            {
                if(b.id==bookId)
                {
                    found=true;
                    if(!b.isIssued)
                    {
                        b.isIssued=true;
                        user.issuedBookIds.push_back(b.id);
                        issuedCount++;
                    }
                    else
                    {
                        cout<<"Book is already issued!\n";
                    }
                }
            }
            if(!found)
            {
                cout<<"Book with ID "<<bookId<<" not found!\n";
            }
        }

        cout<<"Enter number of days to issue the book (Max 14 Days):";
        int days;
        cin>>days;
        if (days<=0 || days>14)
        {
            cout<<"Invalid number of days. Please enter a value between 1 and 14.\n";
            return;
        }
         if (issuedCount > 0)
        {
            cout << issuedCount << " Books issued successfully for " << days << " days.\n";
        }
        else
        {
            cout << "No books were issued.\n";
        }

        

    }

    void returnBooks(User &user) {
        if (user.issuedBookIds.empty()) {
            cout << "You have no books currently issued!\n";
            return;
        }

        int days;
        cout << "Enter the total days you kept the books: ";
        cin >> days;

        int finePerBook = 0;
        if (days > 14) {
            finePerBook = (days - 14) * 5; // Fine rate: Rs. 5 per day past 14 days
            cout << "Overdue by " << (days - 14) << " days. Fine per overdue book: Rs. " << finePerBook << endl;
        }

        int count;
        cout << "How many books do you want to return? ";
        cin >> count;

        int totalFine = 0;
        for (int i = 0; i < count; i++) {
            int bookId;
            cout << "Enter Book ID to return (" << i + 1 << "/" << count << "): ";
            cin >> bookId;

            // Find book in user's list
            auto it = find(user.issuedBookIds.begin(), user.issuedBookIds.end(), bookId);
            if (it != user.issuedBookIds.end()) {
                user.issuedBookIds.erase(it);

                // Mark book as available in library
                for (auto &b : books) {
                    if (b.id == bookId) {
                        b.isIssued = false;
                        break;
                    }
                }
                totalFine += finePerBook;
                cout << "Book ID " << bookId << " returned successfully!\n";
            } else {
                    cout << "You do not have Book ID " << bookId << " issued under your account!\n";
            }
        }

        if (totalFine > 0) {
            cout << "\nTotal fine payable: Rs. " << totalFine << endl;
        } else {
            cout << "No fine incurred. Thank you for returning on time!\n";
        }
    }

    void viewHeldBooks(const User &user) {
        cout << "\n--- Books Currently Held by " << user.name << " ---\n";
        if (user.issuedBookIds.empty()) {
            cout << "You have no issued books.\n";
            return;
        }
        for (int bId : user.issuedBookIds) {
            for (const auto &b : books) {
                if (b.id == bId) {
                    cout << "Book ID: " << b.id << " | Title: " << b.title << endl;
                }
            }
        }
    }

    void addBook()
    {
        // cout<<"Adding Book...\n";
        int id;
        string title;
        cout << "Enter New Book ID :";
        cin >> id;

        for (const auto &b : books)
        {
            if (b.id == id)
            {
                cout << "Error : Book ID already exists!\n";
                return;
            }
        }
        cin.ignore();
        cout << "Enter Book Title : ";
        getline(cin, title);

        books.push_back(Book(id, title));
        cout << "Book added sucessfully!!!\n";
    }

    User* getOrRegisterUser()
    {
        int userId;
        cout << "Enter your User Id : ";
        cin >> userId;

        for(auto &u:users){
            if(u.id==userId){
                cout<<"Welcome back, "<<u.name<<"!\n";
                return &u;
            }
        }

        string name;
        cin.ignore();
        cout<<"User ID not found. Please Register first!"<<endl;
        cout<<"Your User Id is : "<<userId<<endl;
        cout<<"Enter your name to register: ";
        getline(cin,name);
        users.push_back(User(userId,name));
        cout<<"Registration successful!\n";
        cout<<"Welcome, "<<name<<"!\n";
        return &users.back();

    }

    void displayAllUsers()
    {
        // cout<<"Display All Users...\n";
        cout << "\n ----- USER RECORD ----- \n";
        if (users.empty())
        {
            cout << "No registration users yet. \n";
            return;
        }
        for (const auto &u : users)
        {
            cout << " User ID : " << u.id << " | Name : " << u.name << endl;
            cout << "Issued Book IDs : ";
            if (u.issuedBookIds.empty())
            {
                cout << "None";
            }
            else
            {
                for (int bId : u.issuedBookIds)
                {
                    cout << bId << " ";
                }
            }
            cout << endl;
        }
    }

    // bool adminLogin()
    // {
    //     string email, password;
    //     cout << "\n --- ADMIN LOGIN --- \n";
    //     cout << "Enter Admin Email : ";
    //     cin >> email;
    //     cout << "Enter Admin Password : ";
    //     cin >> password;

    //     if (email == adminEmail && password == adminPassword)
    //     {
    //         cout << "Login Successfull\n";
    //         return true;
    //     }
    //     else
    //     {
    //         cout << "Invalid Email or Password\n";
    //         return false;
    //     }
    // }
};

int main()
{
    LibrarySystem sys;

    int mainChoice;

    do
    {
        cout << " \n =============================== \n";
        cout << "     LIBRARY MANAGEMENT SYSTEM     \n";
        cout << "====================================\n";
        cout << "1. User Portal\n";
        cout << "2. View all Users\n";
        cout << "3. Exit\n";
        cout << "Enter Your Choice : ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
        {
            User* user = sys.getOrRegisterUser();
            int userChoice;
            do
            {
                cout << "\n---User Menu ---\n";
                cout << "1. View Available Books\n";
                cout << "2. Issue Books\n";
                cout << "3. Return Books\n";
                cout << "4. View My Held Books\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter your choice : ";
                cin >> userChoice;

                switch (userChoice)
                {
                case 1:
                    sys.displayAllBooks();
                    break;
                case 2:
                    sys.issueBooks(*user);
                    break;
                case 3:
                    sys.returnBooks(*user);
                    break;
                case 4:
                    sys.viewHeldBooks(*user);
                    break;
                case 5:
                    cout << " Logging out of User Portal...\n";
                    break;
                default:
                    cout << "Invalid Choice!!! \n";
                }
            } while (userChoice != 5);
            break;
        }
        case 2:
        {
            sys.displayAllUsers();
            break;
        }

        case 3:
        {
            cout << "Exiting system. Goodbye!\n";
            break;
        }
        default:
            cout << "Invalid Choice!\n";
        }
    } while (mainChoice != 3);
    return 0;
}