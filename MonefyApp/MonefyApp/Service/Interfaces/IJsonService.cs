using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MonefyApp.Service.Interfaces
{
    public interface IJsonService
    {
        public void Serialize<T>(string path, ObservableCollection<T> list);

        public ObservableCollection<T> Deserialize<T>(string fileName);

    }
}
