#include<time.h>
#include"card.h"
#include<string>
#include<cctype>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	//�U�ثŧi
	string s;
	int flag = 0, aa[100] = {},num;
	card a[100] = {}, table[12] = {};
	player p[4];

	//�~�P�A�o�P�A��P
	int T = time(NULL);
	//int T = 1557930574;
	srand(T);
	//cout << T << endl;
	for (int i = 0; i < 52; i++)aa[i] = i;
	for (int I = 0; I < 4; I++)random_shuffle(aa, aa + 52, [](int i) {return rand() % i; });
	for (int i = 0; i < 52; i++)a[i].card_in(aa[i] / 13 + 1, aa[i] % 13 + 1);
	for (int i = 0; i < 52; i++)p[i / 13].Card[i % 13] = a[i];
	for (int i = 0; i < 4; i++) {
		sort(p[i].Card, p[i].Card+13,
		[](card aa, card bb) {
		if(aa.card_suit()!=bb.card_suit())return aa.card_suit() < bb.card_suit(); 
		return aa.card_num() < bb.card_num();
		});
	}

	//���֦��®�7���H���X(�Q�αƧǨϥL�ܦ��Ĺs�쪱�a)
	sort(p, p + 4, [](player a, player b) {
		int aa = 0, bb = 0;
		for (int i = 0; i < 13; i++) (a.Card[i].card_num() == 7) && (aa = max(aa, a.Card[i].card_suit()));
		for (int i = 0; i < 13; i++) (b.Card[i].card_num() == 7) && (bb = max(bb, b.Card[i].card_suit()));
		return aa > bb;
	});

	int tc = 13, flagg=0;
	while(tc--) {
		cout << "�ثe�����W���P�G\n";
		card::print_line(table, 12, 4, 0);
		cout<< "\n�ثe�A��W���P�G\n";
		card::print_line(p[0].Card, 13, 7, 0);
		cout << "��J�A�n�X�ĴX�i�P�G(�R�����P�]��ڡA�Ф��n����)\n";
		while (getline(cin,s)) {
			for (int i = 0; i < s.size(); i++) {
				if (!isdigit(s[i])) {
					flagg = 1;
					cout << "��J���~�A�Э��s��J\n";
					break;
				}
			}
			if (!flagg) {
				num = stoi(s);
				num -= 1;
				if (p[0].Card[num].card_num() && p[0].Card[num].card_suit()&&num>-1&&num<13) {
					if (p[0].playcard(num, table))break;
					else {
						cout << "���ڡA�o���O�A��X���P�ڡA�Э��s��J\n";
					}
				}
				else {
					cout << "��J���~�A�Э��s��J\n";
				}
			}
		}
		card::print_line(table, 12, 4, 0);
		for (int i = 1; i < 4; i++) {
			p[i].computerplay(table);
		}
	}
	pair<int,int> rank[4] = {};
	for (int i = 0; i < 4; i++)rank[i].first =i,rank[i].second= p[i].cover;
	sort(rank, rank + 4, [](pair<int, int>aa, pair<int, int>bb) {return aa.second < bb.second; });
	for (int i = 0; i < 4; i++) {
		cout << "��" << i + 1 << "�W�O:";
		if(rank[i].first!=0)cout<<" ��" << rank[i].first << "��q�����a�A";
		else cout << "�O�A�I";
		cout << "�\�F" << rank[i].second << "�I\n";
	}
	system("pause");
}