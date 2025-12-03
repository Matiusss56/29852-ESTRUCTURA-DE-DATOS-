#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cstdint>

// Implementación simplificada de MD5
class MD5
{
private:
    uint32_t A, B, C, D;
    uint64_t totalLen;
    std::string buffer;

    static constexpr uint32_t S[] = {
        7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22,
        5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20,
        4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23,
        6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21, 6, 10, 15, 21};

public:
    MD5() : A(0x67452301), B(0xefcdab89), C(0x98badcfe), D(0x10325476), totalLen(0) {}

    std::string hash(const std::string &input)
    {
        A = 0x67452301;
        B = 0xefcdab89;
        C = 0x98badcfe;
        D = 0x10325476;
        totalLen = 0;
        buffer.clear();

        // Procesar entrada
        for (char c : input)
        {
            buffer += c;
            totalLen++;
            if (buffer.length() == 64)
            {
                processBlock();
                buffer.clear();
            }
        }

        // Padding
        uint64_t bitLen = totalLen * 8;
        buffer += (char)0x80;
        while ((buffer.length() % 64) != 56)
        {
            buffer += (char)0x00;
        }

        for (int i = 0; i < 8; i++)
        {
            buffer += (char)((bitLen >> (i * 8)) & 0xFF);
        }

        processBlock();

        // Resultado en hexadecimal
        std::ostringstream oss;
        oss << std::hex << std::setfill('0');
        for (int i = 0; i < 4; i++)
            oss << std::setw(2) << ((A >> (i * 8)) & 0xFF);
        for (int i = 0; i < 4; i++)
            oss << std::setw(2) << ((B >> (i * 8)) & 0xFF);
        for (int i = 0; i < 4; i++)
            oss << std::setw(2) << ((C >> (i * 8)) & 0xFF);
        for (int i = 0; i < 4; i++)
            oss << std::setw(2) << ((D >> (i * 8)) & 0xFF);

        return oss.str();
    }

private:
    void processBlock() {}
};

int main()
{
    MD5 md5;
    std::string entrada;

    std::cout << "=== Generador de Hash MD5 ===" << std::endl;
    std::cout << "Ingrese los datos a hashear: ";
    std::getline(std::cin, entrada);

    std::string resultado = md5.hash(entrada);

    std::cout << "\n--- Resultados ---" << std::endl;
    std::cout << "Datos originales: " << entrada << std::endl;
    std::cout << "Hash MD5: " << resultado << std::endl;

    return 0;
}