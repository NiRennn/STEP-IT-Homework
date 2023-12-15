using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace ToDoListWPF
{
    public class ConcreteTaskManagerFactory : TaskManagerFactory
    {
        public override ITaskButton CreateTaskButton()
        {
            return new WpfTaskButton();
        }

        public override ITaskTextBox CreateTaskTextBox()
        {
            return new WpfTaskTextBox();
        }

        public override ITaskListBox CreateTaskListBox()
        {
            return new WpfTaskListBox();
        }
    }

    public class WpfTaskButton : ITaskButton
    {
        public Button CreateButton()
        {
            return new Button();
        }
    }

    public class WpfTaskTextBox : ITaskTextBox
    {
        public TextBox CreateTextBox()
        {
            return new TextBox();
        }
    }

    public class WpfTaskListBox : ITaskListBox
    {
        public ListBox CreateListBox()
        {
            return new ListBox();
        }
    }
}
