using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrendyolApp.Model
{
    public class Warehouse
    {

        [Key]
        public int Id { get; set; }
        [Required, ForeignKey("Products")]
        public int ProductId { get; set; }
        public Product Products { get; set; }

    }
}
