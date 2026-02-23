namespace task2.Models;
public interface IOrganization
{
    string Name { get; set; }
    string Address { get; set; }

    void ShowInfo();
    int GetEmployeeCount();
}