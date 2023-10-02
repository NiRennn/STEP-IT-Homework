using System.Text;
using System.Text.RegularExpressions;


class MenuManagement
{
    public List<Dictionary> dictionaries = new();
    public Dictionary currentDictionary;
    
    
    
    public string RegexInput(string inputText, string pattern)
    {
        string UserInput;
        do
        {
            Console.WriteLine(inputText);
            UserInput = Console.ReadLine();
                        
        } while (!Regex.IsMatch(UserInput, pattern));
        return UserInput;
    }
    
    public void CreateDictionary()
    {
        Console.WriteLine("***Menu for creating a new dictionary***");
        Console.Write("\n");
        try
        {
            string Name = RegexInput("Enter name of dictionary(only letters and spaces allowed): ","^[a-zA-Zа-яА-Я ]+$");
            string Source = RegexInput("Enter source language(only letters and spaces allowed): ","^[a-zA-Zа-яА-Я ]+$");
            string Target = RegexInput("Enter target language(only letters and spaces allowed): ","^[a-zA-Zа-яА-Я ]+$");

            Dictionary newDictionary = new Dictionary(Name, Source, Target);
            dictionaries.Add(newDictionary);
            currentDictionary = newDictionary;
        
            string dictionaryPath = $"{newDictionary.SourceLanguage}-{newDictionary.TargetLanguage}.csv";

            using (StreamWriter sw = new StreamWriter(dictionaryPath, false, Encoding.UTF8))
            {
                sw.WriteLine("Source Word, Target Word");
            
            }
            
            Console.WriteLine("Dictionary created successfully!");
        
            Console.WriteLine("Press <Enter> to finish...");
            while (Console.ReadKey().Key != ConsoleKey.Enter) {}
        }
        catch (Exception exception)
        {
            Console.WriteLine($"An error has occurred: {exception.Message}");
        }
    }
    
    public void LoadDictionaries()
    {
        try
        {
            string[] dictionaryFiles = Directory.GetFiles(Directory.GetCurrentDirectory(), "*.csv");

            foreach (var file in dictionaryFiles)
            {
                string fileName = Path.GetFileNameWithoutExtension(file).Replace(" ", "-");
                string[] nameParts = fileName.Split('-');

                if (nameParts.Length == 2)
                {
                    string sourceLanguage = nameParts[0].Trim();
                    string targetLanguage = nameParts[1].Trim();

                    Dictionary existingDictionary = new Dictionary(fileName, sourceLanguage, targetLanguage);
                    dictionaries.Add(existingDictionary);
                }
            }
        }
        catch (Exception exception)
        {
            Console.WriteLine($"Error loading dictionary: {exception.Message}");
        }
    }

    public void WorkWithDictionary()
    {
        LoadDictionaries();

        Console.WriteLine("***Menu for working with dictionary***");
        Console.Write("\n");

        Console.WriteLine("List of available dictionaries:");
        for (int i = 0; i < dictionaries.Count; i++)
        {
            Console.WriteLine($"{i + 1}. {dictionaries[i].DictionaryName}");
        }

        Console.WriteLine($"{dictionaries.Count + 1}. Back to main manu");
        int choice = Int32.Parse(Console.ReadLine());

        if (choice <= dictionaries.Count && choice >= 1)
        {
            var dictionaryTmp = dictionaries[choice - 1];
            currentDictionary = dictionaryTmp;

            while (true)
            {
                Console.Clear();
                Console.WriteLine($"Selected dictionary : {dictionaryTmp.DictionaryName}");
                Console.WriteLine("1. Add word and translation");
                Console.WriteLine("2. Edit word and translation");
                Console.WriteLine("3. Delete word and translate");
                Console.WriteLine("4. Search translation of word");
                Console.WriteLine("5. Back to main manu");

                int choiceMenu = Int32.Parse(Console.ReadLine());

                try
                {
                    switch (choiceMenu)
                    {
                        case 1:
                            AddW();
                            break;
                        case 2:
                            EditW();
                            break;
                        case 3:
                            DeleteW();
                            break;
                        case 4:
                            SearchW();
                            break;
                        case 5:
                            return;
                        default:
                            Console.WriteLine("Invalid menu choice.");
                            break;

                    }
                }
                catch (Exception exception)
                {
                    Console.WriteLine($"An error has occurred: {exception.Message}");
                    Console.WriteLine("Press <Enter> to continue");
                    while (Console.ReadKey().Key != ConsoleKey.Enter)
                    {
                    }
                }



                void AddW()
                {
                    Console.WriteLine("***Menu for adding a word to the dictionary***");
                    Console.WriteLine("\n");

                    try
                    {
                        string originalWord = RegexInput("Enter word(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$");
                        string translation = RegexInput("Enter translation(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$");


                        Word newWord = new Word(originalWord, translation);

                        string dictionaryPath = $"{currentDictionary.DictionaryName}.csv";

                        using (StreamWriter sw = new StreamWriter(dictionaryPath, true, Encoding.UTF8))
                        {
                            if (sw.BaseStream.Length == 0)
                            {
                                sw.WriteLine("Source Word, Target Word");
                            }

                            sw.WriteLine($"{newWord.SourceWord}, {newWord.TargetWord}");
                        }

                        Console.WriteLine("Word added to dictionary successfully! ");
                        Console.WriteLine("Press <Enter> to continue...");
                        while (Console.ReadKey().Key != ConsoleKey.Enter)
                        {
                        }
                    }
                    catch (Exception exception)
                    {
                        Console.WriteLine($"An error has occured: {exception.Message}");
                    }
                }



                void EditW()
                {
                    Console.WriteLine("***Menu for editing a word in the dictionary***");
                    Console.WriteLine("\n");
                    try
                    {
                        string wordToEdit = RegexInput("Enter word to edit: ", "^[a-zA-Zа-яА-Я ]+$");
                        string newWordToEdit = RegexInput("Enter new word(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$");
                        string newTranslation = RegexInput("Enter new translation(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$");

                        string dictionaryPath = $"{currentDictionary.DictionaryName}.csv";


                        if (File.Exists(dictionaryPath))
                        {
                            var lines = File.ReadAllLines(dictionaryPath).ToList();

                            for (int i = 0; i < lines.Count; i++)
                            {
                                string[] parts = lines[i].Split(',');

                                if (parts.Length == 2 && parts[0].Trim() == wordToEdit)
                                {
                                    lines[i] = $"{newWordToEdit}, {newTranslation}";
                                    File.WriteAllLines(dictionaryPath, lines, Encoding.UTF8);
                                    Console.WriteLine("Word edited successfully!");
                                    break;
                                }
                            }

                        }
                        else
                        {
                            Console.WriteLine("Dictionary file not found!");
                        }

                        Console.WriteLine("Press <Enter> to continue...");
                        while (Console.ReadKey().Key != ConsoleKey.Enter)
                        {
                        }
                    }
                    catch (Exception exception)
                    {
                        Console.WriteLine($"An error has occurred: {exception.Message}");
                    }
                }

                void DeleteW()
                {
                    Console.WriteLine("***Menu for deleting a word from the dictionary***");
                    Console.WriteLine("\n");

                    try
                    {
                        string wordToDelete = RegexInput("Enter word to delete(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$").Trim();

                        string dictionaryPath = $"{currentDictionary.DictionaryName}.csv";

                        if (File.Exists(dictionaryPath))
                        {
                            var lines = File.ReadAllLines(dictionaryPath).ToList();
                            bool wordFound = false;

                            for (int i = 0; i < lines.Count(); i++)
                            {
                                string[] parts = lines[i].Split(',');

                                if (parts.Length == 2 && parts[0].Trim() == wordToDelete)
                                {
                                    lines.RemoveAt(i);
                                    File.WriteAllLines(dictionaryPath, lines, Encoding.UTF8);
                                    Console.WriteLine("Word deleted successfully!");
                                    wordFound = true;
                                    break;
                                }
                            }

                            if (!wordFound)
                            {
                                Console.WriteLine("Word not found in the dictionary.");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Dictionary file not found!");
                        }

                        Console.WriteLine("Press <Enter> to continue...");
                        while (Console.ReadKey().Key != ConsoleKey.Enter)
                        {
                        }
                    }
                    catch (Exception exception)
                    {
                        Console.WriteLine($"An error has occured: {exception.Message}");
                    }
                }


                void SearchW()
                {
                    Console.WriteLine("***Menu for searching a word in the dictionary***");
                    Console.WriteLine("\n");
                    try
                    {
                        string wordToSearch = RegexInput("Enter word to search(only letters and spaces allowed): ",
                            "^[a-zA-Zа-яА-Я ]+$");

                        string dictionaryPath = $"{currentDictionary.DictionaryName}.csv";

                        if (File.Exists(dictionaryPath))
                        {
                            var lines = File.ReadAllLines(dictionaryPath, Encoding.UTF8).ToList();
                            bool wordFound = false;

                            foreach (var line in lines)
                            {
                                string[] parts = line.Split(',');
                                if (parts.Length == 2 && parts[0].Trim() == wordToSearch)
                                {
                                    Console.WriteLine($"Word: {parts[0].Trim()}");
                                    Console.WriteLine($"Translation: {parts[1].Trim()}");
                                    Console.WriteLine();
                                    wordFound = true;
                                    break;
                                }
                            }

                            if (!wordFound)
                            {
                                Console.WriteLine("Word not found in the dictionary.");
                            }
                        }
                        else
                        {
                            Console.WriteLine("Dictionary file not found!");
                        }

                        Console.WriteLine("Press <Enter> to continue...");
                        while (Console.ReadKey().Key != ConsoleKey.Enter)
                        {
                        }
                    }
                    catch (Exception exception)
                    {
                        Console.WriteLine($"An error has occurred: {exception.Message}");
                    }

                }
            }
        }
    }

}
