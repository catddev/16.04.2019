#include"Vector.h"

int main() {

	ifstream in_file("in.txt");
	//Array arr[6];
	Vector v;
	Array arr;
	Array amount;
	Array difference;

	bool f = false, f2 = false;
	int i = 0;
	while (true) {
		int choice;
		cout << " Enter 1 to read marks from file" << endl;
		cout << " Enter 2 to get marks randomly" << endl;
		cout << " Enter 3 to find student with the best marks" << endl;
		cout << " Enter 4 to find the students with the worst marks" << endl;
		cout << " Enter 5 to print out the month when each student got the best mark" << endl;
		cout << " Enter 6 to print out the month when each student got the worst mark" << endl;
		cout << " Enter 7 to record the amount of marks of each student" << endl;
		cout << " Enter 8 to record the difference between marks of the best and the worst student" << endl;
		cout << " Enter 9 to print out info about all students" << endl;
		cout << " Enter 0 to exit" << endl;
		cin >> choice;
		if (choice == 0) break;
		switch (choice)
		{
		case 1:
			while (!in_file.eof()) {
				
				in_file >> arr;
				v.push_back(arr);
			}

			for (int i = 0; i < v.size()-1; i++) //? -1
				cout << v[i] << endl;
			break;
		case 2:
			for (int i = 0; i < 6; i++)//why the same
			{
				v[i]=arr.random();
				cout << v[i] << endl;
			}
			break;
		case 3:
			for (int i = 0; i < 6; i++)
			{
				f = false;
				for (int j = i+1; j < 6; j++)//?
				{
					if (arr[i] > arr[j]) f = true;
				}
				if (f==true) cout << arr[i];
			}
			break;
		case 4:
			for (int i = 0; i < 6; i++)
			{
				f = false;
				for (int j = i+1; j < 6; j++)
				{
					if (arr[i] < arr[j]) f = true;
				}
				if (f) cout << arr[i];
			}
			break;
		case 5:
			for (int i = 0; i < 6; i++)
				if (arr[i] == arr.max_el())//[i]
					cout << i << endl;
			break;
		case 6:
			for (int i = 0; i < 6; i++)
				if (arr[i] == arr.min_el())//
					cout << i << endl;
			break;
		case 7:
				for (int i = 0; i < 6; i++)
					amount += arr[i]; //???
			break;
		case 8:
			int a, b;
			for (int i = 0; i < 6; i++)
			{
				f = false, f2 = false;
				for (int j = i+1; j < 6; j++)
				{
					if (arr[i] > arr[j]) f = true;
					if (arr[i] < arr[j]) f2 = true;
				}
				if (f) a = i;
				if (f2) b = i;
			}

			difference = arr[a] - arr[b]; //OR ?????????

			break;
		case 9:
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			cout << endl;
			break;
	}
	}

	system("pause");
	return 0;
}