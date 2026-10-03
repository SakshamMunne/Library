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
    vector<int> issueBooksId;

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
    void issueBooks()
    {
        cout << "Issue Books...\n";
    }
    void returnBooks()
    {
        cout << "Return Books...\n";
    }
    void viewHeldBooks()
    {
        cout << "View Held Books...\n";
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
        cout<<"User ID not found. Enter your name to register: ";
        getline(cin,name);
        users.push_back(User(userId,name));
        cout<<"Registration successful!\n";
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
            if (u.issueBooksId.empty())
            {
                cout << "None";
            }
            else
            {
                for (int bId : u.issueBooksId)
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
                    sys.issueBooks();
                    break;
                case 3:
                    sys.returnBooks();
                    break;
                case 4:
                    sys.viewHeldBooks();
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