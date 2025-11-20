#include <iostream>
using namespace std;

class Product
{
    string name;
    int price;
    int stock;
    public:
    Product(string name,int price, int stock):name{name}, price{price},stock{stock}{}
    void display(int discountMultiplier=1)
    {
        cout<<"\nName:"<<name<<"\nPrice:"<<price*discountMultiplier<<"\nStock:"<<stock;
    } 
};

class Bundle
{
    Product** products;
    int numProducts;
    float discountMultiplier;
    public:
    Bundle():products(new Product* [0]),numProducts(0),discountMultiplier{1}{};
    void addProduct(Product* product)
    {
        Product** np=new Product* [++numProducts];
        for(int i=0;i<numProducts-1;i++)np[i]=products[i];
        np[numProducts-1]=product;
        delete[] products;
        products=np;
    }

    void display()
    {
        for(int i=0;i<numProducts;i++)
        {
            cout<<"\n-------------------------";
            cout<<"\nNO:"<<i;
            products[i]->display(discountMultiplier);
        }
    }

    void shallowCopy(Bundle& b)
    {
        delete[] products;
        products=b.products;
        numProducts=b.numProducts;
        discountMultiplier=b.discountMultiplier;
    }

    void deepCopy(Bundle&b)
    {
        delete[] products;
        numProducts=b.numProducts;
        discountMultiplier=b.discountMultiplier;
        products=new Product* [numProducts];
        for(int i=0;i<numProducts;i++)products[i]=b.products[i];
    }
    void changeFirstIndex(Product* product){products[0]=product;}
    void applyDiscount(int discountMultiplier){this->discountMultiplier=discountMultiplier;}
};

int main()
{
    Product oranges("orange",50,100);
    Product apples("apple(original first entry)",70,12);
    Product bar("dish-cleaning bar",100,20);
    Product soap("soap(this is a new entry)",10,12);
    Bundle original;
    original.addProduct(&apples);
    original.addProduct(&oranges);
    original.addProduct(&bar);
    cout<<"\n\n\n\nOriginal Bundle:";
    original.display();

    //deep copy
    Bundle deepCopy;
    deepCopy.deepCopy(original);
    deepCopy.changeFirstIndex(&soap);
    cout<<"\n\n\n\nValue of deep-copy after change:";
    deepCopy.display();
    cout<<"\n\n\n\nOriginal Bundle after Deep-Copy and change:";
    original.display();

    //shallow copy
    Bundle shallowCopy;
    shallowCopy.shallowCopy(original);
    shallowCopy.changeFirstIndex(&soap);
    cout<<"\n\n\n\nValue of shallow-copy after change:";
    shallowCopy.display();
    cout<<"\n\n\n\nOriginal Bundle after shallow-Copy and change:";
    original.display();

    return 0;
}