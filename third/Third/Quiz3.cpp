#include <iostream>
#include <string>
#include <algorithm>
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

	const string& GetItemName() const{
		return name_;
	}

	int GetItemPrice() const{
		return price_;
	}

	void PrintInfo() const {
		cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
	}


private:
	string name_;
	int price_;
};

bool compareItemsByPrice(const Item& a, const Item& b) {
	return a.GetItemPrice() < b.GetItemPrice();
}

template <typename T>
class Inventory {
public:
	Inventory(int capacity = 10)
	{
		pItems_ = new T[capacity];
		this->capacity_ = capacity;
		size_ = 0;
	}

	Inventory(const Inventory<T>& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];
		for (int i = 0; i < size_; ++i) {
			pItems_[i] = other.pItems_[i];
		}
		std::cout << "인벤토리 복사 완료" << std::endl;
	}

	~Inventory() {
		delete[] pItems_;
	}

	void AddItem(T item) {
		if (size_ >= capacity_) {
			cout << "인벤토리가 꽉 찼습니다!" << endl;
			int newCap = (capacity_ <= 0) ? 1 : capacity_ * 2;
			Resize(newCap);
		}
		pItems_[size_++] = item;
	}

	void RemoeveLastItem() {
		if (size_ <= 0) {
			cout << "인벤토리가 비어있습니다." << endl;
			return;
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
		if (size_ == 0) {
			cout << "(비어있음)" << endl;
			return;
		}
		for (int i = 0; i <= size_-1; i++) {
			pItems_[i].PrintInfo();
		}
	}

	void Resize(int newCapacity) {
		if (newCapacity <= 0) return;
		if (newCapacity == capacity_) return;

		T* newItems = new T[newCapacity]{};

		for (int i = 0; i < size_; ++i) {
			newItems[i] = pItems_[i];
		}

		delete[] pItems_;

		pItems_ = newItems;
		capacity_ = newCapacity;
	}

	void SortItems() {
		sort(pItems_, pItems_ + size_, compareItemsByPrice);
	}

private:
	T* pItems_;
	int capacity_;
	int size_;
};

int main()
{
	Inventory<Item>* itemInventory = new Inventory<Item>();
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->Resize(25);
	for (int i = 0; i < 14; ++i)
	{
		itemInventory->AddItem(Item("Item" + std::to_string(i), i * 100));
	}

	itemInventory->PrintAllItems();
	std::cout << "ItemCapacity : " << itemInventory->GetCapacity() << std::endl;

	itemInventory->SortItems();
	itemInventory->PrintAllItems();

	Inventory<Item>* itemInventory2 = new Inventory<Item>(*itemInventory);
	itemInventory2->PrintAllItems();

	delete itemInventory;
	delete itemInventory2;
	return 0;
}