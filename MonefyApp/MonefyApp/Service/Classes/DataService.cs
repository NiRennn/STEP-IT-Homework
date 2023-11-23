using GalaSoft.MvvmLight.Messaging;
using MonefyApp.Messages;
using MonefyApp.Models;
using MonefyApp.Service.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;

namespace MonefyApp.Service.Classes
{
    class DataService : IDataService
    {
        private readonly IMessenger _messenger;

        public DataService(IMessenger messenger)
        {
            _messenger = messenger;
        }

        public void SendData(object data)
        {
            _messenger.Send(new DataMessage()
            {
                Data = data
            });
        }
        public void SendButton(Button data)
        {
            _messenger.Send(new ButtonMessage()
            {
                Data = data
            });
        }
        public void SendValueName(object value, Button button, string description, string date, Color brush)
        {
            _messenger.Send(new ValueNameMessage()
            {
                Value = value,
                button = button,
                Description = description,
                Date = date,
                Brush = brush
            }) ;
        }
        public void SendDataExpense(object data)
        {
            _messenger.Send(new DataExpenseMessage()
            {
                Data = data,
            });
        }

        public void SendDate(string date) 
        {
            _messenger.Send(new DateMessege()
            {
                Date = date
            });
        }

        public void SendOtherExpenses(object value, string description, string date)
        {
            _messenger.Send(new OtherExpensesMessage()
            {
                Value = value,
                Description = description,
                Date = date
            });
        }
    }
}

