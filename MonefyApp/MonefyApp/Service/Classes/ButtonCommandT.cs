using System;
using System.Windows.Input;

namespace MonefyApp.Service.Classes
{
    class ButtonCommand<T> : ICommand
    {
        private readonly Action<T> _funcToExecute;
        private readonly Func<T, bool> _funcToCheck = _ => true;

        public event EventHandler? CanExecuteChanged
        {
            add { CommandManager.RequerySuggested += value; }
            remove { CommandManager.RequerySuggested -= value; }
        }

        public ButtonCommand(Action<T> funcToExecute)
        {
            _funcToExecute = funcToExecute;
        }

        public ButtonCommand(Action<T> funcToExecute, Func<T, bool> funcToCheck)
        {
            _funcToExecute = funcToExecute;
            _funcToCheck = funcToCheck;
        }

        public bool CanExecute(object? parameter)
        {
            return _funcToCheck((T)parameter!);
        }

        public void Execute(object? parameter)
        {
            _funcToExecute((T)parameter!);
        }
    }
}
