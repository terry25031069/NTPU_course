#include<regex>
#include<time.h>
#include"card.h"
#include<string>
#include<cctype>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

bool pokayoke(string s, int _begin, int _end) {
	int flag = 0;
	for (int i = 0; i < s.size(); i++) {
		if (!isdigit(s[i])) {
			cout << "��J���~�A�Э��s��J\n";
			return 0;
		}
	}
	int num = stoi(s);
	if (num > _end || num < _begin) {
		cout << "��J���~�A�Э��s��J\n";
		return 0;
	}
	return 1;
}

int main() {
	string num, sor1, line, sor2, check;
	int pointer = 0;
yee: {};
	srand(time(NULL));
	int flag = 0, a[100] = {};
	for (int i = 0; i < 52; i++)a[i] = i;
	random_shuffle(a, a + 52, [](int i) {return rand() % i; });
	pointer = 0;
	while (1) {
		if (52 - pointer > 0) {
			cout << "-------------------------------------------------------------------\n";
			cout << "| �п�J���J�P�`�i�ơA��J�����Ы�Enter��G                       |\n";
			cout << "| �]�`�N�G�ȯ��J1-";
			cout << 52 - pointer;
			if (52 - pointer < 10)cout << ' ';
			cout << "�^";
			cout << "                                          |\n";
			cout << "-------------------------------------------------------------------\n";
		}
		else {
			cout << "-------------------------------------------------------------------\n";
			cout << "| �w�g�S���P�i�H�o�FQQ                                            |\n";
			cout << "| �Q�}�@�Ʒs�����J�P�A�п�J1�����Enter��A��J0�����{��         |\n";
			cout << "-------------------------------------------------------------------\n";
			while (getline(cin, check)) {
				if ((pokayoke(check, 0, 1) == 1))break;
			}
			if (check == "0")break;
			else goto yee;
		}
		while (getline(cin, num)) {
			if ((pokayoke(num, 1, 52 - pointer) == 1))break;
		}
		cout << "-------------------------------------------------------------------\n";
		cout << "| �п�J���J�P�C��i�ơA��J�����Ы�Enter��G                     |\n";
		cout << "| �]�`�N�G�ȯ��J1-7�^                                           |\n";
		cout << "-------------------------------------------------------------------\n";
		while (getline(cin, line)) {
			if ((pokayoke(line, 1, 7) == 1))break;
		}
		cout << "-------------------------------------------------------------------\n";
		cout << "| �п�J���J�P���ƧǤ覡�A��J�����Ы�Enter��G                 |\n";
		cout << "| 1.����                                                          |\n";
		cout << "| 2.���                                                          |\n";
		cout << "| 3.�R��                                                          |\n";
		cout << "| 4.�®�                                                          |\n";
		cout << "| �]�|�ҡG�Y�Q�n�̷ӡu����v�A�u����v�A�u�R�ߡv�A�u�®�v)       |\n";
		cout << "| �]�п�J\"1234\"�^                                                |\n";
		cout << "| �Y���n�ƧǡA�п�J3333                                          |\n";
		cout << "-------------------------------------------------------------------\n";
		while (getline(cin, sor1)) {
			int flag = 0; string sor11 = sor1;
			if (pokayoke(sor11, 1234, 4321) == 0)continue;
			sort(sor11.begin(), sor11.end());
			if (sor11 != "1234"&&sor1 != "3333") {
				flag = 1;
				cout << "��J���~�A�Э��s��J\n";
			}
			if (flag == 0)break;
		}
		card card[100] = {};
		int pn = pointer;
		for (int i = pointer; i < pointer + stoi(num); i++)card[i - pn].card_in(a[i] / 13 + 1, a[i] % 13 + 1);

		card::print_line(card, stoi(num), stoi(line), sor1);
		pointer += stoi(num);
	}
}
