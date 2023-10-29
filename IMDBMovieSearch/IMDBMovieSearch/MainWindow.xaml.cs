using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Xml.Linq;
using Newtonsoft.Json.Linq;

namespace IMDBMovieSearch
{

    public partial class MainWindow : Window
    {
        private const string ApiKey = "f1db0b3ff211765bbafb520864cb2477";
        private const string ApiBaseUrl = "https://api.themoviedb.org/3";
        public MainWindow()
        {
            InitializeComponent();
        }


        private async void SearchButton_Click(object sender, RoutedEventArgs e)
        {
            string searchTerm = txtSearch.Text;
            if (!string.IsNullOrWhiteSpace(searchTerm))
            {
                string apiUrl = $"{ApiBaseUrl}/search/movie?api_key={ApiKey}&query={searchTerm}";

                using (HttpClient client = new HttpClient())
                {
                    string jsonResult = await client.GetStringAsync(apiUrl);
                    JObject result = JObject.Parse(jsonResult);

                    // Обработка результатов поиска и преобразование JSON в объекты Movie
                    List<Movie> movies = new List<Movie>();
                    foreach (var item in result["results"])
                    {
                        Movie movie = new Movie
                        {
                            Title = item["title"].ToString(),
                            Overview = item["overview"].ToString(),
                            PosterPath = item["poster_path"].ToString(),
                        };
                        movies.Add(movie);
                    }

                    // Отображение результатов в интерфейсе
                    MovieResultView resultView = new MovieResultView(lstResults);
                    resultView.DisplayResults(movies);
                }
            }
        }
    }
}
