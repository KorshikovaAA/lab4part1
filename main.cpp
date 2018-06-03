#include <iostream>
#include <fstream>
#include <cassert>
#include <iomanip>
using namespace std;
char nibble_to_hex(uint8_t i) {
    assert(0x0 <= i && i <= 0xf);
    char digits[] = "0123456789abcdef";
    return digits[i];
}
void
print_in_hex(uint8_t byte) {
    cout << nibble_to_hex(byte >> 4);
    cout << nibble_to_hex(byte & 0b00001111);
}
const uint8_t*
as_bytes(const void* data) {
    return reinterpret_cast<const uint8_t*>(data);
}
void
print_in_hex(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_hex(bytes[i]);
        if ((i + 1) % 16 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
char
bit_digit(uint8_t byte, uint8_t bit) {
    if (byte & (0x1 << bit)) {
        return '1';
    }
    return '0';
}
void
print_in_binary(uint8_t byte) {
    for (uint8_t bit = 7; bit > 0; bit--) {
        cout << bit_digit(byte, bit);
    }
    cout << bit_digit (byte, 0);
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct student{
    char name[17];
    uint16_t year;
    float sred_ball;
    uint8_t sex;
    int classes;
    student*starosta;
};
int
main() {
    /*assert(nibble_to_hex(0x0) == '0');
    assert(nibble_to_hex(0x1) == '1');
    assert(nibble_to_hex(0x2) == '2');
    assert(nibble_to_hex(0x3) == '3');
    assert(nibble_to_hex(0x4) == '4');
    assert(nibble_to_hex(0x5) == '5');
    assert(nibble_to_hex(0x6) == '6');
    assert(nibble_to_hex(0x7) == '7');
    assert(nibble_to_hex(0x8) == '8');
    assert(nibble_to_hex(0x9) == '9');
    assert(nibble_to_hex(0xa) == 'a');
    assert(nibble_to_hex(0xb) == 'b');
    assert(nibble_to_hex(0xc) == 'c');
    assert(nibble_to_hex(0xd) == 'd');
    assert(nibble_to_hex(0xe) == 'e');
    assert(nibble_to_hex(0xf) == 'f');
     uint32_t u32 = 0x42;
     cout << "u32 bytes: ";
     print_in_hex(&u32, sizeof(u32));
     cout << '\n';
     uint8_t u8=3;
     print_in_binary(&u8, sizeof (u8));

     uint16_t operator_1, operator_2, res;
     char operator_0;
	 cout << "Vvedite operatori:\n";
     cin >>operator_1>>operator_0>>operator_2;
     switch (operator_0){
	 case '&':
         res=operator_1&operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
                cout << '&';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '\n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '&';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
		 break;
	 case '|':
         res=operator_1|operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
         cout << '|';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '\n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '|';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
		 break;
     case '^':
         res=operator_1^operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
         cout << '^';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '\n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '^';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
		 break;
     }

    student students[3] = {
            {
                    "Tema", 2017, 4.1, 0, 7, nullptr
            },
            {
                    "Kristina", 2017, 4.2, 0, 7, &students[0]
            },
            {
                    "Masha", 2017, 4.3, 0, 7, &students[0]
            }
    };
    cout << "\nAdress of array: " << &students << '\n';
    cout << "Size of array: " << sizeof(students) << '\n';
    cout << "el."<<"\tAdress of element:" << "\t Size of element:\n";
    for (int i = 0; i < 3; i++) {
        cout << i << '\t' << &students[i] << "\t\t\t" << sizeof(students[i]) << "\n";
    }
    cout << "For first element of array:\n";
    cout << "\t\tAddress of field:" << "\t size of filed:" << "\t\toffset:\n";
    cout << "Name:    \t" << &students[0].name << "\t\t\t";
    cout << sizeof(students[0].name) << "\t\t" << offsetof(struct student, name);
    cout << '\n';

    cout << "Year:    \t" << &students[0].year << "\t\t\t";
    cout << sizeof(students[0].year) << "\t\t" << offsetof(struct student, year);
    cout << '\n';

    cout << "Sred_ball:\t" << &students[0].sred_ball << "\t\t\t";
    cout << sizeof(students[0].sred_ball) << "\t\t"<< offsetof(struct student, sred_ball);
    cout << '\n';

    cout << "Classes:\t" << &students[0].classes << "\t\t\t";
    cout << sizeof(students[0].classes) << "\t\t" << offsetof(struct student, classes);
    cout << '\n';

    cout << "Starosta: \t" << &students[0].starosta << "\t\t\t";
    cout << sizeof(students[0].starosta) << "\t\t"<< offsetof(struct student, starosta);
    cout << "\n";

    cout << "\n\n\n";
    cout << "Name:\n";
    cout << "Binary\n";
    print_in_binary(&students[0].name, sizeof(students[0].name));
    cout << "\nHex:\n";
    print_in_hex(&students[0].name, sizeof(students[0].name));
    cout << "\n";

    cout << "\n\n\n";
    cout << "Year:\n";
    cout << "Binary:\n";
    print_in_binary(&students[0].year, sizeof(students[0].year));
    cout << "\nHex:\n";
    print_in_hex(&students[0].year, sizeof(students[0].year));
    cout << "\n\n\n";

    cout << "Sred_ball:\n";
    cout << "Binary:\n";
    print_in_binary(&students[0].sred_ball, sizeof(students[0].sred_ball));
    cout << "\nHex:\n";
    print_in_hex(&students[0].sred_ball, sizeof(students[0].sred_ball));
    cout << "\n\n\n";

    cout << "Classes:\n";
    cout << "Binary:\n";
    print_in_binary(&students[0].classes, sizeof(students[0].classes));
    cout << "\nHex:\n";
    print_in_hex(&students[0].classes, sizeof(students[0].classes));
    cout << "\n\n\n";

    cout << "Starosta:\n";
    cout << "Binary:\n";
    print_in_binary(&students[0].starosta, sizeof(students[0].starosta));
    cout << "\nHex:\n";
    print_in_hex(&students[0].starosta, sizeof(students[0].starosta));
    cout << "\n\n\n";
*/
    const size_t MAX_SIZE = 256;
    const char* separators = " \r\n,.!?:;()-";
    char text[MAX_SIZE];
    cout << "Vvedite nazvanie faila : ";
    cin >> text;
    if ((strchr(text, '*') != 0) || (strchr(text, '"') != 0) ||
        (strchr(text, '<') != 0) || (strchr(text, '>') != 0) ||
        (strchr(text, '?') != 0) || (strchr(text, '|') != 0)) {
        cout << "Error, nedopustimie simvoli v imeni faila";
        return 1;
    }
    if ((strchr(text, ':') != 0) &&
        (!(((strchr(text, ':') - text + 1) == 2) &&
           (((strchr(text, '\\') - text + 1) == 3) ||
            isalpha(1) != 0)))) {
        cout << "Error, necorrectnoe imya faila";
        return 1;
    }
    char* last_point = strrchr(text, '.');

    if (last_point != 0) {
        if (strcoll(last_point, ".rtf") != 0) {
            strcat(text, ".rtf");
        }
    }
    else {
        strcat(text, ".rtf");
    }
    ifstream ifs(text);
    int FILE_LENGTH = 0;
    if (ifs) {
        ifs.seekg(0, ifs.end);
        FILE_LENGTH = ifs.tellg();
        ifs.seekg(0, ifs.beg);
        char* file_content = new char[FILE_LENGTH];
        ifs.read(file_content, FILE_LENGTH);
        ifs.close();

        cout << "Enter a string to search for (up to 255 characters):" << endl;
        char search_str[256];
        cin >> search_str;
        int count = 0;
        const char* tmp = file_content;
        while (tmp = strstr(tmp, search_str)) {
            count++;
            tmp++;
        }
        cout << "The string \"" << search_str << "\" occures in the file " << text << " " << count << " times." << endl;
        delete[] file_content;
        delete[] tmp;
    }
    delete[] last_point;
    return 0;
}