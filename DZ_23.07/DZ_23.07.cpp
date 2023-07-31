#include <iostream>
#include <string>
#include <regex>
#include <fstream>

class User
{
public:
    std :: string username;
    std :: string password;
    std :: string email;
    std :: string phoneNumber;

    User() = default;

    User(std :: string username,std :: string password,std :: string email,std :: string phoneNumber)
    {
        this->username = username;
        this->password = password;
        this->email = email;
        this->phoneNumber = phoneNumber;
    }

    bool validUsername(const std::string& username)
    {
        std :: regex rUsername("[a-zA-Z0-9._]{3,15}");
        return std :: regex_match(username, rUsername);
    }

    bool validPassword(const std::string& password)
    {
        std :: regex rPassword("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,20}$");
        return std :: regex_match(password, rPassword);
    }

    bool validEmail(const std::string& email)
    {
        std :: regex rEmail(R"([_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4}))");
        return std :: regex_match(email, rEmail);
    }

    bool validNumber(const std::string& phoneNumber)
    {
        std :: regex rPhoneNumber("^[+]994[0-9]{9}");
        return std :: regex_match(phoneNumber, rPhoneNumber);
    }






};

void registerUser()
{
    User newUser;

    std :: cout << "Enter your username: ";
    std :: cin >> newUser.username;
    if (!newUser.validUsername(newUser.username))
    {
        std :: cout << "Invalid username. The username must contain only letters and numbers and be between 3 and 15 characters long. " << std :: endl;
        return;
    }

    std :: cout << "Enter your password: ";
    std :: cin >> newUser.password;
    if (!newUser.validPassword(newUser.password))
    {
        std :: cout << "Incorrect password. The password must contain at least one lowercase letter, one uppercase letter, one number, and have 8 or more characters. " << std :: endl;
        return;
    }

    std :: cout << "Enter your email: ";
    std :: cin >> newUser.email;
    if (!newUser.validEmail(newUser.email))
    {
        std :: cout << "Invalid email. Try again. " << std :: endl;
        return;
    }

    std :: cout << "Enter your phone number: ";
    std :: cin >> newUser.phoneNumber;
    if (!newUser.validNumber(newUser.phoneNumber))
    {
        std :: cout << "Invalid phoneNumber. Try again. " << std :: endl;
        return;
    }

    std :: ofstream outfile("users.txt", std :: ios :: app);

    if(outfile.is_open())
    {
        outfile << newUser.username << ' ' << newUser.password << ' ' << newUser.email << ' ' << newUser.phoneNumber << std :: endl;
        outfile.close();
        std :: cout << "Registration completed successfully!" << std::endl;

    }
    else
    {
        std :: cout << "Error! data was not written in the file!" << std::endl;
    }


}

void loginUser()
{
    User user;
    std :: cout << "Enter your username and password" << std::endl;

    std :: cout << "Username: " << std::endl;
    std :: cin >> user.username;

    std:: cout << "Password: " << std::endl;
    std :: cin >> user.password;

    std :: ifstream inFile("users.txt");
    if(inFile.is_open())
    {
        std :: string line;
        while (std::getline(inFile, line))
        {
            std::string username_in_file, password_in_file;
            std::istringstream iss(line);
            if (iss >> username_in_file >> password_in_file)
            {
                if (username_in_file == user.username && password_in_file == user.password) {
                    std::cout << "Login successful!\n";
                    inFile.close();
                    return;
                }
            }
        }
        std :: cout << "Error: User with the given name or password was not found." << std :: endl;
        inFile.close();
    }

}




int main() {


int option{};

do {
    std :: cout << "Welcome! Please enter option: " << std :: endl
                << "1.Register" << std :: endl
                << "2.Login " << std :: endl
                << "3.End programm " << std :: endl;

    std :: cin >> option;

    try {
        switch(option) {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                break;
        }
    } catch (const std::exception& error){
        std::cout << "Error: " << error.what() << std::endl;
    }
}while (option != 3);






    return 0;
}
