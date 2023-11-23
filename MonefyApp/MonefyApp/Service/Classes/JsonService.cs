using MonefyApp.Service.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.Json;
using MonefyApp.Models;
using Newtonsoft.Json;
using System.Collections.ObjectModel;
using System.IO;

namespace MonefyApp.Service.Classes
{
    class JsonService : IJsonService
    {
        public void Serialize<T>(string path, ObservableCollection<T> list)
        {
            using var fileStream = new FileStream(path, FileMode.Create, FileAccess.Write);
            using var streamWriter = new StreamWriter(fileStream);
            string json = JsonConvert.SerializeObject(list, Formatting.Indented);
            streamWriter.Write(json);
        }

        public ObservableCollection<T> Deserialize<T>(string fileName)
        {
            using var fileStream = new FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Read);
            using var streamReader = new StreamReader(fileStream);

            string json = streamReader.ReadToEnd();

            var deserializedObject = JsonConvert.DeserializeObject<ObservableCollection<T>>(json, new JsonSerializerSettings
            {
                TypeNameHandling = TypeNameHandling.All
            });

            return deserializedObject;
        }


    }
}
