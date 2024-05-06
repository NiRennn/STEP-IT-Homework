using RestSharp;
using System;
using System.Net.Http;
using System.Threading.Tasks;


Console.WriteLine("1.Post\n2.Get");
int a;
var metod = int.Parse(Console.ReadLine());

switch (metod)
{
    case 1:
        {      
            var client = new RestClient("http://localhost:5273"); 

            var request = new RestRequest("/addbrand", Method.Post);            
            
            request.AddHeader("brand", "Mersedes");

            var response = client.Execute(request);

            if (response.IsSuccessful)
            {
                var content = response.Content;
                Console.WriteLine(content);
            }
            else
            {
                Console.WriteLine("Error: " + response.ErrorMessage);
            }
            break;
        }
    case 2:
        {
            var client = new RestClient("http://localhost:5273"); 

            var request = new RestRequest("/getproducts", Method.Get);

            var response = client.Execute(request);

            if (response.IsSuccessful)
            {
                var content = response.Content;
                Console.WriteLine(content);
            }
            else
            {
                Console.WriteLine("Error: " + response.ErrorMessage);
            }
            break;
        }
    default:
        break;
}







