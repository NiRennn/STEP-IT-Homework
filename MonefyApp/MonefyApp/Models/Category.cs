using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace MonefyApp.Models
{
    public class Category
    {
        public string CategoryName { get; set; }
        public double CategorySum { get; set; } = 0;
        public DateTime Date { get; set; }
        public string Description { get; set; }
        public Color Color { get; set; }

        public Category(string name,double sum,DateTime date,string description,Color color)
        {
            CategoryName = name;
            CategorySum = sum;
            Date = date;
            Description = description;
            Color = color;
        }


        
    }


}
