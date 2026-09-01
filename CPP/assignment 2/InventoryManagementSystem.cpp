#include <iostream>
using namespace std;

class Product {
private:
    int productId;
    string name;
    double price;
    int quantity;
public:
    void acceptDetails() {
        cout << "Enter Product ID: " << endl;
        cin >> productId;
        cout << "Enter Product Name: " << endl;
        cin >> name;
        cout << "Enter Price: " << endl;
        cin >> price;
        cout << "Enter Quantity: " << endl;
        cin >> quantity;
    }
    void displayDetails() const {
        cout << productId << "     "
             << name << "     "
             << price << "     "
             << quantity << "     "
             << totalValue() << endl;
    }
    double totalValue() const {
        double totalvalue = price * quantity;
        return totalvalue;
    }
    bool isLowStock() {
        return false;
    }
    bool isBelowThreshold(int threshold) {
        return quantity < threshold;
    }
    string getName() const {
        return name;
    }
};

double reorderCost (int quantity, double price){
	cout << "Reorder Cost: ";
	return quantity * price;
}
double reorderCost (double quantity, double price){
	cout << "Reorder Cost: ";
	return quantity * price;
}
double reorderCost (int quantity, double price, double taxRate){
	double cost = quantity * price;
	cout << "Reorder Cost: ";
	return cost + (cost * taxRate / 100);
}
double applyDiscount (double price, double discountPercent = 10.0){
	double discountAmount = price * (discountPercent / 100.0);
	cout << "Discounted price: ";
	return price - discountAmount;
}
int main() {
    Product inventory[5];
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Product " << (i + 1) << endl;
        inventory[i].acceptDetails();
    }
    cout << "===== INVENTORY REPORT =====" << endl;
    cout << "ID     Name     Price     Quantity     Total Value" << endl;

    for (int i = 0; i < 5; i++) {
        inventory[i].displayDetails();
    }

    cout << "--------------------------------------------------------" << endl;
    double highest = inventory[0].totalValue();    int highestIndex = 0;
    for (int i = 0; i < 5; i++) {
        if (inventory[i].totalValue() > highest) {
            highest = inventory[i].totalValue();
            highestIndex = i;
        }
    }
    cout << "Highest Value Product: " << inventory[highestIndex].getName() << "(Rs. " << highest << ")" << endl;
    int threshold = 10;
    cout << "Low Stock (threshold: 10) : ";
    for (int i = 0; i < 5; i++) {
        if (inventory[i].isBelowThreshold(threshold)) {
        	cout << inventory[i].getName() << endl;        }
    }
    cout << reorderCost(10, 50) << endl;
    cout << reorderCost(10.5, 50) << endl;
    cout << reorderCost(10, 50, 18) << endl;
    cout << applyDiscount(100) << endl;
    return 0;
}
