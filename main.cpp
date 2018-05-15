#include <iostream>
#include <cassert>
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

        // Для удобства чтения: пробелы между байтам, по 16 байт на строку.
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
        cout << bit_digit (byte, bit);
        cout << bit_digit (byte, 0);
    }
}
void
print_in_binary(const void* data, size_t size) {
    const uint8_t* bytes = as_bytes(data);
    for (size_t i = 0; i < size; i++) {
        print_in_binary(bytes[i]);

        // Для удобства чтения: пробелы между байтами, по 4 байта на строку.
        if ((i + 1) % 4 == 0) {
            cout << '\n';
        }
        else {
            cout << ' ';
        }
    }
}
struct Student{
    char name[17];
    uint16_t year;
    float sred_ball;
    uint8_t sex:1;
    int classes;
    Student*starosta;
};
int
main() {
    /*
    assert(nibble_to_hex(0x0) == '0');
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


     cin >>operator_1>>operator_0>>operator_2;
     if (operator_0== '&'){
         res=operator_1&operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
                cout << '&';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '/n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '&';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
     }
     if (operator_0== '|'){
         res=operator_1|operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
         cout << '|';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '/n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '|';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
     }
     if (operator_0== '^'){
         res=operator_1|operator_2;
         print_in_hex(&operator_1,sizeof(uint16_t));
         cout << '^';
         print_in_hex(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_hex(&res,sizeof(uint16_t));
         cout << '/n';
         print_in_binary(&operator_1,sizeof(uint16_t));
         cout << '^';
         print_in_binary(&operator_2,sizeof(uint16_t));
         cout << '=';
         print_in_binary(&res,sizeof(uint16_t));
     }
    */

    Student students[3] = {
            {
                    "Fam1", 2017, 4.1, 0, 7, nullptr
            },
            {
                    "Fam2", 2017, 4.2, 1, 7, &students[0]
            },
            {
                    "Fam3", 2017, 4.3, 0, 7, &students[0]
            }
    };
    cout << "Adress of array:" << &students << '\n';
    cout << "Size of array:" << sizeof(students) << '\n';
    cout << "\tAdress of element:" << "\t Size of element:\n";
    for (int i = 0; i < 3; i++) {
        cout << i << '\t' << &students[i] << "\t\t" << sizeof(students[i]);
        cout << '\n';
    }
    cout<<"For first element of array:\n";
    cout << "\tAddress of field:"<<"\tsize of filed:"<< "\toffset:\n";
    cout << "Name:\t"<<&students[0].name<<"\t";
    cout << sizeof(students[0].name)<<"\t"<<offsetof(struct Student, name);
    cout <<'\n';

    cout << "Year:\t"<<&students[0].year<<"\t";
    cout << sizeof(students[0].year)<<"\t"<<offsetof(struct Student, year);
    cout <<'\n';

    cout << "Sred_ball:\t"<<&students[0].sred_ball<<"\t";
    cout << sizeof(students[0].sred_ball)<<"\t"<<offsetof(struct Student, sred_ball);
    cout <<'\n';

    /*cout << "Sex:\t"<<&students[0].sex<<"\t";
    cout << sizeof(students[0].sex)<<"\t"<<offsetof(struct Student, sex);
    cout <<'\n';

    cout << "Classes:\t"<<&students[0].classes<<"\t";
    cout << sizeof(students[0].classes)<<"\t"<<offsetof(struct Student, classes);
    cout <<'\n';
     */

    return 0;
}