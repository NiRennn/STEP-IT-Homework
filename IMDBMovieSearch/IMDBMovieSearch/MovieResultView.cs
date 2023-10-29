using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace IMDBMovieSearch
{
    public class MovieResultView
    {
        private ListBox resultListBox;

        public MovieResultView(ListBox listBox)
        {
            resultListBox = listBox;
        }

        public void DisplayResults(List<Movie> movies)
        {
            resultListBox.ItemsSource = movies;
        }
    }
}
