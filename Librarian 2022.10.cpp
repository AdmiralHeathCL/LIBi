#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#include <list>
using namespace std;


class item
{
	public: string name;
	public: string item_type;

	bool Register;
};

class Book : public item
{
public:
	Book() { borrow_flag = false; }
	Book(string name, string num, string author)
		:name(name), num(num), author(author) {
		borrow_flag = false;
	} 
	void setReader(string reader, int lcn, string data); 
	void setInfo(string name, string num, string author); 
	string getName() {
		return name;
	}
	string getNum() { return num; }
	string getAuthor() {
		return author;
	}
	bool getBorrow_flag() {
		return borrow_flag;
	}
	string getReader() {
		return reader;
	}
	int getLcn() {
		return lcn;
	}
	string getData() {
		return data;
	}
	bool isBorrow() { return borrow_flag; }
	void setBorrow_flag(bool b) { borrow_flag = b; }
	void showInfo();
private:
	string name; 
	string num;
	string author;
	bool borrow_flag;
	string reader;
	int lcn;
	string data;
};


class Person
{
public:
	string Name;
	string Adress;
	list<item> Regist_items;
};



void Book::setReader(string reader, int lcn, string data)
{
	borrow_flag = true;
	this->reader.assign(reader);
	this->lcn = lcn;
	this->data.assign(data);
}
void Book::setInfo(string name, string num, string author)
{
	this->name.assign(name);
	this->num.assign(num);
	this->author.assign(author);
}
void Book::showInfo()
{
	cout << "�鼮���ƣ�" << setiosflags(ios_base::left) << setw(56) << name << endl
		 << "�鼮��ţ�" << setw(56) << num << endl
		 << "�鼮���ߣ�" << setw(56) << author << endl;
	if (borrow_flag)
	{
	   cout << "�鼮�������                                                      \n"
			<< "����������" << setw(56) << reader<< endl
			<< "����֤�ţ�" << setw(56) << lcn << endl
			<< "�������ڣ�" << setw(56) << data << endl;
	}
	else {
		cout << "�鼮δ�������                                                    \n";
	}
}
class Library
{
public:

	list<item> itemList;
	Library() { currentNum = 0; borrowNum = 0; }
	void addBook();
	void addBook(string name, string num, string author);
	void deleteBook();
	void borrowBook();
	void returnBook();
	void getReader();
	int indexOfNum(string num);
	vector<Book> getBooks() {
		return books;
	}
	void showInfo();
	int getTotalBooks() { return currentNum + borrowNum; }
private:
	vector<Book> books;
	map<string, int> readers;
	int currentNum;
	int borrowNum; 
};
void Library::showInfo()
{
	cout << "  ***************************����ͼ����Ϣ***************************\n\n";
	for (int i = 0; i < books.size(); i++)
	{
		cout << "��" << i + 1 << "���鼮����Ϣ��" << endl;
		books[i].showInfo();
	}
	system("pause");
	system("cls");
}
int Library::indexOfNum(string num)
{
	int i;
	for (i = 0; i < books.size(); i++)
	{
		if (books[i].getNum() == num)
			return i;
	}
	return -1;
}
void Library::addBook()
{
	Book b;
	int temp;
	string name, num, author;
	cout << "  *****************************���ӽ���*****************************\n\n";
	do {
		cout << "�����鼮���ƣ���ţ����ߣ�";
		cin >> name >> num >> author;
		b.setInfo(name, num, author);
		if (indexOfNum(num) == -1) {
			books.push_back(b);
			currentNum++;
			cout << "\n��ӳɹ���" << endl;
			cout << "����1��������,������һ������2��";
			cin >> temp;
		}
		else {
			cout << "�Ѵ��ڸñ�ŵ��鼮�����ʧ�ܡ�" << endl;
			cout << "����1������������,������һ������2��";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
void Library::addBook(string name, string num, string author)
{
	Book b;
	b.setInfo(name, num, author);
	books.push_back(b);
}
void Library::deleteBook()
{
	int index, temp;
	string num;
	cout << "  *****************************ɾ������*****************************\n\n";
	do {
		cout << "����Ҫɾ�����鼮�ı�ţ�";
		cin >> num;
		index = indexOfNum(num);
		if (index != -1) {
			if (!books[index].getBorrow_flag()) {
				cout << "ɾ�����鼮����Ϣ��\n";
				books[index].showInfo();
				books.erase(books.begin() + index);
				currentNum--;
				cout << "ɾ���ɹ���" << endl;
				cout << "����1��������ɾ��,������һ������2��";
				cin >> temp;
			}
			else {
				cout << "ɾ��ʧ�ܣ��鼮�Ѿ��������" << endl;
				cout << "����1��������ɾ��,������һ������2��";
				cin >> temp;
			}
		}
		else
		{
			cout << "ɾ��ʧ�ܡ�δ�ҵ����Ϊ" << num << "���鼮��\n";
			cout << "����1��������ɾ��,������һ������2��";
			cin >> temp;
		}
	} while (temp == 1);
	system("pause");
	system("cls");
}
void Library::borrowBook()
{
	string num;
	int index;
	cout << "  *****************************���Ľ���*****************************\n\n";
	cout << "����Ҫ���ĵ��鼮�ı�ţ�";
	cin >> num;
	index = indexOfNum(num);
	if (index != -1) {
		if (books[index].isBorrow()) {
			cout << "����ʧ�ܣ��鼮�Լ��������\n";
			system("pause");
			system("cls");
		}
		else
		{
			cout << "Ҫ����鼮����Ϣ��\n";
			books[index].showInfo();
			string reader, data;
			int lcn;
			cout << "�����������������֤�ţ��������ڣ�";
			cin >> reader >> lcn >> data;
			if (readers[reader] != 2) {
				books[index].setReader(reader, lcn, data);
				cout << "������ɡ�\n";
				currentNum--;
				borrowNum++;
				readers[reader]++;
				system("pause");
				system("cls");
			}
			else
			{
				cout << "����ʧ�ܣ��ö����Խ賬�������鼮��\n";
				system("pause");
				system("cls");
			}
		}
	}
	else
	{
		cout << "����ʧ�ܡ�δ�ҵ����Ϊ" << num << "���鼮.\n";
		system("pause");
		system("cls");
	}

}
void Library::returnBook()
{
	string num;
	cout << "  *****************************�������*****************************\n\n";
	cout << "����Ҫ�����鼮�ı�ţ�";
	cin >> num;
	int index;
	index = indexOfNum(num);
	if (index != -1)
	{
		cout << "Ҫ�����鼮����ϢΪ��\n";
		books[index].showInfo();
		books[index].setBorrow_flag(false);
		readers[books[index].getReader()]--;
		cout << "����ɹ���\n";
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����ʧ�ܣ������鼮����Ƿ��������\n";
		system("pause");
		system("cls");
	}
}
void Library::getReader()
{
	string num;
	cout << "  *****************************��ѯ����*****************************\n\n";
	cout << "����Ҫ���ҵ��鼮��ţ�";
	cin >> num;
	int index;
	index = indexOfNum(num);
	if (index != -1)
	{
		if (books[index].getBorrow_flag())
			cout << "����Ϊ��" << books[index].getReader() << endl;
		else {
			cout << "�޶��ߡ�" << endl;
		}
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѯʧ�ܣ������鼮����Ƿ��������\n";
		system("pause");
		system("cls");
	}
}
Library l;

void menu()
{
	int temp;
	
	while (1)
	{
		cout << "___________________________ ͼ��ݹ���ϵͳ____________________________\n";
	    cout << "                  ������������������������������                      \n";
		cout << "                  �� [0]�˳�ϵͳ��            ��                      \n";
		cout << "                  �� [1]����ͼ�顣            ��                      \n";
		cout << "                  �� [2]ɾ��ͼ�顣            ��                      \n";
		cout << "                  �� [3]����ͼ�顣            ��                      \n";
		cout << "                  �� [4]�黹ͼ�顣            ��                      \n";
		cout << "                  �� [5]��ʾͼ����Ϣ��        ��                      \n";
		cout << "                  �� [6]��ѯͼ�顣            ��                      \n";
		cout << "                  ������������������������������                      \n";
		cout << "����Ҫ���еĲ�����";
		cin >> temp;
		switch (temp) {
		case 1:
			system("cls");
			l.addBook(); 
			break;
		case 2:system("cls");
			l.deleteBook(); 
			break;
		case 3:system("cls");
			l.borrowBook(); 
			break;
		case 4:system("cls");
			l.returnBook(); 
			break;
		case 5:system("cls");
			l.showInfo();
			break;
		case 6:system("cls");
			l.getReader();
			break;
		case 0:
			
			exit(1);
			break;
		default:
			cout << "�������" << endl;
			system("pause");
			system("cls");
		}
	}
}
int main()
{
	menu();
	return 0;
}

	

