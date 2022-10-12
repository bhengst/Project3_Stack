/*
* Project 3 Data Structures
*
* Name: Brittany Hengst
*/

#include <iostream>
#include <cmath>

using namespace std;

/*
* This class represents a stack.
*/
template <class Type>
class MyStack {
private:
	int maxStackSize;
	int stackTop;
	Type* list;
	void copyStack(const MyStack<Type>&);
public:
	/*
	* Default constructor, sets the list size, max stack size and stack top
	*/
	MyStack(int mySize = 100) {
		list = new int[mySize];
		maxStackSize = mySize;
		stackTop = 0;
	}

	/*
	* Constructor for copying a stack
	*/
	MyStack(const MyStack<Type>& theStack) {
		copyStack(theStack);
	}

	/*
	* Destructor
	*/
	~MyStack() {
		delete[] list;
	}

	void initializeStack();
	bool isEmptyStack() const;
	bool isFullStack() const;

	Type push(const Type& newItem);
	Type top() const;
	void pop();

	/*
	* Changing the equals operator
	*/
	const MyStack<Type>& operator= (const MyStack<Type>& theStack) {
		copyStack(theStack);
		return *(this);
	}

	/*
	* Prints what is in the stack
	*/
	void print() {
		for (int i = 0; i < stackTop; i++) {
			cout << list[i] << " ";
		}
		cout << endl;
	}
};

/*
* Checks to see if stack is empty
* @returns boolean
*/
template<class Type>
bool MyStack<Type>::isEmptyStack() const {
	return (stackTop == 0);
}

/*
* Checks to see if stack is full
* @returns boolean
*/
template<class Type>
bool MyStack<Type>::isFullStack() const {
	return (stackTop == maxStackSize);
}

/*
* Adds a value to the top of the stack
* @returns Type
* @param Type newItem
*/
template<class Type>
Type MyStack<Type>::push(const Type& newItem) {
	if (isFullStack()) {
		return NULL;
	}
	list[stackTop] = newItem;
	stackTop++;
	return list[stackTop - 1];
}

/*
* Finds the value at the top of the stack and returns it
* @returns Type
*/
template<class Type>
Type MyStack<Type>::top() const {
	if (isEmptyStack()) {
		return NULL;
	}
	return list[stackTop - 1];
}

/*
* Deletes the top value off the stack
*/
template<class Type>
void MyStack<Type>::pop() {
	if (!isEmptyStack()) {
		stackTop--;
	}
}

/*
* Copies the stack that is passed by parameter
* @param MyStack theStack
*/
template<class Type>
void MyStack<Type>::copyStack(const MyStack<Type>& theStack) {
	delete[] list;
	list = new Type[theStack.maxStackSize];

	for (int i = 0; i < theStack.maxStackSize; i++) {
		list[i] = theStack.list[i];
	}

	stackTop = theStack.stackTop;
	maxStackSize = theStack.maxStackSize;
}

/*
* Converts a binary number to decimal value, returns the converted value
* @returns int
* @param int num
*/
int convertBinaryToDecimal(long num) {
	MyStack<int> theStack;

	long decimalNum = 0;
	int remain, i = 0, temp;

	while (num != 0) {
		remain = num % 10;
		num = num / 10;

		temp = remain * pow(2, i);

		theStack.push(temp);
		++i;
	}

	int j = 0;
	while (!theStack.isEmptyStack()) {
		j = j + theStack.top();
		theStack.pop();
	}

	decimalNum = j;

	return decimalNum;
}

/*
* The main function
*/
int main() {
	long num;
	long decNum;

	/*
	* While the user does not enter -999, keep asking for a number to be
	* converted
	* When -999 is entered exit program
	*/
	do {
		cout << "-999 to stop, enter a binary number: " << endl;
		cin >> num;
		if (num != -999) {
			decNum = convertBinaryToDecimal(num);
			cout << "The equivalent decimal num is: " << decNum << endl;
		}
	} while (num != -999);

	return 0;
}