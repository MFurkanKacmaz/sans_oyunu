#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<string>
#include<Windows.h>
#include<iomanip>
#include<locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Turkish");
    srand(time(0));
    const int boyut = 60;
    unsigned int numPeople, sayac = 2;

    cout << "Kaç kişi yarışaçak?\n\n3 hatalı girişten sonra oyun sonlanacaktır.\n";
    cin >> numPeople;

    while (numPeople <= 1 && 0 <= sayac) {//Yarışmacıya 3 hatalı giriş hakkı tanıyan döngü
        if (0 < sayac) {
            cout << "HATALI GİRİŞ\n";
            cin >> numPeople;
        }
       
        if (0 == sayac) {
            cout << "Çok fazla hatalı giriş yaptınız.\nOYUN SONLANIYOR!!!";
            exit(EXIT_FAILURE);
        }
        --sayac;
    }
 
    cout << endl << endl;
    vector <string> kisiler;
    vector<bool>winlose;
    string a;

    for (unsigned int i = 0; i < numPeople; ++i) {

        cout << i + 1;
        cout << ". kisinin adini ve soyadini giriniz\n";

        if(0==i) getline(cin, a);// uygulama 1. kişinin adını almadan 2. kişiye geçtiği için 2 defa veri alındı.
        getline(cin, a);
        kisiler.push_back(a);
    }

    system("cls");

    int denemeSayisi = 0;

    vector <int> winNumAttPeo;
    vector<int> loseNumAttPeo;

    system("cls");

    for (unsigned int ks = 0; ks < numPeople; ++ks) {
        
        cout << ks+1 << ". yarismacimiz " << kisiler[ks];
        Sleep(2000);//oyunu 2 sn duraklatır.
        system("cls");

        cout << "Başlamak için bir harf girin : ";

        char x;
        cin >> x;

        system("cls");

        unsigned int pozisyon = boyut / 2;
        int eklenti, cikis = 0;

        while (0 == cikis) {

            eklenti = rand() % 3 - 1;
            cout << "|BASLANGIC|";

            for (int i = 0; i < boyut; ++i) {

                if (i == pozisyon) {
                    cout << x;
                }
                else {
                    cout << " ";
                }
            }

            cout << "|BITIS|";
            cout << endl;

            if (pozisyon == boyut) {
                cout << endl << "Yarışmayı başarıyla tamamladınız.\n\nKAZANDINIZ!!!";
                winlose.push_back(true);
                cikis = 1;
                winNumAttPeo.push_back(denemeSayisi);//"winNumAttPeo" dizisi, kazanan yarışmacıların kaç denemede yarışmayı bitirdiğini kaydeder.
                Sleep(2000);
            }

            else if (0 == pozisyon) {
                cout << endl << "Yarışmayı tamamlıyamadınız.\n\nKAYBETTİNİZ!!!";
                winlose.push_back(false);
                cikis = 1;
                loseNumAttPeo.push_back(denemeSayisi);//"loseNumAttPeo" dizisi, kaybeden yarışmacıların kaç denemede yarışmayı bitirdiğini kaydeder.
                Sleep(2000);
            }
            
            denemeSayisi++;
            pozisyon += eklenti;
        }
        system("cls");
    }

    vector<string>winners;
    vector<string>losers;

    cout << "\nKAZANANLAR\tDENEME SAYISI\n";
    int k = 0;
    for (unsigned int j = 0; j < numPeople; ++j) {//Kazananları ekrana yazdırır.
        if (1 == winlose[j]) {
            cout << setfill(' ') << setw(10) << kisiler[j] << " -> " << winNumAttPeo[k] << endl;
            winners.push_back(kisiler[j]);
            k++;
        }
    }

    cout << "\n\n";
    
    cout << "KAYBEDENLER\tDENEME SAYISI\n";
    k = 0;
    for (unsigned int j = 0; j < numPeople; ++j) {//Kaybedenleri ekrana yazdırır.
        if (0 == winlose[j]) {
            cout << setfill(' ') << setw(11) << kisiler[j] << " -> " << loseNumAttPeo[k] << endl;
            losers.push_back(kisiler[j]);
            k++;
        }
    }

    Sleep(5000);
    system("cls");

    int tutIndex = 0, minds, maxds, syc;

    cout << "* SAMPIYON *\n\n";
    Sleep(1500);

    if (winNumAttPeo.size() > 0) {//Eğer kazanan varsa
        
        minds = winNumAttPeo[0];
        
        for (syc = 0; syc < winNumAttPeo.size(); ++syc) {//Şampiyonun indexini bulur.
            if (winNumAttPeo[syc] < minds) {
                minds = winNumAttPeo[syc];
                tutIndex = syc;
            }
        }
        cout << winners[tutIndex] << "\n\n";//Şampiyonu yazdırır.
    }

    else if (loseNumAttPeo.size() > 0 && 0 == winNumAttPeo.size()) {//Eğer kazanan yoksa şampiyon kaybedenler arasından seçilir.
       
        maxds = loseNumAttPeo[0];
        tutIndex = 0;
        
        for (syc = 0; syc < loseNumAttPeo.size(); ++syc) {//Şampiyonun indexini bulur.
            
            if (loseNumAttPeo[syc] > maxds) {
                maxds = loseNumAttPeo[syc];
                tutIndex = syc;
            }
        }
        cout << losers[tutIndex] << "\n\n";//Şampiyonu yazdırır.
    }
    system("Pause");
    return 0;
}