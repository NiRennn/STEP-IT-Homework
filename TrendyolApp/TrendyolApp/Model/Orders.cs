using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrendyolApp.Model
{
    public class Orders
    {
        [Key]
        public int Id { get; set; }

        [Required, ForeignKey("Users")]
        public int UserId { get; set; }
        [Required]
        public User Users { get; set; }

        [Required, ForeignKey("Products")]
        public int ProductId { get; set; }
        [Required]
        public Product Product { get; set; }

        [Required]
        public string Status { get; set; }
    }
}
