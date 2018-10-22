#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>

using namespace std;

template <class T>
class list
{
public:
	T val;
	list *next;
	list(T v) : val(v), next(NULL) {}
	list *add(list *pre, list *current, T v);
	list *del(list *pre, list *current, T v);
	void disp(list *current);
};

template <class T>
list<T> *list<T>::add(list *pre, list *current, T v)
{
	list *head = current;
	list *temp;
	while (1)
	{
		if (current == NULL || current->val > v)
		{
			temp = new list(v);
			if (pre != NULL)
			{
				pre->next = temp;
			}
			else
			{
				head = temp;
			}
			temp->next = current;
			break;
		}
		else
		{
			pre = current;
			current = current->next;
		}
	}
	return head;
}

template <class T>
list<T> *list<T>::del(list *pre, list *current, T v)
{
	list *root = current;
	while (1)
	{
		if (current->val == v)
		{
			if (pre == NULL)
			{
				root = current->next;
			}
			else
			{
				pre->next = current->next;
			}
			break;
		}
		else
		{
			pre = current;
			current = current->next;
		}
	}
	return root;
}

template <class T>
void list<T>::disp(list *current)
{
	int id = 0;
	while (current != NULL)
	{
		if (id)
		{
			cout << "\t";
		}
		cout << current->val;
		id += 1;
		current = current->next;
	}
	cout << endl;
}

int main()
{
	string line;
	while (getline(cin, line))
	{
		char *p = strtok(const_cast<char *>(line.c_str()), ", ");
		list<int> *root = NULL;
		while (p != NULL)
		{
			root = root->add(NULL, root, stoi(p));
			p = strtok(NULL, ", ");
		}
		cout << "请输入一个要求删除的整数" << endl;
		getline(cin, line);
		root = root->del(NULL, root, stoi(line));
		root->disp(root);

		cout << "请输入一个要求插入的整数" << endl;
		getline(cin, line);
		root = root->add(NULL, root, stoi(line));
		root->disp(root);
		break;
	}
	return 0;
}