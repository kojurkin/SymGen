#include <iostream>
#include <fstream>

int randRange(int min, int max)
{
    max = max - min;
    return rand() % max + min;
}

char randomDigit()
{
    return randRange(48, 57);
}

char randomSymbol()
{
    return randRange(97, 122);
}

int main()
{
    srand(time(0));
    int currentNumberLength, currentSymbolLength, charcount;
    int testnumcount, length, count;
    std::cout << "Enter count of symbols" << std::endl;
    std::cin >> testnumcount;
    std::cout << "Enter length of nums" << std::endl;
    std::cin >> length;
    std::cout << "Enter count of nums" << std::endl;
    std::cin >> count;
    if((count * length + count - 1) > testnumcount)
    {
        std::cout << std::endl << "Error";
        return 0;
    }
    std::ofstream outtestfile ("test.txt");
    charcount = testnumcount - length;
    while (count > 1)
    {
        count -= 1;
        currentNumberLength = randRange(1, length - count);
        length -= currentNumberLength;
        for (int i = 0; i < currentNumberLength; i++)
        {
            outtestfile << randomDigit();
        }
        currentSymbolLength = randRange(1, charcount - count);
        charcount -= currentSymbolLength;
        for (int i = 0; i < currentSymbolLength; i++)
        {
            outtestfile << randomSymbol();
        }
    }
    for (int i = 0; i < length; i++)
    {
        outtestfile << randomDigit();
    }
    for (int i = 0; i < charcount; i++)
    {
        outtestfile << randomSymbol();
    }
    outtestfile.close();
    return 0;
}
// 500 50 3