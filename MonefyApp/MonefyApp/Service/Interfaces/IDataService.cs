using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media;
using MonefyApp.Models;
namespace MonefyApp.Service.Interfaces
{
    interface IDataService
    {
        public void SendData(object data);
        public void SendDataExpense(object data);
        public void SendButton(Button data);
        public void SendValueName(object value,Button button,string description,string date,Color brush);
        public void SendDate(string date);
        public void SendOtherExpenses(object value, string description, string date);

    }
}
