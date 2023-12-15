using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ToDoListWPF
{
    public abstract class TaskManagerFactory
    {
        public abstract ITaskButton CreateTaskButton();
        public abstract ITaskTextBox CreateTaskTextBox();
        public abstract ITaskListBox CreateTaskListBox();
    }
}
