#include <gtest/gtest.h>

TEST(PunterosTest, 01) {
    int *numero;

    // reservar memoria 

    // asignar el valor 2 a la posición reservada
   
    EXPECT_EQ(2, *numero);

    // liberar memoria y asignar puntero a nullptr
    
    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 02) {
    int *numero = new int(2);

    // sumar 3 a la posición reservada a la que apunta "numero"

    EXPECT_EQ(5, *numero);

    // liberar memoria y asignar puntero a nullptr 
    
    EXPECT_EQ(nullptr, numero);
}

TEST(PunterosTest, 03) {
    int numero = 2;
    int *puntero_a_numero;

    // hacer que puntero_a_numero apunte a la variable numero

    EXPECT_EQ(2, *puntero_a_numero);
}


// no está permitido reservar memoria nueva para alias_de_numero
TEST(PunterosTest, 04) {
    int *numero = new int;
    int *alias_de_numero;
    *numero = 2;

    // implementar

    EXPECT_EQ(numero, alias_de_numero);
    EXPECT_EQ(2, *alias_de_numero);

    delete alias_de_numero;
    alias_de_numero = nullptr;
    EXPECT_EQ(nullptr, alias_de_numero);
}
