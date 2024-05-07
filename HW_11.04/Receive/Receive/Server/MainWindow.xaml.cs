using Microsoft.Win32;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Windows;

namespace Server
{
    public partial class MainWindow : Window
    {
        int port = 12345;
        IPAddress ipAddress = IPAddress.Parse("127.0.0.1");

        public MainWindow()
        {
            InitializeComponent();
        }

        private void SelectMP3(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "MP3 files (*.mp3)|*.mp3";

            bool? result = openFileDialog.ShowDialog();

            if (result == true)
            {
                SendMP3(openFileDialog.FileName);
            }
        }

        private void SendMP3(string fileName)
        {
            try
            {
                byte[] mp3Bytes = File.ReadAllBytes(fileName);

                int blockSize = 1024;
                int totalBlocks = (int)Math.Ceiling((double)mp3Bytes.Length / blockSize);

                using (UdpClient client = new UdpClient())
                {
                    IPEndPoint endPoint = new IPEndPoint(ipAddress, port);

                    for (int i = 0; i < totalBlocks; i++)
                    {
                        int offset = i * blockSize;
                        int length = Math.Min(blockSize, mp3Bytes.Length - offset);
                        byte[] block = new byte[length];
                        Buffer.BlockCopy(mp3Bytes, offset, block, 0, length);

                        client.Send(block, block.Length, endPoint);
                    }

                    MessageBox.Show("Файл успешно отправлен.");
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Ошибка: {ex.Message}");
            }
        }
    }
}