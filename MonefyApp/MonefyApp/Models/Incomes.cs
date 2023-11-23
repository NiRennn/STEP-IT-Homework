using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MonefyApp.Models
{
    class Incomes
    {
        public Incomes(double value, DateTime date, string note)
        {
            Value = value;
            Date = date;
            Note = note;
        }


        public double Value { get; set; }
        public DateTime Date { get; set; }
        public string Note { get; set; }
    }
}
