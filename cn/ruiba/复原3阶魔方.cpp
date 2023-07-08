// #include "testlib.h"
#include<iostream>
using namespace std;
string ans_[15] = {"","YYY","YYY","YYY","OOOBBBRRRGGG","OOOBBBRRRGGG","OOOBBBRRRGGG","WWW","WWW","WWW"}
    ,target[15] = {"","YYY","YYY","YYY","OOOBBBRRRGGG","OOOBBBRRRGGG","OOOBBBRRRGGG","WWW","WWW","WWW"};
int work(string s) {
	if(s=="U ") {
		string newans_[3] = {"   ","   ","   "};
		ans_[4] = ans_[4].substr(3,9)+ans_[4].substr(0,3);
		newans_[0][0] = ans_[3][0],newans_[0][1] = ans_[2][0],newans_[0][2] = ans_[1][0];
		newans_[1][0] = ans_[3][1],newans_[1][1] = ans_[2][1],newans_[1][2] = ans_[1][1];
		newans_[2][0] = ans_[3][2],newans_[2][1] = ans_[2][2],newans_[2][2] = ans_[1][2];
		ans_[1] = newans_[0];
		ans_[2] = newans_[1];
		ans_[3] = newans_[2];
	}else if(s=="U\'") {
		string newans_[3] = {"   ","   ","   "};
		ans_[4] = ans_[4].substr(9,3)+ans_[4].substr(0,9);
		newans_[0][0] = ans_[1][2],newans_[0][1] = ans_[2][2],newans_[0][2] = ans_[3][2];
		newans_[1][0] = ans_[1][1],newans_[1][1] = ans_[2][1],newans_[1][2] = ans_[3][1];
		newans_[2][0] = ans_[1][0],newans_[2][1] = ans_[2][0],newans_[2][2] = ans_[3][0];
		ans_[1] = newans_[0];
		ans_[2] = newans_[1];
		ans_[3] = newans_[2];
	}else if(s=="U2") {
		string newans_[3] = {"   ","   ","   "};
		ans_[4] = ans_[4].substr(3,9)+ans_[4].substr(0,3);
		newans_[0][0] = ans_[3][0],newans_[0][1] = ans_[2][0],newans_[0][2] = ans_[1][0];
		newans_[1][0] = ans_[3][1],newans_[1][1] = ans_[2][1],newans_[1][2] = ans_[1][1];
		newans_[2][0] = ans_[3][2],newans_[2][1] = ans_[2][2],newans_[2][2] = ans_[1][2];
		ans_[1] = newans_[0];
		ans_[2] = newans_[1];
		ans_[3] = newans_[2];
		ans_[4] = ans_[4].substr(3,9)+ans_[4].substr(0,3);
		newans_[0][0] = ans_[3][0],newans_[0][1] = ans_[2][0],newans_[0][2] = ans_[1][0];
		newans_[1][0] = ans_[3][1],newans_[1][1] = ans_[2][1],newans_[1][2] = ans_[1][1];
		newans_[2][0] = ans_[3][2],newans_[2][1] = ans_[2][2],newans_[2][2] = ans_[1][2];
		ans_[1] = newans_[0];
		ans_[2] = newans_[1];
		ans_[3] = newans_[2];
	}else if(s=="D ") {
		string newans_[3] = {"   ","   ","   "};
		ans_[6] = ans_[6].substr(9,3)+ans_[6].substr(0,9);
		newans_[0][0] = ans_[9][0],newans_[0][1] = ans_[8][0],newans_[0][2] = ans_[7][0];
		newans_[1][0] = ans_[9][1],newans_[1][1] = ans_[8][1],newans_[1][2] = ans_[7][1];
		newans_[2][0] = ans_[9][2],newans_[2][1] = ans_[8][2],newans_[2][2] = ans_[7][2];
		ans_[7] = newans_[0];
		ans_[8] = newans_[1];
		ans_[9] = newans_[2];
	}else if(s=="D\'") {
		string newans_[3] = {"   ","   ","   "};
		ans_[6] = ans_[6].substr(3,9)+ans_[6].substr(0,3);
		newans_[0][0] = ans_[7][2],newans_[0][1] = ans_[8][2],newans_[0][2] = ans_[9][2];
		newans_[1][0] = ans_[7][1],newans_[1][1] = ans_[8][1],newans_[1][2] = ans_[9][1];
		newans_[2][0] = ans_[7][0],newans_[2][1] = ans_[8][0],newans_[2][2] = ans_[9][0];
		ans_[7] = newans_[0];
		ans_[8] = newans_[1];
		ans_[9] = newans_[2];
	}else if(s=="D2") {
		string newans_[3] = {"   ","   ","   "};
		ans_[6] = ans_[6].substr(9,3)+ans_[6].substr(0,9);
		newans_[0][0] = ans_[9][0],newans_[0][1] = ans_[8][0],newans_[0][2] = ans_[7][0];
		newans_[1][0] = ans_[9][1],newans_[1][1] = ans_[8][1],newans_[1][2] = ans_[7][1];
		newans_[2][0] = ans_[9][2],newans_[2][1] = ans_[8][2],newans_[2][2] = ans_[7][2];
		ans_[7] = newans_[0];
		ans_[8] = newans_[1];
		ans_[9] = newans_[2];
		ans_[6] = ans_[6].substr(9,3)+ans_[6].substr(0,9);
		newans_[0][0] = ans_[9][0],newans_[0][1] = ans_[8][0],newans_[0][2] = ans_[7][0];
		newans_[1][0] = ans_[9][1],newans_[1][1] = ans_[8][1],newans_[1][2] = ans_[7][1];
		newans_[2][0] = ans_[9][2],newans_[2][1] = ans_[8][2],newans_[2][2] = ans_[7][2];
		ans_[7] = newans_[0];
		ans_[8] = newans_[1];
		ans_[9] = newans_[2];
	}else if(s=="R ") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[1][2],ans_[4][5]),swap(ans_[2][2],ans_[5][5]),swap(ans_[3][2],ans_[6][5]);
		swap(ans_[4][5],ans_[7][2]),swap(ans_[5][5],ans_[8][2]),swap(ans_[6][5],ans_[9][2]);
		swap(ans_[7][2],ans_[6][9]),swap(ans_[8][2],ans_[5][9]),swap(ans_[9][2],ans_[4][9]);
		newans_[0][0] = ans_[6][6],newans_[0][1] = ans_[5][6],newans_[0][2] = ans_[4][6];
		newans_[1][0] = ans_[6][7],newans_[1][1] = ans_[5][7],newans_[1][2] = ans_[4][7];
		newans_[2][0] = ans_[6][8],newans_[2][1] = ans_[5][8],newans_[2][2] = ans_[4][8];
		ans_[4] = ans_[4].substr(0,6)+newans_[0]+ans_[4].substr(9,3);
		ans_[5] = ans_[5].substr(0,6)+newans_[1]+ans_[5].substr(9,3);
		ans_[6] = ans_[6].substr(0,6)+newans_[2]+ans_[6].substr(9,3);
	}else if(s=="R\'") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[7][2],ans_[6][9]),swap(ans_[8][2],ans_[5][9]),swap(ans_[9][2],ans_[4][9]);
		swap(ans_[4][5],ans_[7][2]),swap(ans_[5][5],ans_[8][2]),swap(ans_[6][5],ans_[9][2]);
		swap(ans_[1][2],ans_[4][5]),swap(ans_[2][2],ans_[5][5]),swap(ans_[3][2],ans_[6][5]);
		newans_[0][0] = ans_[4][8],newans_[0][1] = ans_[5][8],newans_[0][2] = ans_[6][8];
		newans_[1][0] = ans_[4][7],newans_[1][1] = ans_[5][7],newans_[1][2] = ans_[6][7];
		newans_[2][0] = ans_[4][6],newans_[2][1] = ans_[5][6],newans_[2][2] = ans_[6][6];
		ans_[4] = ans_[4].substr(0,6)+newans_[0]+ans_[4].substr(9,3);
		ans_[5] = ans_[5].substr(0,6)+newans_[1]+ans_[5].substr(9,3);
		ans_[6] = ans_[6].substr(0,6)+newans_[2]+ans_[6].substr(9,3);
	}else if(s=="R2") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[1][2],ans_[4][5]),swap(ans_[2][2],ans_[5][5]),swap(ans_[3][2],ans_[6][5]);
		swap(ans_[4][5],ans_[7][2]),swap(ans_[5][5],ans_[8][2]),swap(ans_[6][5],ans_[9][2]);
		swap(ans_[7][2],ans_[6][9]),swap(ans_[8][2],ans_[5][9]),swap(ans_[9][2],ans_[4][9]);
		newans_[0][0] = ans_[6][6],newans_[0][1] = ans_[5][6],newans_[0][2] = ans_[4][6];
		newans_[1][0] = ans_[6][7],newans_[1][1] = ans_[5][7],newans_[1][2] = ans_[4][7];
		newans_[2][0] = ans_[6][8],newans_[2][1] = ans_[5][8],newans_[2][2] = ans_[4][8];
		ans_[4] = ans_[4].substr(0,6)+newans_[0]+ans_[4].substr(9,3);
		ans_[5] = ans_[5].substr(0,6)+newans_[1]+ans_[5].substr(9,3);
		ans_[6] = ans_[6].substr(0,6)+newans_[2]+ans_[6].substr(9,3);
		swap(ans_[1][2],ans_[4][5]),swap(ans_[2][2],ans_[5][5]),swap(ans_[3][2],ans_[6][5]);
		swap(ans_[4][5],ans_[7][2]),swap(ans_[5][5],ans_[8][2]),swap(ans_[6][5],ans_[9][2]);
		swap(ans_[7][2],ans_[6][9]),swap(ans_[8][2],ans_[5][9]),swap(ans_[9][2],ans_[4][9]);
		newans_[0][0] = ans_[6][6],newans_[0][1] = ans_[5][6],newans_[0][2] = ans_[4][6];
		newans_[1][0] = ans_[6][7],newans_[1][1] = ans_[5][7],newans_[1][2] = ans_[4][7];
		newans_[2][0] = ans_[6][8],newans_[2][1] = ans_[5][8],newans_[2][2] = ans_[4][8];
		ans_[4] = ans_[4].substr(0,6)+newans_[0]+ans_[4].substr(9,3);
		ans_[5] = ans_[5].substr(0,6)+newans_[1]+ans_[5].substr(9,3);
		ans_[6] = ans_[6].substr(0,6)+newans_[2]+ans_[6].substr(9,3);
	}else if(s=="L ") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[7][0],ans_[6][11]),swap(ans_[8][0],ans_[5][11]),swap(ans_[9][0],ans_[4][11]);
		swap(ans_[4][3],ans_[7][0]),swap(ans_[5][3],ans_[8][0]),swap(ans_[6][3],ans_[9][0]);
		swap(ans_[1][0],ans_[4][3]),swap(ans_[2][0],ans_[5][3]),swap(ans_[3][0],ans_[6][3]);
		newans_[0][0] = ans_[6][0],newans_[0][1] = ans_[5][0],newans_[0][2] = ans_[4][0];
		newans_[1][0] = ans_[6][1],newans_[1][1] = ans_[5][1],newans_[1][2] = ans_[4][1];
		newans_[2][0] = ans_[6][2],newans_[2][1] = ans_[5][2],newans_[2][2] = ans_[4][2];
		ans_[4] = newans_[0]+ans_[4].substr(3,9);
		ans_[5] = newans_[1]+ans_[5].substr(3,9);
		ans_[6] = newans_[2]+ans_[6].substr(3,9);
	}else if(s=="L\'") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[1][0],ans_[4][3]),swap(ans_[2][0],ans_[5][3]),swap(ans_[3][0],ans_[6][3]);
		swap(ans_[4][3],ans_[7][0]),swap(ans_[5][3],ans_[8][0]),swap(ans_[6][3],ans_[9][0]);
		swap(ans_[7][0],ans_[6][11]),swap(ans_[8][0],ans_[5][11]),swap(ans_[9][0],ans_[4][11]);
		newans_[0][0] = ans_[4][2],newans_[0][1] = ans_[5][2],newans_[0][2] = ans_[6][2];
		newans_[1][0] = ans_[4][1],newans_[1][1] = ans_[5][1],newans_[1][2] = ans_[6][1];
		newans_[2][0] = ans_[4][0],newans_[2][1] = ans_[5][0],newans_[2][2] = ans_[6][0];
		ans_[4] = newans_[0]+ans_[4].substr(3,9);
		ans_[5] = newans_[1]+ans_[5].substr(3,9);
		ans_[6] = newans_[2]+ans_[6].substr(3,9);
	}else if(s=="L2") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[7][0],ans_[6][11]),swap(ans_[8][0],ans_[5][11]),swap(ans_[9][0],ans_[4][11]);
		swap(ans_[4][3],ans_[7][0]),swap(ans_[5][3],ans_[8][0]),swap(ans_[6][3],ans_[9][0]);
		swap(ans_[1][0],ans_[4][3]),swap(ans_[2][0],ans_[5][3]),swap(ans_[3][0],ans_[6][3]);
		newans_[0][0] = ans_[6][0],newans_[0][1] = ans_[5][0],newans_[0][2] = ans_[4][0];
		newans_[1][0] = ans_[6][1],newans_[1][1] = ans_[5][1],newans_[1][2] = ans_[4][1];
		newans_[2][0] = ans_[6][2],newans_[2][1] = ans_[5][2],newans_[2][2] = ans_[4][2];
		ans_[4] = newans_[0]+ans_[4].substr(3,9);
		ans_[5] = newans_[1]+ans_[5].substr(3,9);
		ans_[6] = newans_[2]+ans_[6].substr(3,9);
		swap(ans_[7][0],ans_[6][11]),swap(ans_[8][0],ans_[5][11]),swap(ans_[9][0],ans_[4][11]);
		swap(ans_[4][3],ans_[7][0]),swap(ans_[5][3],ans_[8][0]),swap(ans_[6][3],ans_[9][0]);
		swap(ans_[1][0],ans_[4][3]),swap(ans_[2][0],ans_[5][3]),swap(ans_[3][0],ans_[6][3]);
		newans_[0][0] = ans_[6][0],newans_[0][1] = ans_[5][0],newans_[0][2] = ans_[4][0];
		newans_[1][0] = ans_[6][1],newans_[1][1] = ans_[5][1],newans_[1][2] = ans_[4][1];
		newans_[2][0] = ans_[6][2],newans_[2][1] = ans_[5][2],newans_[2][2] = ans_[4][2];
		ans_[4] = newans_[0]+ans_[4].substr(3,9);
		ans_[5] = newans_[1]+ans_[5].substr(3,9);
		ans_[6] = newans_[2]+ans_[6].substr(3,9);
	}else if(s=="F ") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[4][2],ans_[7][0]),swap(ans_[5][2],ans_[7][1]),swap(ans_[6][2],ans_[7][2]);
		swap(ans_[7][0],ans_[6][6]),swap(ans_[7][1],ans_[5][6]),swap(ans_[7][2],ans_[4][6]);
		swap(ans_[6][6],ans_[3][2]),swap(ans_[5][6],ans_[3][1]),swap(ans_[4][6],ans_[3][0]);
		newans_[0][0] = ans_[6][3],newans_[0][1] = ans_[5][3],newans_[0][2] = ans_[4][3];
		newans_[1][0] = ans_[6][4],newans_[1][1] = ans_[5][4],newans_[1][2] = ans_[4][4];
		newans_[2][0] = ans_[6][5],newans_[2][1] = ans_[5][5],newans_[2][2] = ans_[4][5];
		ans_[4] = ans_[4].substr(0,3)+newans_[0]+ans_[4].substr(6,6);
		ans_[5] = ans_[5].substr(0,3)+newans_[1]+ans_[5].substr(6,6);
		ans_[6] = ans_[6].substr(0,3)+newans_[2]+ans_[6].substr(6,6);
	}else if(s=="F\'") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[6][6],ans_[3][2]),swap(ans_[5][6],ans_[3][1]),swap(ans_[4][6],ans_[3][0]);
		swap(ans_[7][0],ans_[6][6]),swap(ans_[7][1],ans_[5][6]),swap(ans_[7][2],ans_[4][6]);
		swap(ans_[4][2],ans_[7][0]),swap(ans_[5][2],ans_[7][1]),swap(ans_[6][2],ans_[7][2]);
		newans_[0][0] = ans_[4][5],newans_[0][1] = ans_[5][5],newans_[0][2] = ans_[6][5];
		newans_[1][0] = ans_[4][4],newans_[1][1] = ans_[5][4],newans_[1][2] = ans_[6][4];
		newans_[2][0] = ans_[4][3],newans_[2][1] = ans_[5][3],newans_[2][2] = ans_[6][3];
		ans_[4] = ans_[4].substr(0,3)+newans_[0]+ans_[4].substr(6,6);
		ans_[5] = ans_[5].substr(0,3)+newans_[1]+ans_[5].substr(6,6);
		ans_[6] = ans_[6].substr(0,3)+newans_[2]+ans_[6].substr(6,6);
	}else if(s=="F2") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[4][2],ans_[7][0]),swap(ans_[5][2],ans_[7][1]),swap(ans_[6][2],ans_[7][2]);
		swap(ans_[7][0],ans_[6][6]),swap(ans_[7][1],ans_[5][6]),swap(ans_[7][2],ans_[4][6]);
		swap(ans_[6][6],ans_[3][2]),swap(ans_[5][6],ans_[3][1]),swap(ans_[4][6],ans_[3][0]);
		newans_[0][0] = ans_[6][3],newans_[0][1] = ans_[5][3],newans_[0][2] = ans_[4][3];
		newans_[1][0] = ans_[6][4],newans_[1][1] = ans_[5][4],newans_[1][2] = ans_[4][4];
		newans_[2][0] = ans_[6][5],newans_[2][1] = ans_[5][5],newans_[2][2] = ans_[4][5];
		ans_[4] = ans_[4].substr(0,3)+newans_[0]+ans_[4].substr(6,6);
		ans_[5] = ans_[5].substr(0,3)+newans_[1]+ans_[5].substr(6,6);
		ans_[6] = ans_[6].substr(0,3)+newans_[2]+ans_[6].substr(6,6);
		swap(ans_[4][2],ans_[7][0]),swap(ans_[5][2],ans_[7][1]),swap(ans_[6][2],ans_[7][2]);
		swap(ans_[7][0],ans_[6][6]),swap(ans_[7][1],ans_[5][6]),swap(ans_[7][2],ans_[4][6]);
		swap(ans_[6][6],ans_[3][2]),swap(ans_[5][6],ans_[3][1]),swap(ans_[4][6],ans_[3][0]);
		newans_[0][0] = ans_[6][3],newans_[0][1] = ans_[5][3],newans_[0][2] = ans_[4][3];
		newans_[1][0] = ans_[6][4],newans_[1][1] = ans_[5][4],newans_[1][2] = ans_[4][4];
		newans_[2][0] = ans_[6][5],newans_[2][1] = ans_[5][5],newans_[2][2] = ans_[4][5];
		ans_[4] = ans_[4].substr(0,3)+newans_[0]+ans_[4].substr(6,6);
		ans_[5] = ans_[5].substr(0,3)+newans_[1]+ans_[5].substr(6,6);
		ans_[6] = ans_[6].substr(0,3)+newans_[2]+ans_[6].substr(6,6);
	}else if(s=="B ") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[4][8],ans_[1][0]),swap(ans_[5][8],ans_[1][1]),swap(ans_[6][8],ans_[1][2]);
		swap(ans_[9][0],ans_[6][8]),swap(ans_[9][1],ans_[5][8]),swap(ans_[9][2],ans_[4][8]);
		swap(ans_[4][0],ans_[9][0]),swap(ans_[5][0],ans_[9][1]),swap(ans_[6][0],ans_[9][2]);
		newans_[0][0] = ans_[6][9],newans_[0][1] = ans_[5][9],newans_[0][2] = ans_[4][9];
		newans_[1][0] = ans_[6][10],newans_[1][1] = ans_[5][10],newans_[1][2] = ans_[4][10];
		newans_[2][0] = ans_[6][11],newans_[2][1] = ans_[5][11],newans_[2][2] = ans_[4][11];
		ans_[4] = ans_[4].substr(0,9)+newans_[0];
		ans_[5] = ans_[5].substr(0,9)+newans_[1];
		ans_[6] = ans_[6].substr(0,9)+newans_[2];
	}else if(s=="B\'") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[4][0],ans_[9][0]),swap(ans_[5][0],ans_[9][1]),swap(ans_[6][0],ans_[9][2]);
		swap(ans_[9][0],ans_[6][8]),swap(ans_[9][1],ans_[5][8]),swap(ans_[9][2],ans_[4][8]);
		swap(ans_[4][8],ans_[1][0]),swap(ans_[5][8],ans_[1][1]),swap(ans_[6][8],ans_[1][2]);
		newans_[0][0] = ans_[4][11],newans_[0][1] = ans_[5][11],newans_[0][2] = ans_[6][11];
		newans_[1][0] = ans_[4][10],newans_[1][1] = ans_[5][10],newans_[1][2] = ans_[6][10];
		newans_[2][0] = ans_[4][9],newans_[2][1] = ans_[5][9],newans_[2][2] = ans_[6][9];
		ans_[4] = ans_[4].substr(0,9)+newans_[0];
		ans_[5] = ans_[5].substr(0,9)+newans_[1];
		ans_[6] = ans_[6].substr(0,9)+newans_[2];
	}else if(s=="B2") {
		string newans_[3] = {"   ","   ","   "};
		swap(ans_[4][8],ans_[1][0]),swap(ans_[5][8],ans_[1][1]),swap(ans_[6][8],ans_[1][2]);
		swap(ans_[9][0],ans_[6][8]),swap(ans_[9][1],ans_[5][8]),swap(ans_[9][2],ans_[4][8]);
		swap(ans_[4][0],ans_[9][0]),swap(ans_[5][0],ans_[9][1]),swap(ans_[6][0],ans_[9][2]);
		newans_[0][0] = ans_[6][9],newans_[0][1] = ans_[5][9],newans_[0][2] = ans_[4][9];
		newans_[1][0] = ans_[6][10],newans_[1][1] = ans_[5][10],newans_[1][2] = ans_[4][10];
		newans_[2][0] = ans_[6][11],newans_[2][1] = ans_[5][11],newans_[2][2] = ans_[4][11];
		ans_[4] = ans_[4].substr(0,9)+newans_[0];
		ans_[5] = ans_[5].substr(0,9)+newans_[1];
		ans_[6] = ans_[6].substr(0,9)+newans_[2];
		swap(ans_[4][8],ans_[1][0]),swap(ans_[5][8],ans_[1][1]),swap(ans_[6][8],ans_[1][2]);
		swap(ans_[9][0],ans_[6][8]),swap(ans_[9][1],ans_[5][8]),swap(ans_[9][2],ans_[4][8]);
		swap(ans_[4][0],ans_[9][0]),swap(ans_[5][0],ans_[9][1]),swap(ans_[6][0],ans_[9][2]);
		newans_[0][0] = ans_[6][9],newans_[0][1] = ans_[5][9],newans_[0][2] = ans_[4][9];
		newans_[1][0] = ans_[6][10],newans_[1][1] = ans_[5][10],newans_[1][2] = ans_[4][10];
		newans_[2][0] = ans_[6][11],newans_[2][1] = ans_[5][11],newans_[2][2] = ans_[4][11];
		ans_[4] = ans_[4].substr(0,9)+newans_[0];
		ans_[5] = ans_[5].substr(0,9)+newans_[1];
		ans_[6] = ans_[6].substr(0,9)+newans_[2];
	}else{
		return -1;
	}
	return 0;
}
int main(int argc, char* argv[]) {
	// registerTestlibCmd(argc, argv);
	for(int i = 1;i<=9;i++) cin>>ans_[i];
    for(int i = 1;i<=1000;i++) {
        int x = rand()%6;
        if(x==0) work("U ");
        if(x==1) work("D ");
        if(x==2) work("F ");
        if(x==3) work("R ");
        if(x==4) work("L ");
        if(x==5) work("B ");
    }
    for(int i=1;i<=9;i++){
        cout<<ans_[i]<<endl;
    }
    string s;cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		string ss="  ";
		ss[0]=s[i];
		if(i<n-1&&(s[i+1]=='2'||s[i+1]=='\'')){
			ss[1]=s[i+1];i++;
		}
		if(work(ss)==-1){
			// quitf(_wa, "Illegal operation.");
            cout<<"Illegal operation."<<endl;
		}
	}
	for(int i = 1; i<=3; i++)
		for(int j = 0; j<=2; j++)
			if(ans_[i][j]!=target[i][j])
				// quitf(_wa, "The answer is wrong.");
                cout<<"The answer is wrong."<<endl;
	for(int i = 4; i<=6; i++)
		for(int j = 0; j<=11; j++)
			if(ans_[i][j]!=target[i][j])
				// quitf(_wa, "The answer is wrong.");
                cout<<"The answer is wrong."<<endl;
	for(int i = 7; i<=9; i++)
		for(int j = 0; j<=2; j++)
			if(ans_[i][j]!=target[i][j])
				// quitf(_wa, "The answer is wrong.");
                cout<<"The answer is wrong."<<endl;
	// quitf(_ok, "The answer is correct.");
    cout<<"The answer is correct."<<endl;
}