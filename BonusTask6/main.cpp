#include <iostream>
#include <ctime>
#include <cstdlib>




int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	// ������ 1. ������� �������������� ������� ������� �������
	std::cout << "������ 1.\n������ ��������� �����.\n";
	const int rows1 = 10, cols1 = 10;

	int matr1[rows1][cols1]{};

	srand(time(NULL));

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			matr1[i][j] = rand() % 90 + 10;
			std::cout << matr1[i][j] << '\t';
		}
		std::cout << std::endl;
	}

	std::cout << "\n������� �������������� ������� �������.\n";
	std::cout << "||\t||\t||\t||\t||\t||\t||\t||\t||\t||\t\n";
	std::cout << "\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\\/\t\n";

	int sum = 0;

	for (int i = 0; i < cols1; i++) {
		for (int j = 0; j < rows1; j++)
			sum += matr1[j][i];
		std::cout << sum / (double)cols1 << '\t';
		sum = 0;
	}
	std::cout << "\n\n";


	// ������ 2. ���������� ������� 0 � 1 � ��������� �������

	std::cout << "������ 2.\n������ ����������� 0 � 1 � ��������� �������.\n\n";
	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols1; j++) {
			if ((i + j) % 2 == 0)
				matr1[i][j] = 0;
			else
				matr1[i][j] = 1;
			std::cout << matr1[i][j] << " ";
		}
		std::cout << '\n';
	}

	// ������ 3. ���������� ������� �� �������

	std::cout << "������ 3.\n";
	const int rows2 = 10, cols2 = 2;
	int mx2[rows2][cols2]{};

	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < cols2; j++) {
			if (j == 0) {
				std::cout << "������� �������� ������� " << i << ", " << j << " -> ";
				std::cin >> mx2[i][j];
			}
			else
				mx2[i][j] = i * mx2[i][j - 1];
		}
	}

	std::cout << "����������� ������.\n";
	for (int i = 0; i < rows2; i++) {
		for (int j = 0; j < cols2; j++) {
			std::cout << '\t' << mx2[i][j];
		}
		std::cout << std::endl;
	}

	std::cout << "\n\n";

	// ������ 4. ��������� ������ 5 �� 5 �� �������

	std::cout << "������ 4.\n";
	const int row3 = 5, col3 = 5;
	int mx3[row3][col3]{};

	int count = 0;
	int k = 0;
	
	/*for (int m = 0; m <= row3/2; m++) {
		for (int i = 0; i < 4; i++) {
			for (int j = m; j < col3 - m; j++) {
				if (i == 0) {
					mx3[m][j] = count;
					count++;
				}
				if (i == 1) {
					if (j > m) {
						mx3[j][row3 - 1 - m] = count;
						count++;
					}
				}
				if (i == 2) {
					if (j > m) {
						mx3[row3 - 1 - m][col3 - 1 - j] = count;
						count++;
					}
				}
				if (i == 3) {
					if (m < j && j < row3 - 1 - m) {
						mx3[row3 - 1 - j][m] = count;
						count++;
					}

				}
			}
		}
	}*/
	int m = 0; // ������� ��������� ���������������� � ������ ������ ����������� �������� 3� ����������������
	int start_x = 0, start_y = 0;
	int last_digit = 0;
	int border_x = col3, border_y = row3; // ������� �������

	for (int i = 0; i < row3 * col3; i++) {

		if (m == 0) { // ������� 0 ���������� �������� ����������������
			start_x = 0;
			start_y = 0;
			if (last_digit <= i && i < last_digit + border_x)
				mx3[start_y][i - (last_digit - m)] = i;

			if (last_digit + border_x <= i && i < last_digit + border_x + border_y - 1)
				mx3[i - (last_digit + border_x - 1 - m)][border_x - 1 + m] = i;

			if (last_digit + border_x + border_y - 1 <= i && i < last_digit + 2 * (border_x - 1) + border_y)
				mx3[border_y - 1 + m][last_digit + 2 * (border_x - 1) + border_y - 1 + m - i] = i;

			if (last_digit + 2 * (border_x - 1) + border_y <= i && i < last_digit + 2 * (border_x + border_y - 2))
				mx3[last_digit + 2 * (border_y + border_x - 2) + m - i][start_x] = i;

			if (i == last_digit + 2 * (border_x + border_y - 2)) {
				m = 1;
				start_x = m;
				start_y = m;
				last_digit = last_digit + 2 * (border_x + border_y - 2);
				border_x = col3 - 2*m;
				border_y = row3 - 2*m;
			}
				
		}
		
		if (m == 1) { // ������� 1 ���������� ���������������� ������ ���������������� ������ 0
			

			if ( last_digit <= i && i < last_digit + border_x)
				mx3[start_y][i - (last_digit - m)] = i;

			if (last_digit + border_x <= i && i < last_digit + border_x + border_y - 1)
				mx3[i - (last_digit + border_x - 1 - m)][border_x - 1 + m] = i;

			if (last_digit + border_x + border_y - 1 <= i && i < last_digit + 2 * (border_x - 1) + border_y)
				mx3[border_y - 1 + m][(last_digit + 2 * (border_x - 1) + border_y - 1 + m) - i] = i;

			if (last_digit + 2 * (border_x - 1) + border_y <= i && i < last_digit + 2 * (border_x + border_y - 2))
				mx3[last_digit + 2 * (border_y + border_x - 2) + m - i][start_x] = i;

			if (i == last_digit + 2 * (border_x + border_y - 2)) {
				m = 2;
				start_x = m;
				start_y = m;
				last_digit = last_digit + 2 * (border_x + border_y - 2);
				border_x = col3 - 2 * m;
				border_y = row3 - 2 * m;
			}
		}
		
		
		if (m == 2) { // ������� 2 ���������� ���������������� ������ ���������������� ������ 1

			if (last_digit <= i && i < last_digit + border_x)
				mx3[start_y][i - (last_digit - m)] = i;

			if (last_digit + border_x <= i && i < last_digit + border_x + border_y - 1)
				mx3[i - (last_digit + border_x - 1 - m)][border_x - 1 + m] = i;

			if (last_digit + border_x + border_y - 1 <= i && i < last_digit + 2 * (border_x - 1) + border_y)
				mx3[border_y - 1 + m][(last_digit + 2 * (border_x - 1) + border_y - 1 + m) - i] = i;

			if (last_digit + 2 * (border_x - 1) + border_y <= i && i < last_digit + 2 * (border_x + border_y - 2))
				mx3[last_digit + 2 * (border_y + border_x - 2) + m - i][start_x] = i;

			if (i == last_digit + 2 * (border_x + border_y - 2)) {
				m = 3;
				start_x = m;
				start_y = m;
				last_digit = last_digit + 2 * (border_x + border_y - 2);
				border_x = col3 - 2 * m;
				border_y = row3 - 2 * m;
			}

		}		

	}



	std::cout << '\n';

	for (int i = 0; i < row3; i++) {
		for (int j = 0; j < col3; j++) {
			std::cout << '\t' << mx3[i][j];
		}
		std::cout << std::endl;
	}


	return 0;
}