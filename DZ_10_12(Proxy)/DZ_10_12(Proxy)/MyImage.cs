using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ_10_12_Proxy_
{
     class MyImage : IImage
    {
        private string filename;

        public MyImage(string filename)
        {
            this.filename = filename;
            LoadImageFromDisk();
        }

        private void LoadImageFromDisk()
        {
            Console.WriteLine($"Loading image from disk: {filename}");
        }

        public void Display()
        {
            Console.WriteLine($"Displaying image: {filename}");
        }
    }
}
