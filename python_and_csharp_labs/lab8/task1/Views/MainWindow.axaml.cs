using Avalonia.Controls;
using lab8.ViewModels;
using lab8.Models;
using System.Collections.Generic;
using System;

namespace lab8;

public partial class MainWindow : Window
{
    private readonly ProductManager _manager = new();
    public MainWindow()
    {
        InitializeComponent();
    }

    private void AddProductClick(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        try
        {
            string name = ProductNameBox.Text ?? "";
            double price = double.Parse(ProductPriceBox.Text ?? "0");
            int quantity = int.Parse(ProductQuantityBox.Text ?? "0");
            string category = ProductCategoryBox.Text ?? "0";

            _manager.AddProduct(name, price, quantity, category);
            RefreshProductList(_manager.GetAllProducts());
            AveragePriceBlock.Text = $"Average Price: {_manager.GetAveragePrice()}";
        }
        catch (Exception)
        {
            ShowMessage("Wrong Data.");
        }
    }
    private void RefreshProductList(IEnumerable<Product> products)
    {
        ProductListBox.ItemsSource = products;
    }

    private void ShowAllProductsClick(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        RefreshProductList(_manager.GetAllProducts());
    }

    private void ShowSocialProductsClick(object? sender, Avalonia.Interactivity.RoutedEventArgs e)
    {
        RefreshProductList(_manager.GetSocialProducts());
        AveragePriceBlock.Text = $"Social Products Count: {_manager.GetSocialProductsCount()}";
    }
        
    private async void ShowMessage(string message)
    {
        var dialog = new Window
        {
            Width = 300,
            Height = 150,
            Content = new TextBlock
            {
                Text = message,
                VerticalAlignment = Avalonia.Layout.VerticalAlignment.Center,
                HorizontalAlignment = Avalonia.Layout.HorizontalAlignment.Center
            }
        };
        await dialog.ShowDialog(this);
    }
}