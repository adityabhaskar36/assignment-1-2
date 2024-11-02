#include <iostream>
#include <string.h>
using namespace std;

class Product
{
    int productId;
    char name[20];
    float price;

public:
    Product()
    {
        productId = 0;
        strcpy(name, "");
        price = 0.0;
    }
    virtual void getData()
    {
        cout << "Enter Product ID: ";
        cin >> productId;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Price: ";
        cin >> price;
    }
    virtual void displayProductDetails()
    {
        cout << "Product ID: " << productId << endl;
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
    }
};

class Electronics : public Product
{
    int warrantyPeriod;

public:
    void getData()
    {
        cout << endl
             << "Enter details for Electronics:" << endl;
        Product::getData();
        cout << "Enter Warranty Period (Years): ";
        cin >> warrantyPeriod;
    }
    void displayProductDetails()
    {
        cout << endl
             << "Electronics Details:" << endl;
        Product::displayProductDetails();
        cout << "Warranty Period: " << warrantyPeriod << " Years" << endl;
    }
};

class Furniture : public Product
{
    char materialType[20];

public:
    void getData()
    {
        cout << endl
             << "Enter details for Furniture:" << endl;
        Product::getData();
        cout << "Enter Material Type: ";
        cin >> materialType;
    }
    void displayProductDetails()
    {
        cout << endl
             << "Furniture Details:" << endl;
        Product::displayProductDetails();
        cout << "Material Type: " << materialType << endl;
    }
};

int main()
{
    Electronics e1;
    Furniture f1;
    Product *arr[2];
    arr[0] = &e1;
    arr[1] = &f1;
    for (int i = 0; i < 2; i++)
    {
        arr[i]->getData();
        arr[i]->displayProductDetails();
    }

    return 0;
}
