#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class LinkedList {

	struct Node {
		int value;
		Node *next;
		Node *prev;
	};

	private:
		Node *head, *tail;
		int size;

	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}

		void addToTail(int newNodeValue) {
			Node *n = new Node();
			n->value = newNodeValue;

			if (head == NULL && tail == NULL)
			{
				n->prev = NULL;
				head = n;
				tail = n;
			}
			else {
				n->prev = tail;
				tail->next = n;
				tail = n;
			}
			
			tail->next = NULL;

			size++;
		}

		void addToHead(int newNodeValue) {
			Node *n = new Node();
			n->value = newNodeValue;

			if (head == NULL && tail == NULL)
			{
				n->next = NULL;
				head = n;
				tail = n;
			}
			else {
				n->next = head;
				head->prev = n;
				head = n;
			}

			head->prev = NULL;

			size++;
		}

		int GetAtIndex(int index) {
			Node* temp = head;

			for (size_t i = 0; i < index; i++)
			{
				
				temp = temp->next;
			}
			//cout << "prev: " << temp->prev << ", current:" << temp << ", next:" << temp->next << endl;
			return temp->value;
		}
};

int main(int argc, char** argv) {

	LinkedList linkedList;
	linkedList.addToTail(1);
	linkedList.addToTail(2);
	linkedList.addToTail(3);
	linkedList.addToHead(243);
	cout << "NULL -> ";
	for (size_t i = 0; i < 4; i++)
	{
		cout << linkedList.GetAtIndex(i) << " -> ";
	}
	cout << " NULL";

	std::getchar(); // so the window doesn't close immediately
	return 0;
}