using Avalonia.Controls;
using Avalonia.Interactivity;
using System.IO;

namespace task1;

public partial class MainWindow : Window
{
    private class Person
    {
        private string firstName = "";
        private string lastName = "";
        private int age;
        private double height;
        private double weight;
        private string occupation = "";
        private bool isMarried;
        
        public Person()
        {
            firstName = "";
            lastName = "";
            age = 0;
            height = 0;
            weight = 0;
            occupation = "";
            isMarried = false;
        }

        public string FirstName
        {
            get { return firstName; }
            set { firstName = value; }
        }
        public string LastName
        {
            get { return lastName; }
            set { lastName = value; }
        }
        public int Age
        {
            get { return age; }
            set { age = value; }
        }
        public double Height
        {
            get { return height; }
            set { height = value; }
        }
        public double Weight
        {
            get { return weight; }
            set { weight = value; }
        }
        public string Occupation
        {
            get { return occupation; }
            set { occupation = value; }
        }
        public bool IsMarried
        {
            get { return isMarried; }
            set { isMarried = value; }
        }

        public string Summary()
        {
            return $"Name: {FirstName} {LastName}\n" +
                   $"Age: {Age}\n" +
                   $"Height: {Height} cm, Weight: {Weight} kg\n" +
                   $"Occupation: {Occupation}\n" +
                   $"Married: {(IsMarried ? "Yes" : "No")}";
        }

        public bool IsAdult()
        {
            return Age >= 18;
        }

        public void SaveToFile(string filename)
        {
            File.WriteAllText(filename, Summary());
        }
    }
    private void CreatePerson_Click(object sender, RoutedEventArgs e)
    {
        int age = int.TryParse(AgeBox.Text, out var a) ? a : 0;
        double height = double.TryParse(HeightBox.Text, out var h) ? h : 0;
        double weight = double.TryParse(WeightBox.Text, out var w) ? w : 0;

        Person person = new Person
        {
            FirstName = FirstNameBox.Text,
            LastName = LastNameBox.Text,
            Age = age,
            Height = height,
            Weight = weight,
            Occupation = OccupationBox.Text,
            IsMarried = IsMarriedBox.IsChecked ?? false
        };

        person.SaveToFile("person.txt");
        ResultTextBlock.Text = person.Summary();
    }
        
    public MainWindow()
    {
        InitializeComponent();
    }
}