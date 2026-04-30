using System.Collections.Generic;
using System.Linq;
using lab8.Models;

namespace lab8.ViewModels;
public class ProductManager
{
    private readonly List<Product> _products = new();
    public void AddProduct(string name, double price, int quantity, string category)
    {
        var product = new Product(name, price, quantity, category);
        _products.Add(product);
    }

    public IEnumerable<Product> GetAllProducts() => _products;
    // Average очікує функцію, яка вкаже яке саме поле з кожного елемента взяти
    public double GetAveragePrice() => _products.Any() ? _products.Average(product => product.Price) : 0.0;

    public IEnumerable<Product> GetSocialProducts() => _products.Where(p => p.Price < GetAveragePrice());

    public int GetSocialProductsCount() => GetSocialProducts().Count();
    

}