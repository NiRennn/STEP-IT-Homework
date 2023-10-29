using LogonPasswordApp.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Threading.Tasks;
using System.IO;
using System.Text.Json;
using System.Windows;

namespace LogonPasswordApp.ViewModel
{
    public class LoginViewModel
    {
        private UserDataManager userManager;

        public LoginViewModel()
        {
            userManager = new UserDataManager();
        }
        public class UserDataManager
        {
            public const string UsersDataPath = "users.json";

            public List<User> LoadUsers()
            {
                if (File.Exists(UsersDataPath))
                {
                    string json = File.ReadAllText(UsersDataPath);
                    return JsonSerializer.Deserialize<List<User>>(json);
                }
                return new List<User>();
            }

            public void SaveUsers(List<User> users)
            {
                string json = JsonSerializer.Serialize(users);
                File.WriteAllText(UsersDataPath, json);
            }

            public bool UserExists(string username)
            {
                List<User> users = LoadUsers();
                return users.Any(user => user.Username == username);
            }

        }
        public void LoginMethod(string username, string password)
        {
            List<User> users = userManager.LoadUsers();

            if (users.Exists(user => user.Username == username && user.Password == password))
            {
                MessageBox.Show("Login successful.", "Success", MessageBoxButton.OK, MessageBoxImage.Information);
            }
            else
            {
                MessageBox.Show("The username or password you entered is incorrect.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }


    }
}
