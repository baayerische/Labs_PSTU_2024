#include <iostream>
#include <string>
using namespace std;

string info(int year) {
    string n[] = {
        "Êðûñû", "Áûêà", "Òèãðà", "Êðîëèêà",
        "Äðàêîíà", "Çìåè", "Ëîøàäè", "Êîçû",
        "Îáåçüÿíû", "Ïåòóõà", "Ñîáàêè", "Ñâèíüè"
    };
    int i = (year - 2020) % 12;
    if (i < 0) i += 12;
    return "Ãîä " + n[i];
}

string info(string month) {
    if (month == "ßíâàðü" or month == "Ôåâðàëü") return "Âîäîëåé/Êîçåðîã";
    if (month == "Ìàðò" or month == "Àïðåëü") return "Îâåí/Ðûáû";
    if (month == "Ìàé" or month == "Èþíü") return "Áëèçíåöû/Òåëåö";
    if (month == "Èþëü" or month == "Àâãóñò") return "Ëåâ/Ðàê";
    if (month == "Ñåíòÿáðü" or month == "Îêòÿáðü") return "Äåâà";
    if (month == "Íîÿáðü" or month == "Äåêàáðü") return "Ñòðåëåö/Êîçåðîã/Ñêîðïèîí";
    return "Íåâåðíûé ìåñÿö";
}

int main() {
    setlocale(LC_ALL, "rus");
    cout << info(2006) << endl;
    cout << info("Ñåíòÿáðü") << endl;
    return 0;
}
