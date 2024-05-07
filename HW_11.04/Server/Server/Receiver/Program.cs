using System;
using System.IO;
using System.Net.Sockets;
using System.Net;

int port = 12345;
IPAddress ipAddress = IPAddress.Parse("127.0.0.1");

try
{
    using (UdpClient listener = new UdpClient(port))
    {
        IPEndPoint endPoint = new IPEndPoint(ipAddress, port);

        List<byte[]> receivedBlocks = new List<byte[]>();

        while (true)
        {
            byte[] receivedBytes = listener.Receive(ref endPoint);
            receivedBlocks.Add(receivedBytes);

            if (receivedBytes.Length < 1024)
                break;
        }

        byte[] mp3Bytes = receivedBlocks.SelectMany(b => b).ToArray();

        string downloadsPath = Environment.GetFolderPath(Environment.SpecialFolder.UserProfile);
        string fileName = Path.Combine(downloadsPath, "Downloads", "received.mp3");
        File.WriteAllBytes(fileName, mp3Bytes);

        Console.WriteLine("Файл успешно сохранен: " + fileName);
    }
}
catch (Exception ex)
{
    Console.WriteLine($"Ошибка: {ex.Message}");
}
