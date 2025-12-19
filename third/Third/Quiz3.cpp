#include <iostream>
#include <string>
using namespace std;
class Item
{
public:
	Item()
	{
		name_ = "";
		price_ = 0;
	}
	Item(string name, int price)
	{
		name_ = name;
		price_ = price;
	}
	~Item()	{}

	string GetItemName() {
		return name_;
	}

	int GetItemPrice() {
		return price_;
	}

	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}


private:
	string name_;
	int price_;
};

template <typename T>
class Inventory {
public:
	Inventory(int capacity = 10)
	{
		pItems_ = new T[capacity];
		this->capacity_ = capacity;
		size_ = 0;
	}
	~Inventory() {
		delete[] pItems_;
	}

	void AddItem(T item) {
		if (size_ >= capacity_) {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
			return;
		}
		pItems_[size_++] = item;
	}

	void RemoeveLastItem() {
		if (size_ <= 0) {
			cout << "인벤토리가 비어있습니다." << endl;
		}
		size_--;
	}
	int GetSize() {
		return size_;
	}
	int GetCapacity() {
		return capacity_;
	}

	void PrintAllItems() {
		for (int i = 0; i < size_; i++) {
			pItems_[i].PrintInfo();
		}
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};

int main()
{
	Inventory<Item> inventory;

	for (int i = 0; i < 10; i++) {
		inventory.AddItem(Item("Hello Item" + to_string(i), 100));
	}
	inventory.RemoeveLastItem();
	inventory.PrintAllItems();
	return 0;
}