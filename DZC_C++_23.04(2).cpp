#include <iostream>
using namespace std;
#include <cstring>

struct Book{
    char* Author = new char[30]{};
    char* Name = new char[30]{};
    char* Genre = new char[30]{};


void printOne(Book *books){

    cout << "Author:\t" << Author << endl
    << "Name:\t" << Name << endl
    << "Genre:\t" << Genre << endl;
    cout << endl;
}

void Editor(){

    getchar();
    cout << "Enter new author, name and genre of book: " << endl;

    cout << "Author: ";
    cin.getline(Author,30);

    cout << "Name: ";
    cin.getline(Name, 30);

    cout << "Genre: ";
    cin.getline(Genre, 30);

    cout << "New book successfully created!" << endl;
}

    void print(Book* books){

        for (int i = 0; i < 10; i++) {

            cout << "Book #" << i + 1 << endl;
            books[i].printOne(books);

        }
    }

    void findAuthor(Book* books)
    {
        char* authorFind = new char[30];
        int countLen{};
        cout << "Enter author to search: " << endl;
        cin.getline(authorFind, 30);

        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < strlen(authorFind); i++) {
                if (authorFind[i] == Author[i])
                    countLen++;
            }
            if(countLen == strlen(authorFind))
            {
                books[j].printOne(books);
            }
        }
    }

    void findName(Book* books) {

        char* nameFind = new char[30];
        int countLen{};
        cout << "Enter name to search: " << endl;
        cin.getline(nameFind, 30);

        for (int j = 0; j < 10; j++) {
            for (int i = 0; i < strlen(nameFind); i++) {
                if (nameFind[i] == Name[i])
                    countLen++;
            }
            if(countLen == strlen(nameFind))
            {
                books[j].printOne(books);
            }
        }
    }

    void sortName(){



    }


    void sortGenres(){



    }



};

int main() {

const int count = 10;
int choice{};

Book *books = new Book[count];


books[0].Author = new char[30]{"Remark"};
books[0].Name = new char[30]{"Na zapadnom fronte"};
books[0].Genre = new char[30]{"Roman"};

books[1].Author = new char[30]{"Osten"};
books[1].Name = new char[30]{"Emma"};
books[1].Genre = new char[30]{"Thriller"};

books[2].Author = new char[30]{"Dojl"};
books[2].Name = new char[30]{"Znak chetireh"};
books[2].Genre = new char[30]{"Action"};

books[3].Author = new char[30]{"Stocker"};
books[3].Name = new char[30]{"Dracula"};
books[3].Genre = new char[30]{"Thriller"};

books[4].Author = new char[30]{"Kippling"};
books[4].Name = new char[30]{"Kim"};
books[4].Genre = new char[30]{"Roman"};

books[5].Author = new char[30]{"London"};
books[5].Name = new char[30]{"Zov predkov"};
books[5].Genre = new char[30]{"Thriller"};

books[6].Author = new char[30]{"Lowrence"};
books[6].Name = new char[30]{"Raduga"};
books[6].Genre = new char[30]{"Roman"};

books[7].Author = new char[30]{"Lewis"};
books[7].Name = new char[30]{"Babbit"};
books[7].Genre = new char[30]{"Thriller"};

books[8].Author = new char[30]{"Hemingway"};
books[8].Name = new char[30]{"Fiesta"};
books[8].Genre = new char[30]{"Roman"};

books[9].Author = new char[30]{"Passos"};
books[9].Name = new char[30]{"1919"};
books[9].Genre = new char[30]{"Roman"};


    int bookNumber{};


cout << "Welcome to Library! " << endl;

cout << "1.Editor.\n"
        "2.Print all books.\n"
        "3.Search by author.\n"
        "4.Search by name.\n"
        "5.Sort by  name.\n"
        "6.Sort by author.\n";

while(true) {
    cout << "Enter your choice: ";
    cin >> choice;
    getchar();

    switch (choice) {
        case 1:
            system("cls");

            books->print(books);

            cout << "Enter number of book to edit: " << endl;
            cin >> bookNumber;

            books[bookNumber - 1].Editor();

            break;
        case 2:
            system("cls");
            books->print(books);

            break;
        case 3:
            system("cls");
            books->print(books);

            books->findAuthor(books);

            break;
        case 4:
            system("cls");
            books->print(books);

            books->findName(books);


            break;
        case 5:
            system("cls");
            books->print(books);

            books->sortName();

            break;
        case 6:
            system("cls");
            books->print(books);

            books->sortGenres();

            break;
    }
}











    return 0;
}
