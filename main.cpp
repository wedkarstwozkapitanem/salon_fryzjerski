#include <iostream>
#include <vector>
#include <locale.h>
#include <string>

namespace salon_fryzerski {
class salon {
  private:
    struct dane {
        std::string oferta;
        int cena;
    } mojedane;
    std::vector<dane> cennik = {
        {"Strzyżenie męskie",30},
        {"Farbowanie końcówek (Hit sezonu!)",120},
        {"Utlenianie",150}
    };
    int moj_wybor;

    std::string jaka_oferta(int id) {
        return cennik[id].oferta;
    }
    std::string ile_kosztuje() {
        return moj_wybor <= cennik.size() && moj_wybor >= 1  ? "Wybrana oferta \"" + jaka_oferta(moj_wybor - 1) + "\"  u nas kosztuje " + std::to_string(cennik[moj_wybor - 1].cena) + " z³.\n Zapraszamy do skorzystania z oferty." : "Numer poza zakresem od 1 do " + std::to_string(cennik.size()) + " !!!";
    }
    std::string zamknij_program() {
    return "Błędne dane wejściowe";
    }
  public:
    void oferta() {
        std::cout << "Oferta naszego salonu fryzjerskiego \"u kapitana\" \n Cennik: \n";
        for(int i=0; i<cennik.size(); i++) std::cout << i + 1 << ". " << cennik[i].oferta << std::endl;
        return;
    }

    void wprowadz() {
        std::cout << std::endl;
        std::cout << "Wpisz numer oferty: ";
        std::cin >> moj_wybor;
        !std::cin.fail() ? std::cout << ile_kosztuje() : std::cout << zamknij_program();
        std::cout << std::endl << std::endl;
        return;
    }
};
}

int main() {
    setlocale(LC_CTYPE,"Polish");
    salon_fryzerski::salon moj_salon;
    moj_salon.oferta();
    moj_salon.wprowadz();
    return 0;
}
