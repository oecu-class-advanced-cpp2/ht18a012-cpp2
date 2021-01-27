#include <iostream>
#include <string>
#include <sstream>

using namespace std;

namespace cpp2 {
	/* --------------------------------------------------------------------- */
	/*
	mcxi
	mcxi �L�@����͂���N���X�ł��B
	*/
	/* --------------------------------------------------------------------- */
	class mcxi {
	public:
		/* ----------------------------------------------------------------- */
		/*
		mcxi
		�w�肳�ꂽ���������͂��āA�I�u�W�F�N�g�����������܂��B
		�ȉ��̏ꍇ�ɂ͗�O���n�o����܂��B
		1. [2-9,m,c,x,i] �ȊO�̕������o�������ꍇ
		2. 2 ���������Đ��� (2-9) ���o�������ꍇ
		3. m, c, x, i �����̏����ŏo�����Ȃ������ꍇ
		�������A�Ⴆ�� mx �̂悤�ɁA����̕������X�L�b�v���鎖�͋��e
		����܂��B
		*/
		/* ----------------------------------------------------------------- */
		mcxi(const std::string& s) : value_(0) {

			char car1[4] = { 'm','c','x','i' };
			char car2[8] = { '2','3','4','5','6','7','8','9' };
			int num[4] = { 1000,100,10,1 };
			int result = 0;
			int sub = 1;

			for (auto pos = s.begin(); pos != s.end(); pos++) {
				for (int i = 0; i < 8; i++) {
					if (*pos == car1[i]) {
						result = result + (num[i] * sub);
						sub = 1;
					}
					else if (*pos == car2[i]) {
						sub = *pos - '0';
					}
				}
			}
			value_ = result;
		}


		/* ----------------------------------------------------------------- */
		/*
		operator+
		2 �̃I�u�W�F�N�g�̉��Z���ʂ��擾���܂��B
		*/
		/* ----------------------------------------------------------------- */

		mcxi operator+(const mcxi &rhs) {
			mcxi num = this->value_ + rhs.value_;
			return num;
		}

		mcxi(int value_) {
			this->value_ = value_;
		}

		/* ----------------------------------------------------------------- */
		/*
		to_string
		���݂̒l�� mcxi �L�@�ɕϊ����܂��B
		*/
		/* ----------------------------------------------------------------- */
		std::string to_string() const {
			std::stringstream ss;
			int value = value_;
			int i = 0;

			//m�̕����ϊ�
			i = value / 1000;
			if (i == 1) ss << 'm';
			if (i > 1) {
				ss << i;
				ss << 'm';
			}
			//c�̕����ϊ�
			i = value % 1000;
			i = i / 100;
			if (i == 1) ss << 'c';
			if (i > 1) {
				ss << i;
				ss << 'c';
			}
			//x�̕����ϊ�
			i = value % 100;
			i = i / 10;
			if (i == 1) ss << 'x';
			if (i > 1) {
				ss << i;
				ss << 'x';
			}
			//i�̕����ϊ�
			i = value % 10;
			if (i == 1) ss << 'i';
			if (i > 1) {
				ss << i;
				ss << 'i';
			}
			return ss.str();
		}
	private:
		int unit(char c) {
			if (c == 'm')return 1000;
			if (c == 'c')return 100;
			if (c == 'x')return 10;
			if (c == 'i')return 1;
		}

	private:
		int value_;
	};
}

int main() {
	cpp2::mcxi a0("xi");
	cpp2::mcxi b0("x9i");
	auto result0 = a0 + b0;
	std::cout << "�� " << "3x" << "      /�� " << result0.to_string() << std::endl;

	cpp2::mcxi a1("i");
	cpp2::mcxi b1("9i");
	auto result1 = a1 + b1;
	std::cout << "�� " << "x" << "       /�� " << result1.to_string() << std::endl;

	cpp2::mcxi a2("c2x2i"); //122
	cpp2::mcxi b2("4c8x8i");//488
	auto result2 = a2 + b2; //610
	std::cout << "�� " << "6cx" << "     /�� " << result2.to_string() << std::endl;

	cpp2::mcxi a3("m2ci");
	cpp2::mcxi b3("4m7c9x8i");
	auto result3 = a3 + b3;
	std::cout << "�� " << "5m9c9x9i" << "/�� " << result3.to_string() << std::endl;

	cpp2::mcxi a4("9c9x9i");
	cpp2::mcxi b4("i");
	auto result4 = a4 + b4;
	std::cout << "�� " << "m" << "       /�� " << result4.to_string() << std::endl;

	cpp2::mcxi a5("i");
	cpp2::mcxi b5("9m9c9x8i");
	auto result5 = a5 + b5;
	std::cout << "�� " << "9m9c9x9i" << "/�� " << result5.to_string() << std::endl;

	cpp2::mcxi a6("m");
	cpp2::mcxi b6("i");
	auto result6 = a6 + b6;
	std::cout << "�� " << "mi" << "      /�� " << result6.to_string() << std::endl;

	cpp2::mcxi a7("i");
	cpp2::mcxi b7("m");
	auto result7 = a7 + b7;
	std::cout << "�� " << "mi" << "      /�� " << result7.to_string() << std::endl;

	cpp2::mcxi a8("m9i");
	cpp2::mcxi b8("i");
	auto result8 = a8 + b8;
	std::cout << "�� " << "mx" << "      /�� " << result8.to_string() << std::endl;

	cpp2::mcxi a9("9m8c7xi");
	cpp2::mcxi b9("c2x8i");
	auto result9 = a9 + b9;
	std::cout << "�� " << "9m9c9x9i" << "/�� " << result9.to_string() << std::endl;

	std::cin.get();
	return 0;
}