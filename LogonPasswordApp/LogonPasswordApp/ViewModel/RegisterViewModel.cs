using LogonPasswordApp.Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.IO;
using System.Text.Json;

namespace LogonPasswordApp.ViewModel
{
    public class RegisterViewModel
    {
        private UserDataManager userManager;

        public RegisterViewModel()
        {
            userManager = new UserDataManager();
        }
        public class UserDataManager
        {
            private const string UsersDataPath = "users.json";

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
        public void RegisterMethod(string username, string password)
        {
            List<User> users = userManager.LoadUsers();

            if (userManager.UserExists(username))
            {
                MessageBox.Show("A user with the same name already exists.", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            else
            {
                userManager.SaveUsers(users);
                MessageBox.Show("Регистрация прошла успешно.", "Успех", MessageBoxButton.OK, MessageBoxImage.Information);
            }
        }

    }
}
