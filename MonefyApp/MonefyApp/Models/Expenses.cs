using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MonefyApp.Models
{
    class Expenses
    {
        public double CategorySum { get; set; } = 0;
        public DateTime Date { get; set; }
        public string Description { get; set; }

        public Expenses( double sum, DateTime date, string description)
        {
            CategorySum = sum;
            Date = date;
            Description = description;
        }
    }
}
