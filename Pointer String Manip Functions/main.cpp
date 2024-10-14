#include <iostream>

void Delete(char input[], int index1, int index2);
int Length(const char input[]);
int Pos(const char input[], char c);
void UpperCase(char input[]);
void Copy(char input[], int index1, int index2);

int Length(const char input[]) {
    int length = 0;

    while (input[length] != '\0') {
        length++;
    }

    return length;
}

int Pos(const char input[], char c) {
    int index = 0;

    while (input[index] != '\0') {
        if (input[index] == c) {
            return index;
        }
        index++;
    }

    std::cout << "Character not found" << std::endl;
    return -1;
}

void UpperCase(char input[]) {
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = input[i] - 32;
        }
    }
}

void LowerCase(char input[]) {
    for (size_t i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + 32;
        }
    }
}

void Copy(char input[], int index1, int index2) {
    if (index1 < 0 || index2 > Length(input) || index1 > index2) {
        std::cout << "Invalid index" << std::endl;
        exit(1);
    }

    int length = index2 - index1 + 1;
    char* result = new char[length];
    int index = 0;

    for (size_t i = index1; i <= index2; i++) {
        result[index] = input[i];
        index++;
    }

    result[index] = '\0';

    for (size_t j = 0; result[j] != '\0'; j++) {
        input[j] = result[j];
    }

    input[index] = '\0';

    delete[] result;
    result = nullptr;
}

void Delete(char input[], int index1, int index2) {
    int length = Length(input);

    if (index1 > index2 || index1 < 0 || index2 > length) {
        std::cout << "Invalid index" << std::endl;
        exit(1);
    }

    int newLength = index2 - index1 + 1;
    char* result = new char[newLength];
    int index = 0;

    for (size_t i = 0; i < length; i++) {
        if (i < index1 || i > index2) {
            result[index] = input[i];
            index++;
        }
    }

    result[index] = '\0';

    for (size_t j = 0; result[j] != '\0'; j++) {
        input[j] = result[j];
    }

    input[index] = '\0';

    delete[] result;
    result = nullptr;
}

int main() {
    char str[] = "Hello, World!";
    char* ptrStr = str;

    UpperCase(ptrStr);
    LowerCase(ptrStr);
    Copy(ptrStr, 7, 11);
    Delete(ptrStr, 0, 2);

    int ipos = Pos(ptrStr, 'c');

    std::cout << ptrStr << std::endl;
    std::cout << "position of character: " << ipos << std::endl;

    return 0;
}


