#include <iostream>
// #include <bits/stdc++.h>
using namespace std;

#include <vector>

double func(int angka, int warna1, int warna2) {
	// pair

	double konstan = (angka * 10.1) - 13;
	// return 1.39 + (pow(2, warna1)) * (pow(2, warna2)) + pow(angka, 3);
	return 1.39 + konstan + (pow(2, warna1) + pow(2, warna2));
}

double func2(int angka1, int warna1_a, int warna1_b, int angka2, int warna2_a, int warna2_b) {
	// twopair

	// int biggerNum = (angka1 > angka2) ? (angka1) : (angka2);
	if (angka1 > angka2) {
		return 131.69 + func(angka1, warna1_a, warna1_b) + func(angka2, warna2_a, warna2_b) * 0.3;
	} else {
		return 131.69 + func(angka2, warna2_a, warna2_b) + func(angka1, warna1_a, warna1_b) * 0.3;
	}

	// 299.857
}

double func3(int angka, int warna1, int warna2, int warna3) {
	// threes

	double konstan = (angka * 10.1) - 15;

	return 299.857 + (konstan) + (pow(2, warna1) + pow(2, warna2) + pow(2, warna3));
}

double func4(int angka1, int angka2, int angka3, int angka4, int angka5, int warna1, int warna2, int warna3, int warna4, int warna5) {
	// straight

	double konstan = angka1 * 1024;

	int subset = 0;
	subset = subset | (warna5 << 8);
	subset = subset | (warna4 << 6);
	subset = subset | (warna3 << 4);
	subset = subset | (warna2 << 2);
	subset = subset | warna1;

	return 430.157 + konstan + subset;
}

double func5(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
	// flush

	double konstan = warna * 0.2;

	return 10669.2 + konstan + pow(2, angka1) + pow(2, angka2) + pow(2, angka3) + pow(2, angka4) + pow(2, angka5);

	// max = 50861.2
}

double func6(int angka1, int angka2, int warna1_1, int warna1_2, int warna1_3, int warna2_1, int warna2_2) {
	// full house
	// angka1 = 3 biji
	// angka2 = 2 biji

	double konstan1 = pow(2, warna1_1) + pow(2, warna1_2) + pow(2, warna1_3);
	double konstan2 = pow(2, warna2_1) + pow(2, warna2_2);

	// min 5 x 32 = 160
	// max 158

	return 26285.8 + (pow(2, angka1) + pow(2, angka2)) * pow(2, 5) + (pow(konstan1, 2) + konstan2 - 50);
}

double func7(int angka) {

	return 419660 + angka;
}

double func8(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
	// straight flush

	double konstan = warna;

	return 419673 + konstan + angka1 + angka2 + angka3 + angka4 + angka5;
}


// int main() {
// 	int hijau = 0, biru = 1, kuning = 2, merah = 3;

// 	// int count = 0;
// 	// int count22 = 0;

// 	// vector<double> v1;

// 	// for (int i = 1; i <= 13; i ++) {
// 	// 	for (int j = 0; j < 4; j ++) {
// 	// 		for (int k = j + 1; k < 4; k ++) {
// 	// 			// cout << func(i, j, k) << " " << j << " " << k << " " << i << endl;
// 	// 			cout << func(i, j, k) << endl;

// 	// 			count++;

// 	// 			std::vector<double>::iterator it;
// 	// 			it = std::find(v1.begin(), v1.end(), func(i,j,k));
// 	// 			if (it != v1.end())
// 	// 			{
// 	// 			    count22 ++;
// 	// 			}
// 	// 		    v1.push_back(func(i,j,k));
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << count << endl;
// 	// cout << count22 << endl;

// 	// cout << endl << "two pair" << endl;

// 	// int count2 = 0;
// 	// int count3 = 0;

// 	// vector<double> v;

// 	// for (int i = 1; i <= 13; i ++) {
// 	// 	for (int p = i + 1; p <= 13; p ++) {
// 	// 		for (int j = 0; j < 4; j ++) {
// 	// 			for (int k = j + 1; k < 4; k ++) {
// 	// 				for (int x = 0; x < 4; x ++) {
// 	// 					for (int y = x + 1; y < 4; y ++) {
// 	// 						// if (j != )
// 	// 						count2++;
// 	// 						cout << func2(i, j, k, p, x, y) << "\n";
// 	// 						// cout << i << " " << j << " " << k << " " << p << " " << x << " " << y << endl;
							
// 	// 						std::vector<double>::iterator it;
// 	// 						it = std::find(v.begin(), v.end(), func2(i, j, k, p, x, y));
// 	// 						if (it != v.end())
// 	// 						{
// 	// 						    count3 ++;
// 	// 						}
// 	// 					    v.push_back(func2(i, j, k, p, x, y));

// 	// 						// count2++;
// 	// 						// cout << func2(i, j, k, p, x, y) << endl;
// 	// 					}
// 	// 				}
// 	// 				// cout << func2(i, j, k) << " " << j << " " << k << " " << i << endl;
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << count2 << endl;
// 	// cout << count3 << endl;

// 	// int a = 0;
// 	// int aa = 0;

// 	// vector<double> v3;

// 	// for (int i = 1; i <= 13; i ++) {
// 	// 	for (int j = 0; j < 4; j ++) {
// 	// 		for (int k = j + 1; k < 4; k ++) {
// 	// 			for (int l = k + 1; l < 4; l ++) {
// 	// 				// cout << func3(i, j, k, l) << " " << j << " " << k << " " << l << " " << i << endl;
// 	// 				cout << func3(i, j, k, l) << endl;
// 	// 				a++;

// 	// 				std::vector<double>::iterator it;
// 	// 				it = std::find(v3.begin(), v3.end(), func3(i,j,k,l));
// 	// 				if (it != v3.end())
// 	// 				{
// 	// 				    aa ++;
// 	// 				}
// 	// 			    v3.push_back(func3(i,j,k,l));
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }


// 	// cout << a << endl;
// 	// cout << aa << endl;

// 	// vector<double> v4;
// 	// int a4 = 0;
// 	// int a44 = 0;

// 	// for (int pp = 1; pp <=9; pp ++) {
// 	// 	for (int i = 0; i < 4; i ++) {
// 	// 		for (int j = 0; j < 4; j ++) {
// 	// 			for (int k = 0; k < 4; k ++) {
// 	// 				for (int l = 0; l < 4; l ++) {
// 	// 					for (int m = 0; m < 4; m ++) {
// 	// 						if (i != j != k != l != m) {
// 	// 							cout << func4(pp, pp+1, pp +2, pp+3, pp+4, i, j, k, l,m) << endl;
// 	// 							// << " " << i << " " << j << " " << k << " " << l << " " << m << endl;
// 	// 							a4++;

// 	// 							std::vector<double>::iterator it;
// 	// 							it = std::find(v4.begin(), v4.end(), func4(pp, pp+1, pp +2, pp+3, pp+4, i,j,k,l,m));
// 	// 							if (it != v4.end())
// 	// 							{
// 	// 							    a44 ++;
// 	// 							}
// 	// 						    v4.push_back(func4(pp, pp+1, pp +2, pp+3, pp+4, i,j,k,l,m));
// 	// 						}
// 	// 					}
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << a4 << endl;
// 	// cout << a44 << endl;

// 	// vector<double> v5;

// 	// int count = 0;

// 	// for (int warna = 0; warna <= 3; warna ++) {
// 	// 	for (int x = 1; x <= 13; x ++) {
// 	// 		for (int y = x + 1; y <= 13; y ++) {
// 	// 			for (int z = y + 1; z <= 13; z ++) {
// 	// 				for (int o = z + 1; o <= 13; o ++) {
// 	// 					for (int p = o + 1; p <= 13; p ++) {
// 	// 						int temp1 = x + 4;
// 	// 						int temp2 = y + 3;
// 	// 						int temp3 = z + 2;
// 	// 						int temp4 = o + 1;

// 	// 						if (temp1 == temp2 && temp2 == temp3 && temp3 == temp4 && temp4 == p) {
// 	// 							// cout << "HALOHALO" << endl;
// 	// 						} else {
// 	// 							// cout << func5(x, y, z, o, p, warna) << " " << x << " " << y << " " << z << " " << o << " " << p << " warna: " << warna << endl;

// 	// 							cout << func5(x, y, z, o, p, warna) << endl;
// 	// 							std::vector<double>::iterator it;
// 	// 							it = std::find(v5.begin(), v5.end(), func5(x, y, z, o, p, warna));
// 	// 							if (it != v5.end())
// 	// 							{
// 	// 							    count ++;
// 	// 							}
// 	// 						    v5.push_back(func5(x, y, z, o, p, warna));
// 	// 						}
// 	// 					}
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << count << endl;

// 	// vector<double> v6;

// 	// int f = 0;
// 	// int fl = 0;

// 	// for (int x = 1; x <= 13; x ++) {
// 	// 	for (int y = x + 1; y <= 13; y ++) {
// 	// 		for (int w1 = 0; w1 <= 3; w1 ++) {
// 	// 			for (int w2 = w1 + 1; w2 <= 3; w2 ++) {
// 	// 				for (int w3 = w2 + 1; w3 <= 3; w3 ++) {
// 	// 					for (int v1 = 0; v1 <= 3; v1 ++) {
// 	// 						for (int v2 = v1 + 1; v2 <= 3; v2 ++) {
// 	// 							// cout << func6(x, y, w1, w2, w3, v1, v2) << " " << x << " " << w1 << " " << w2 << " " << w3 << " | " << y << " " << v1 << " " << v2 << endl;

// 	// 							cout << func6(x, y, w1, w2, w3, v1, v2) << endl;
// 	// 							f ++;
// 	// 							std::vector<double>::iterator it;
// 	// 							it = std::find(v6.begin(), v6.end(), func6(x, y, w1, w2, w3, v1, v2));
// 	// 							if (it != v6.end())
// 	// 							{
// 	// 							    fl ++;
// 	// 							}
// 	// 						    v6.push_back(func6(x, y, w1, w2, w3, v1, v2));
// 	// 						}
// 	// 					}
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << f << endl;
// 	// cout << fl << endl;

// 	// vector<double> temp;
// 	// int cc = 0;
// 	// int cc1 = 0;

// 	// for (int w1 = 0; w1 <= 3; w1 ++) {
// 	// 	for (int w2 = w1 + 1; w2 <= 3; w2 ++) {
// 	// 		for (int w3 = w2 + 1; w3 <= 3; w3 ++) {
// 	// 			for (int v1 = 0; v1 <= 3; v1 ++) {
// 	// 				for (int v2 = v1 + 1; v2 <= 3; v2 ++) {
// 	// 					double konstan1 = pow(2, w1) + pow(2, w2) + pow(2, w3);
// 	// 					double konstan2 = pow(2, v1) + pow(2, v2);

// 	// 					double rumus = (pow(konstan1, 2) + konstan2) - 50;
// 	// 					// cout << rumus << " " << konstan1 << " " << konstan2 << endl;

// 	// 					cout << rumus << endl;
// 	// 					cc ++;
// 	// 					std::vector<double>::iterator it;
// 	// 					it = std::find(temp.begin(), temp.end(), rumus);
// 	// 					if (it != temp.end())
// 	// 					{
// 	// 					    cc1 ++;
// 	// 					}
// 	// 				    temp.push_back(rumus);
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << cc << endl;
// 	// cout << cc1 << endl;

// 	// cout << 50.2 + pow(2, 13) << endl;

// 	// vector<double> temp;
// 	// int cc = 0;
// 	// int cc1 = 0;

// 	// for (int x = 1; x <= 13; x ++) {
// 	// 	for (int y = x + 1; y <= 13; y ++) {
// 	// 		cout << x << " " << y << " " << pow(2, x) + pow(2, y) << endl;

// 	// 		cc ++;
// 	// 		std::vector<double>::iterator it;
// 	// 		it = std::find(temp.begin(), temp.end(), pow(2, x) + pow(2, y));
// 	// 		if (it != temp.end())
// 	// 		{
// 	// 		    cc1 ++;
// 	// 		}
// 	// 	    temp.push_back(pow(2, x) + pow(2, y));
// 	// 	}
// 	// }

// 	// cout << cc << endl;
// 	// cout << cc1 << endl;

// 	// vector<double> v7;

// 	// int count = 0;
// 	// int banyak = 0;

// 	// for (int warna = 0; warna <= 3; warna ++) {
// 	// 	for (int x = 1; x <= 13; x ++) {
// 	// 		for (int y = x + 1; y <= 13; y ++) {
// 	// 			for (int z = y + 1; z <= 13; z ++) {
// 	// 				for (int o = z + 1; o <= 13; o ++) {
// 	// 					for (int p = o + 1; p <= 13; p ++) {
// 	// 						int temp1 = x + 4;
// 	// 						int temp2 = y + 3;
// 	// 						int temp3 = z + 2;
// 	// 						int temp4 = o + 1;

// 	// 						if (temp1 == temp2 && temp2 == temp3 && temp3 == temp4 && temp4 == p) {
// 	// 							cout << func8(x, y, z, o, p, warna) << " " << x << " " << y << " " << z << " " << o << " " << p << " warna: " << warna << endl;
// 	// 							banyak ++;
// 	// 							std::vector<double>::iterator it;
// 	// 							it = std::find(v7.begin(), v7.end(), func8(x, y, z, o, p, warna));
// 	// 							if (it != v7.end())
// 	// 							{
// 	// 							    count ++;
// 	// 							}
// 	// 						    v7.push_back(func8(x, y, z, o, p, warna));
// 	// 						} else {
// 	// 							cout << "HALOHALO" << endl;
// 	// 						}
// 	// 					}
// 	// 				}
// 	// 			}
// 	// 		}
// 	// 	}
// 	// }

// 	// cout << banyak << endl;
// 	// cout << count << endl;

// 	vector<double> v8;

// 	int count = 0;
// 	int banyak = 0;

// 	for (int warna = 0; warna <= 3; warna ++) {
// 		for (int x = 1; x <= 13; x ++) {
// 			for (int y = x + 1; y <= 13; y ++) {
// 				for (int z = y + 1; z <= 13; z ++) {
// 					for (int o = z + 1; o <= 13; o ++) {
// 						for (int p = o + 1; p <= 13; p ++) {
// 							int temp1 = x + 4;
// 							int temp2 = y + 3;
// 							int temp3 = z + 2;
// 							int temp4 = o + 1;

// 							if (temp1 == temp2 && temp2 == temp3 && temp3 == temp4 && temp4 == p) {
// 								cout << func8(x, y, z, o, p, warna) << " " << x << " " << y << " " << z << " " << o << " " << p << " warna: " << warna << endl;
								
// 								// cout << func8(x, y, z, o, p, warna) << endl;
// 								banyak ++;
// 								std::vector<double>::iterator it;
// 								it = std::find(v8.begin(), v8.end(), func8(x, y, z, o, p, warna));
// 								if (it != v8.end())
// 								{
// 								    count ++;
// 								}
// 							    v8.push_back(func8(x, y, z, o, p, warna));
// 							} else {
// 								// cout << "HALOHALO" << endl;
// 							}
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}

// 	cout << banyak << endl;
// 	cout << count << endl;
// 	return 0;
// }