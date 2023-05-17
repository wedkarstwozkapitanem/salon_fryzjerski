#include <iostream>
#include <vector>
#include <locale.h>
#include <string>
#include "src/salon_fryzjerski.cpp"


int main() {
    setlocale(LC_CTYPE,"Polish");
    salon_fryzerski::salon moj_salon;
    moj_salon.oferta();
    moj_salon.wprowadz();
    return 0;
}
