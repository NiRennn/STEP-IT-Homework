using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace ToDoListWPF
{

    public partial class MainWindow : Window
    {
        public ObservableCollection<TaskItem> Tasks { get; set; }

        private readonly TaskManagerFactory _taskManagerFactory;

        public MainWindow()
        {
            InitializeComponent();

            _taskManagerFactory = new ConcreteTaskManagerFactory();

            var addButton = _taskManagerFactory.CreateTaskButton().CreateButton();
            addButton.Content = "Add Task";
            addButton.Click += AddTask_Click;

            var deleteButton = _taskManagerFactory.CreateTaskButton().CreateButton();
            deleteButton.Content = "Delete Task";
            deleteButton.Click += DeleteTask_Click;

            var taskTextBox = _taskManagerFactory.CreateTaskTextBox().CreateTextBox();
            var taskListBox = _taskManagerFactory.CreateTaskListBox().CreateListBox();

            var grid = (Grid)Content;
            grid.Children.Add(addButton);
            grid.Children.Add(deleteButton);
            grid.Children.Add(taskTextBox);
            grid.Children.Add(taskListBox);
        }

        private void AddTask_Click(object sender, RoutedEventArgs e)
        {
            if (!string.IsNullOrWhiteSpace(taskTextBox.Text))
            {
                Tasks.Add(new TaskItem { TaskName = taskTextBox.Text });
                taskTextBox.Clear();
            }
        }

        private void DeleteTask_Click(object sender, RoutedEventArgs e)
        {
            if (taskListBox.SelectedItem != null)
            {
                Tasks.Remove((TaskItem)taskListBox.SelectedItem);
            }
        }
    }

   
}

