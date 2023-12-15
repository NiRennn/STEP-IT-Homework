using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace ToDoListWPF
{
    public interface ITaskButton
    {
        Button CreateButton();
    }

    public interface ITaskTextBox
    {
        TextBox CreateTextBox();
    }

    public interface ITaskListBox
    {
        ListBox CreateListBox();
    }

    
}
