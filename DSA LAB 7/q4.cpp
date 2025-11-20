#include <iostream>
using namespace std;

class Product 
{
public:
    string name;
    double price;
    string description;
    bool available;

    Product(string n, double p, string d, bool a) : name(n), price(p), description(d), available(a) {}
};

void swap(Product &a, Product &b) 
{
    Product temp = a;
    a = b;
    b = temp;
}

int partition(Product arr[], int low, int high) 
{
    double pivot = arr[high].price;
    int i = low - 1;
    for(int j = low; j < high; j++)
       if(arr[j].price <= pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(Product arr[], int low, int high)
{
    if(low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printProducts(Product arr[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        cout << arr[i].name << " - $" << arr[i].price << " - " 
             << arr[i].description << " - " 
             << (arr[i].available ? "Available" : "Out of stock") << endl;
    }
}

int main() 
{
    Product products[3] = 
    {
        Product("Laptop", 5443, "gygg", true),
        Product("Headphones", 553, "jtfvbhjbjbjbj", true),
        Product("Mouse", 11, "wwwwwwwww", false)
    };

    quickSort(products, 0, 2);
    printProducts(products, 3);
}
