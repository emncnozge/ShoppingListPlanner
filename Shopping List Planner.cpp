#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
	vector < vector < string >> productName;
	productName.resize(10000);
	vector < vector < string >> productAmount;
	productAmount.resize(10000);
	string name;
	string amount;
	int list_count = -1;
	int item_counter[10000] = {
	  0
	};
	int currlist = 0;
	string Ans = "-1";
	int y = 0;
	unsigned char hx = 205;
	unsigned char hc = 201;
	unsigned char hb = 186;
	unsigned char ha = 187;
	unsigned char hz = 188;
	unsigned char hy = 200;
	unsigned char mz = 196;
	while (Ans != "0") {
		//MAIN MENU
		cout << hc;
		for (int i = 0; i < 85; i++) {
			cout << hx;
		}
		cout << ha;
		cout << endl;
		cout << hb << "                                    SHOPPING LIST                                    " << hb << endl;
		cout << hy;
		for (int i = 0; i < 85; i++) {
			cout << hx;
		}
		cout << hz;
		cout << "\n  -List Operations\n";
		for (int i = 0; i < 23; i++) {
			cout << mz;
		}
		cout << "\n 1- Create new list. (At the beginning there is no list, you need to create it first.)\n" <<
			" 2- Delete a list.\n" <<
			" 3- Change your list. (Go to another list.)\n" <<
			" 4- Show your current list.(Shows all of the products.)\n\n  -Product Operations\n";
		for (int i = 0; i < 23; i++) {
			cout << mz;
		}
		cout << "\n 5- Add product to your list.\n" <<
			" 6- Delete a product from your list.\n" <<
			" 7- Edit a product.\n" <<
			" 8- Mark or unmark a product.(Marked products will be shown with \"(*)\".)\n" <<
			" 9- Exit.\n" <<
			" NOTE: FOR SELECTIONS USE ONLY NUMBERS!";
		cout << "\n\nPlease enter your choice: ";
		cin >> Ans;
		system("cls");
		cout << "_______________________________________________________________________" << endl;
		//NEW LIST CREATION
		if (Ans == "1") {
			list_count++;
			currlist = list_count;
			cout << "New list succesfully created. You are editing the new list now.";
			cout << endl << "_______________________________________________________________________" << endl;
		}
		//EXISTING LIST DELETION
		else if (Ans == "2") {
			system("cls");
			if (list_count == -1) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no list to delete.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				cout << "\nWhich list do you want to delete?\n";
				for (int i = 0; i < list_count + 1; i++)
					cout << i + 1 << "- " << endl << endl;
				cout << list_count + 2 << "- Go back\n\n";
				cout << "Answer: ";
				int opr;
				cin >> opr;
				if (opr == list_count + 2) {
					system("cls");
					continue;
				}
				else {
					productName.erase(productName.begin() + opr - 1);
					productAmount.erase(productAmount.begin() + opr - 1);
					system("cls");
					cout  << "_______________________________________________________________________" << endl;
					cout << "List " << opr << " successfully deleted.\n";
					cout << "_______________________________________________________________________" << endl;
					for (int i = opr - 1; i < list_count - opr + 2; i++)
						item_counter[i] = item_counter[i + 1];

					if (opr - 1 < currlist) {
						currlist--;
						list_count--;
					}
					else if (opr - 1 > currlist)
						list_count--;
					else if (opr - 1 == currlist) {

						currlist = 0;
						list_count--;
						if (list_count != -1) {
							system("cls");
							cout << endl << "_______________________________________________________________________" << endl << "Now you are editing the 1st list.";
							cout << endl << "_______________________________________________________________________" << endl;
						}
					}

					if (list_count == -1) {
						list_count++;
						cout << "\nNo list left.\n\nDo you want to create a new one?\n\n1- Yes\n\n2- No (You will be directed to main menu.)\n\nAnswer: ";
						int hy;
						cin >> hy;
						if (hy == 1) {
							system("cls");
							cout << endl << "_______________________________________________________________________" << endl;
							list_count++;
							cout << "New list successfully created. You are editing the new list now.\n";
						}
						else if (hy == 2)
							system("cls");
						cout << "_______________________________________________________________________" << endl;
					}
				}
			}
		}
		//CHANGING YOUR CURRENT LIST
		else if (Ans == "3") {
			if (list_count == -1) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no list to change.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else if (list_count == 0) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no list to change. You only have 1 list.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				int a;
				system("cls");
				cout << "_______________________________________________________________________";
				cout << endl << "Which list do you want?\n\n";
				for (int i = 0; i < list_count + 1; i++)
					cout << i + 1 << "- " << endl << endl;
				cout << list_count + 2 << "- Go back\n\nAnswer: ";
				cin >> a;
				if (a == list_count + 2) {
					system("cls");
					continue;
				}
				currlist = a - 1;
				system("cls");
				cout << "List successfully changed. Now you are editing list " << a << ".";
				cout << endl << "_______________________________________________________________________" << endl << endl;
			}
		}
		//PRINTING YOUR CURRENT LIST
		else if (Ans == "4") {
			if (list_count == -1) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no list to show.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				if (item_counter[currlist] == 0) {
					system("cls");
					cout << endl << "_______________________________________________________________________" << endl;
					cout << "Your list is empty.";
					cout << endl << "_______________________________________________________________________" << endl << endl;
				}
				else {
					system("cls");
					cout << endl << "_______________________________________________________________________" << endl << endl;
					for (int i = 0; i < item_counter[currlist]; i++)
						cout << i + 1 << "- " << "Product: " << productName[currlist][i] << "  " << "Amount: " << productAmount[currlist][i] << endl << endl;
					if (item_counter[currlist] == 1) {
						cout << "_______________________________________________________________________" << endl << endl;
						cout << "You have " << item_counter[currlist] << " product in your list.\n\n";
					}
					else {
						cout << "_______________________________________________________________________" << endl << endl;
						cout << "You have " << item_counter[currlist] << " products in your list.\n\n";
					}
					cout << "_______________________________________________________________________" << endl;
				}
			}
		}
		//ADDING PRODUCTS TO YOUR CURRENT LIST
		else if (Ans == "5") {
			if (list_count == -1) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no list to add products.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				int af = 0;
				system("cls");
				cout << "\nDo you want to add product more than one?\n\n1- Yes\n\n2- No\n\n3- Go back.";
				cout << "\n\nAnswer: ";
				cin >> af;
				if (af == 3) {
					system("cls");
					continue;
				}
				else if (af == 2) {
					system("cls");
					cout << "\nPlease enter the name of the product: ";
					cin.ignore();
					getline(cin, name);
					cout << "Please enter the amount of the product: ";
					cin >> amount;
					cout << endl;

					productName[currlist].push_back(name);
					productAmount[currlist].push_back(amount);
					system("cls");
					cout << endl << "_______________________________________________________________________" << endl;
					cout << " " << amount << " x " << name << " succesfully added to your list.";
					item_counter[currlist] = item_counter[currlist] + 1;
					cout << endl << "_______________________________________________________________________" << endl;
				}
				else if (af == 1) {
					system("cls");
				tck:
					while (name != "0") {
						cout << "\nPlease enter the name of the product(To exit press 0): ";
						cin.ignore();
						getline(cin, name);

						if (name == "0") {
							system("cls");
							goto tck;
						}
						cout << "Please enter the amount of the product: ";
						cin >> amount;
						cout << endl;
						system("cls");
						cout << endl << "_______________________________________________________________________" << endl;
						cout << " " << amount << " x " << name << " succesfully added to your list.";
						item_counter[currlist] = item_counter[currlist] + 1;
						cout << endl << "_______________________________________________________________________" << endl;

						productName[currlist].push_back(name);
						productAmount[currlist].push_back(amount);
					}
					name = "";
				}
				else {
					system("cls");
					cout << "_______________________________________________________________________" << endl;
					cout << "\nWrong input, please try again.\n\n";
					cout << "_______________________________________________________________________" << endl;
				}
			}
		}
		//DELETING PRODUCTS FROM YOUR CURRENT LIST
		else if (Ans == "6") {
			if (item_counter[currlist] == 0) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no product to delete.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				system("cls");
				cout << "\nWhich product do you want to delete?\n\n";
				int po = 0;
				for (int i = 0; i < item_counter[currlist]; i++) {
					po = i + 1;
					cout << i + 1 << "- " << "Product: " << productName[currlist][i] << "  " << "Amount: " << productAmount[currlist][i] << endl << endl;
				}
				int x = 0;
				cout << po + 1 << "- Go back\n\n";
				cout << "Answer: ";
				cin >> x;
				if (x == po + 1) {
					system("cls");
					continue;
				}
				system("cls");
				cout << endl << "_______________________________________________________________________" << endl;
				cout << productName[currlist][x - 1] << " successfully deleted from your list.";
				productName[currlist].erase(productName[currlist].begin() + x - 1);
				productAmount[currlist].erase(productAmount[currlist].begin() + x - 1);
				item_counter[currlist]--;
				cout << "\n_______________________________________________________________________" << endl;
			}
		}
		//EDITING YOUR PRODUCT'S NAME AND AMOUNT
		else if (Ans == "7") {
			if (item_counter[currlist] == 0) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no product to edit.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				int fr = 0;
				system("cls");
				cout << "\nWhich product do you want to edit?\n\n";
				for (int i = 0; i < item_counter[currlist]; i++)
				{
					cout << i + 1 << "- " << "Product: " << productName[currlist][i] << "  " << "Amount: " << productAmount[currlist][i] << endl << endl;
					fr = i + 1;
				}
				cout << fr + 1 << "- " << "Go back\n\n";
				int sth;
				cout << "Answer: ";
				cin >> sth;
				system("cls");
				if (sth == fr + 1)
					continue;
				cout << "\nYour selection:" << endl << "________________________________________\n" << "Product: " << productName[currlist][sth - 1] << "  " << "Amount: " << productAmount[currlist][sth - 1] << endl;
				cout << "________________________________________\n";
				cout << "\nWhich one do you want to edit?\n\n1-Product name\n\n2-Amount of product\n\n3-Go back \n\n";
				int c;
				cout << "Answer: ";
				cin >> c;
				system("cls");
				if (c == 3) {
					system("cls");
					continue;
				}
				if (c == 1) {
					cout << "\n\nPlease enter the new name of product: ";
					cin.ignore();
					getline(cin, name);
					productName[currlist][sth - 1] = name;
					system("cls");
					cout << endl << "_______________________________________________________________________";
					cout << "\nName of the product successfully changed.";
				}
				else if (c == 2) {
					cout << "\n\nPlease enter the new amount of product: ";
					string newamount;
					cin >> newamount;
					productAmount[currlist][sth - 1] = newamount;
					system("cls");
					cout << endl << "_______________________________________________________________________";
					cout << "\nAmount of the product successfully changed.";
				}
			}
			cout << endl << "_______________________________________________________________________" << endl;
		}
		//MARKING A PRODUCT WITH (*) OR UNMARKING
		else if (Ans == "8") {
			if (item_counter[currlist] == 0) {
				system("cls");
				cout << "_______________________________________________________________________" << endl;
				cout << "There is no product to mark or unmark.\n";
				cout << "_______________________________________________________________________" << endl;
				continue;
			}
			else {
				system("cls");
				int xj;
				cout << "Which one do you want to do?\n\n1- Mark a product.\n\n2- Unmark a product.\n\n3- Go back\n\nAnswer: ";
				cin >> xj;
				system("cls");

				if (xj == 3) {
					continue;
				}
				else if (xj == 1) {

					cout << "\nWhich product do you want to mark?\n\n";
					for (int i = 0; i < item_counter[currlist]; i++)
						cout << i + 1 << "- " << "Product: " << productName[currlist][i] << "  " << "Amount: " << productAmount[currlist][i] << endl << endl;

					cout << "Answer: ";
					cin >> y;
					if (productAmount[currlist][y - 1].back() != ')') {
						productAmount[currlist][y - 1].push_back(' ');
						productAmount[currlist][y - 1].push_back('(');
						productAmount[currlist][y - 1].push_back('*');
						productAmount[currlist][y - 1].push_back(')');
						system("cls");
						cout << endl << "_______________________________________________________________________";
						cout << endl << productName[currlist][y - 1] << " successfully marked.";
						cout << endl << "_______________________________________________________________________" << endl << endl;
					}
					else {
						system("cls");
						cout << endl << "_______________________________________________________________________";
						cout << "\nThis product is already marked.";
						cout << endl << "_______________________________________________________________________" << endl << endl;
					}
				}
				else if (xj == 2) {
					cout << "\nWhich product do you want to unmark?\n\n";

					for (int i = 0; i < item_counter[currlist]; i++)
						cout << i + 1 << "- " << "Product: " << productName[currlist][i] << "  " << "Amount: " << productAmount[currlist][i] << endl << endl;
					int u;
					cout << "Answer: ";
					cin >> u;
					if (productAmount[currlist][u - 1].back() == ')') {
						productAmount[currlist][u - 1].pop_back();
						productAmount[currlist][u - 1].pop_back();
						productAmount[currlist][u - 1].pop_back();
						productAmount[currlist][u - 1].pop_back();
						system("cls");
						cout << endl << "_______________________________________________________________________";
						cout << endl << productName[currlist][u - 1] << " successfully unmarked.";
						cout << endl << "_______________________________________________________________________" << endl << endl;
					}
					else {
						system("cls");
						cout << endl << "_______________________________________________________________________";
						cout << "\nThis product is already unmarked.";
						cout << endl << "_______________________________________________________________________" << endl << endl;
					}
				}
			}
		}
		//CLOSING THE PROGRAM
		else if (Ans == "9") {
			break;
		}
		else {
			system("cls");
			cout << "_______________________________________________________________________" << endl;
			cout << "Wrong input. Please try again.";
			cout << endl << "_______________________________________________________________________" << endl;
		}
	}
	return 0;
}