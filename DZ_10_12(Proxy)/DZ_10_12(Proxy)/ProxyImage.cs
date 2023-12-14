using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_10_12_Proxy_
{
     class ProxyImage
    {
        private MyImage myImage;
        private string filename;

        public ProxyImage(string filename)
        {
            this.filename = filename;
        }

        public void Display()
        {
            if (myImage == null)
            {
                myImage = new MyImage(filename);
            }

            Console.WriteLine("ProxyImage: Performing access control or additional actions before displaying.");

            myImage.Display();
        }
    }
}
