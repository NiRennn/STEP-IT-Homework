using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrendyolApp.Model
{
    public class CurrentUser
    {
        public int Id { get; set; }
        public string UserName { get; set; }
        public string Email { get; set; }
        public float Balance { get; set; }
        public string Position { get; set; }


        public void ClearUser()
        {
            UserName = null;
            Email = null;
            Balance = 0;
            Position = null;
        }
    }


}
