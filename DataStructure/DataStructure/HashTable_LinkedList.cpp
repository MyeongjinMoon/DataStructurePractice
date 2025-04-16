#include "header.h"

#define HASH_VALUE 13

struct List
{
	int key;
	char name[20];
	List* prev = nullptr;
	List* next = nullptr;
};

void HashTable_LinkedList();

//int main()
//{
//	HashTable_LinkedList();
//}

int FindHashIndex(int);
int CheckCount(List**, int);
void AddList(List**, int);
void DeleteList(List**, int);
void SearchList(List**, int);
void AllPrintList(List**);

void HashTable_LinkedList()
{
	List** hashTable = new List * [HASH_VALUE];
	for (int i = 0; i < HASH_VALUE; i++)
		hashTable[i] = nullptr;

	while (1)
	{
		cout << "(1) ���� (2) ���� (3) �˻� (4) ��� (0) ���� : ";

		int btn, key;
		cin >> btn;

		switch (btn)
		{
		case 0:
			return;

		case 1:
			cout << "������ key�� �Է����ּ��� : ";
			cin >> key;

			AddList(hashTable, key);
			break;

		case 2:
			cout << "������ key�� �Է����ּ��� : ";
			cin >> key;

			DeleteList(hashTable, key);
			break;

		case 3:
			cout << "�˻��� key�� �Է����ּ��� : ";
			cin >> key;

			SearchList(hashTable, key);
			break;

		case 4:
			AllPrintList(hashTable);

			break;
		}

		cout << "\n";
	}
}
int FindHashIndex(int hashKey)
{
	if (hashKey < 0)
		return -1;

	return hashKey % HASH_VALUE;
}
void AddList(List** hashTable, int key)
{
	int hashKey = FindHashIndex(key);
	if (hashKey == -1)
		return;

	List* curList = hashTable[hashKey];
	List* newList = new List;

	while (curList != nullptr && curList->next != nullptr)
	{
		if (curList->key == key)
		{
			cout << "�ش� key ���� �̹� �����մϴ�.";
			return;
		}

		curList = curList->next;
	}

	cout << "������ value�� �Է����ּ��� : ";
	cin >> newList->name;
	newList->key = key;

	if (curList != nullptr)
	{
		curList->next = newList;
		newList->prev = curList;
	}
	else
	{
		curList = newList;
		hashTable[hashKey] = curList;
	}
}
void DeleteList(List** hashTable, int key)
{
	int hashKey = FindHashIndex(key);
	if (hashKey == -1)
	{
		cout << "�ش� key�� �������� �ʽ��ϴ�.";
		return;
	}

	List* curList = hashTable[hashKey];

	while (curList != nullptr && curList->key != key)
		curList = curList->next;

	if (curList == nullptr)
		cout << "�ش� key�� �������� �ʽ��ϴ�.";
	else
	{
		cout << "Key : " << curList->key << " �����Ͱ� �����Ǿ����ϴ�.\n";

		if (curList->prev != nullptr)
			curList->prev->next = curList->next;

		if (curList->next != nullptr)
			curList->next->prev = curList->prev;

		if (curList == hashTable[hashKey])
			hashTable[hashKey] = curList->next;

		delete curList;
	}
}
void SearchList(List** hashTable, int key)
{
	int hashKey = FindHashIndex(key);
	if (hashKey == -1)
	{
		cout << "�ش� key�� �������� �ʽ��ϴ�.";
		return;
	}

	List* curList = hashTable[hashKey];

	while (curList != nullptr && curList->key != key)
		curList = curList->next;

	if (curList == nullptr)
		cout << "�ش� key�� �������� �ʽ��ϴ�.";
	else
	{
		cout << "Key : " << curList->key << " Value : " << curList->name << '\n';
	}
}
void AllPrintList(List** hashTable)
{
	for (int i = 0; i < HASH_VALUE; i++)
	{
		List* curList = hashTable[i];
		cout << i << "��° :";
		while (curList != nullptr && curList->key >= 0)
		{
			cout << " " << curList->name;
			curList = curList->next;
		}
		cout << '\n';
	}
}
int CheckCount(List** hashTable, int hashKey)
{
	List* curList = hashTable[hashKey];

	int count = 1;
	while (curList != nullptr && curList->next != nullptr)
	{
		curList = curList->next;
		count++;
	}

	cout << "\nHashKey - " << hashKey << "��°�� ����� Size�� " << count + 1 << '\n';

	return count + 1;
}