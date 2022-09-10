#pragma
#include <iostream>

using namespace std;

class Array {
	protected:
		int* data, size, capacity;
		
	public:
		Array(int user_capacity) {
			capacity = user_capacity;
			size = 0;
			data = new int[capacity];
			cout << "Array is created with capacity : " << capacity << endl;
		}
		~Array() {
			delete data;
			cout << "Array destroyed." << endl;
		}
		Array(const Array& copyArray) {
			capacity = copyArray.capacity;
			size = copyArray.size;
			data = new int[capacity];
			for (int i = 0; i < copyArray.size; i++) {
				data[i] = copyArray.data[i];
			}
			cout << "Array copied to target." << endl;
		}
		int getSize() const {
			return size;
		}
		int getCapacity() const {
			return capacity;
		}
		void addItem1(int number) {
			if (size == capacity) {
				int* temp_data = new int[capacity * 2];
				for (int i = 0; i < size; i++)
					temp_data[i] = data[i];
				delete[] data;
				data = temp_data;
				capacity *= 2;
			}

			data[size] = number;
			size++;
		}
		void printItems() {
			if (size != 0) {
				for (int i = 0; i < size; i++) {
					cout << (i != 0 ? " - " : "") << data[i];
				}
			}
			cout << "\n" << "capacity : " << capacity << " size : " << size << endl;
		}
		void removeIndexItem(int index) {
			if (index < 0 || index >= size) {
				cout << "ERROR! No item at the index : " << index << endl;
				return;
			}
			int removeItem = data[index];
			for (int i = index; i < size; i++) {
				data[i] = data[i + 1];
			}
			size -= 1;
			cout << "Item " << removeItem << " is deleted." << endl;
		}
		void removeItem(int number) {
			int counter = 0;
			for (int i = 0; i < size; i++) {
				if (data[i] == number) {
					for (int j = i; j < size; j++) {
						data[j] = data[j + 1];
					}
					counter++;
					i--;
				}
			}
			size -= counter;
			if (counter == 0) {
				cout << "The array has no items (" << number << ").";
			}
			else {
				cout << "Items (" << number << ")" << " are deleted from the array." << endl;
			}
		}

		int findIndex(int number, int index = 0) {
			for (int i = index; i < size; i++) {
				if (data[i] == number)
					return i;
			}
			return -1;
		}

		void findElement(int number, int index) {
			int result = findIndex(number, index);
			if (result != -1)
				cout << number << " found at index " << result << endl;
			else
				cout << number << " didn't found in the array." << endl;
		}
		

};



class unsortedArray : public Array {
	public:
		unsortedArray(int user_capacity = 5) : Array(user_capacity) {}
		unsortedArray(const unsortedArray& oth) : Array(oth) {}
		void printItems() {
			cout << "Unsorted Array : " ;
			Array::printItems(); 
		}
};

class sortedArray : public Array {
	public:
		sortedArray(int user_capacity = 5) :Array(user_capacity){}
		sortedArray(const sortedArray& oth):Array(oth){}

		void  addItem1(int number) {
			int i;
			if (capacity == size) {
				int* temp_data = new int[capacity * 2];
				for (int i = 0; i < size; i++) {
					temp_data[i] = data[i];
				}
				delete[] data;
				data = temp_data;
				capacity *= 2;
			}
			for (i = size - 1; (i >= 0 && data[i]>number); i--) {
				data[i + 1] = data[i];
			}
			data[i + 1] = number;
			size++;
		}
		void printItems() {
			cout << "Sorted Array : " ;
			Array::printItems();
		}
};














