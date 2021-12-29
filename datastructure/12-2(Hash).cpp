#include <iostream>
#include <fstream>
using namespace std;

#define Hash_size 5 
typedef struct std_info
{
	 const char* no =NULL;
	 const char* name =NULL;
	 const char* tel =NULL;
}s_info;

struct std_info trash_table;

int Hash_function(const char* key);
std_info Sinfo_create(std_info student[Hash_size]);
std_info Sinfo_search(std_info student[Hash_size], const char* key);

int main()
{
	struct std_info student[Hash_size];
	struct std_info target_info;
	Sinfo_create(student);
	target_info = Sinfo_search(student, "100");
	cout << target_info.no << target_info.name << target_info.tel << endl ;


	return 0;
}

int Hash_function(const char* key) {
	int len = strlen(key);
	int sum = 0;
	for (int i = 0; i < len; i++) {
		sum = sum + key[i];
	}
	return sum % Hash_size;
}

std_info Sinfo_create(std_info student[Hash_size]) {
	int index;

	const char* raw_table[Hash_size][3] = { {"100","KIM","111"},{"128", "Hong","333"}, {"115","Jung","222"},
											{"218","Cha","444"},{"634","Park","666"} }; //txt 파일 대체

	for (int i = 0; i < Hash_size; i++) {
		student[i].no = NULL;
		student[i].name = NULL;
		student[i].tel = NULL;

		int haddr = Hash_function(raw_table[i][0]);
		index = haddr;
		while (student[index].no != NULL) {
			if (student[index].no = raw_table[i][0]) {
				cout << "duplicated key" << endl;
				return trash_table;
			}
			index = (index + 1) % Hash_size;
			if (index = haddr) {
				cout << "hash full" << endl;
				return trash_table;
			}
		}
		student[index].no = raw_table[i][0];
		student[index].name = raw_table[i][1];
		student[index].tel = raw_table[i][2];

	}
	return student[Hash_size];
}

std_info Sinfo_search(std_info student[Hash_size], const char* key)
{
	int haddr = Hash_function(key);
	int index = haddr;
	while (true) {
		if (student[index].no = key) {
			return student[index];
		}
		if (student[index].no = NULL) {
			break;
		}
		index = (index + 1) % Hash_size;
		if (index = haddr) {
			break;
		}
	}
	return trash_table;
}