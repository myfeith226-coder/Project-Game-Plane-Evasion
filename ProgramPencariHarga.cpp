#include <iostream>
#include <string>
#include <limits>

using namespace std;

void screen() {
    
    cout << "================================================" << endl;
    cout << "| PROGRAM PENCARI HARGA BARANG TOKO AL BAROKAH |" << endl;
    cout << "================================================" << endl;
    cout << "Cari harga barang: " << endl;
    cout << "1. Sembako" << endl;
    cout << "2. Plastik" << endl;
    cout << "3. Sabun" << endl;
    cout << "4. Rokok" << endl;
    cout << "5. Obat" << endl;
};

class Sembako {
    private:
    string product[4];
    int price[4];
    int jumlah;

    public:
    Sembako() {
        product[0] = "beras";
        product[1] = "minyak";
        product[2] = "gula";
        product[3] = "telur";

        price[0] = 12000;
        price[1] = 18000;
        price[2] = 16000;
        price[3] = 8000;
        jumlah = 4;    
    }

    void cari(string keyword) {
        bool ditemukan = false;
        for(int i = 0; i < jumlah; i++) {
            if(product[i] == keyword) {
                cout << keyword << " = " << price[i] << endl;
                ditemukan = true;
                break; 
            }
        }
        if(!ditemukan) {
            cout << keyword << "tidak ditemukan!" << endl;
        }
    }

    void screen() {
        cout << "Daftar sembako toko Al Barokah:" << endl;
        cout << "1. Beras" << endl;
        cout << "2. Minyak" << endl;
        cout << "3. Gula" << endl;
        cout << "4. Telur" << endl;
    }
};

class Plastik {
    private:
    string product[3];
    int price[3];
    int jumlah;
    
    public:
    Plastik() {
        product[0] = "plastik 1/4";
        product[1] = "plastik 1/2";
        product[2] = "plastik 1 kg";

        price[0] = 2000;
        price[1] = 3000;
        price[2] = 4000;
        jumlah = 3;
    }

    void cari(string keyword) {
        bool ditemukan = false;
        for(int i = 0; i < jumlah; i++) {
            if(product[i] == keyword) {
                cout << keyword << " = " << price[i] << endl;
                ditemukan = true;
                break; 
            }
        }
        if(!ditemukan) {
            cout << keyword << "tidak ditemukan!" << endl;
        }
    }

    void screen() {
        cout << "Daftar plastik toko Al barokah: " << endl;
        cout << "1. Plastik 1/4" << endl;
        cout << "2. Plastik 1/2" << endl;
        cout << "3. Plastik 1 kg" << endl;
    }

};

class Rokok {
    private:
    string product[4];
    int price[4];
    int jumlah;

    public:
    Rokok() {
        product[0] = "surya";
        product[1] = "tabaco";
        product[2] = "inter";
        product[3] = "djarum super";

        price[0] = 26000;
        price[1] = 15000;
        price[2] = 22000;
        price[3] = 22000;
        jumlah = 4;
    }

    void cari(string keyword) {
        bool ditemukan = false;
        for(int i = 0; i < jumlah; i++) {
            if(product[i] == keyword) {
                cout << keyword << " = " << price[i] << endl;
                ditemukan = true;
                break; 
            }
        }
        if(!ditemukan) {
            cout << keyword << "tidak ditemukan!" << endl;
        }
    }

    void screen() {
        cout << "Daftar rokok toko Al Barokah: " << endl;
        cout << "1. Surya" << endl;
        cout << "2. Tabaco" << endl;
        cout << "3. Inter" << endl;
        cout << "4. Djarum Super" << endl;
    }

};

class Sabun {
    private:
    string product[4];
    int price[4];
    int jumlah;

    public:
    Sabun() {
        product[0] = "nuvo";
        product[1] = "giv";
        product[2] = "lifebuoy";
        product[3] = "shinzui";

        price[0] = 3000;
        price[1] = 3000;
        price[2] = 4000;
        price[3] = 4000;
        jumlah = 4;
    }

    void cari(string keyword) {
        bool ditemukan = false;
        for(int i = 0; i < jumlah; i++) {
            if(product[i] == keyword) {
                cout << keyword << " = " << price[i] << endl;
                ditemukan = true;
                break; 
            }
        }
        if(!ditemukan) {
            cout << keyword << "tidak ditemukan" << endl;
        }
    }

    void screen() {
        cout << "Daftar sabun toko Al Barokah: " << endl;
        cout << "1. Nuvo" << endl;
        cout << "2. Giv" << endl;
        cout << "3. Lifebuoy" << endl;
        cout << "4. Shinzui" << endl;
    }

};

class Obat {
    private:
    string product[4];
    int price[4];
    int jumlah;

    public:
    Obat() {
        product[0] = "paramex";
        product[1] = "oskadon";
        product[2] = "promag";
        product[3] = "bodrex";

        price[0] = 2500;
        price[1] = 2000;
        price[2] = 1000;
        price[3] = 1500;
        jumlah = 4;
    }

    void cari(string keyword) {
        bool ditemukan = false;
        for(int i = 0; i < jumlah; i++) {
            if(product[i] == keyword) {
                cout << keyword << " = " << price[i] << endl;
                ditemukan = true;
                break; 
            }
        }
        if(!ditemukan) {
            cout << keyword << "tidak ditemukan!" << endl;
        }
    }

    void screen() {
        cout << "Daftar obat toko Al Barokah: " << endl;
        cout << "1. Paramex" << endl;
        cout << "2. Oskadon" << endl;
        cout << "3. Promag" << endl;
        cout << "4. Bodrex" << endl;
    }

};

int main() {
    int pilihan;
    screen();

    cout << "Pilihan: ";
    cin >> pilihan;

    cout << endl;

    cout << "=====================================" << endl;

    
    switch(pilihan) {
        case 1: {
        Sembako sembako;
        string keyword;

        sembako.screen();

        cout << "Cari harga sembako: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(cin, keyword);

        for(char &c : keyword) {
            c = tolower(c);
        }

        sembako.cari(keyword);
        break;
        }

        case 2: {
        Plastik plastik;
        string keyword;

        plastik.screen();

        cout << "Cari harga Plastik: ";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(cin, keyword);

        for(char &c : keyword) {
            c = tolower(c);
        }

        plastik.cari(keyword);
        break;
        }

        case 3: {
            Sabun sabun;
            string keyword;

            sabun.screen();

            cout << "Cari harga sabun: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, keyword);

            for(char &c : keyword) {
            c = tolower(c);
            }

            sabun.cari(keyword);
            break;
        }

        case 4: {
        Rokok rokok;
        string keyword;

        rokok.screen();

        cout << "Cari harga rokok: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, keyword);

        for(char &c : keyword) {
            c = tolower(c);
        }

        rokok.cari(keyword);
        break;
        }

        case 5: {
        Obat obat;
        string keyword;

        obat.screen();

        cout << "Cari harga obat: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, keyword);

        for(char &c : keyword) {
            c = tolower(c);
        }

        obat.cari(keyword);
        break;
        }

        default:
        cout << "Error: input anda tidak valid!" << endl;
    }
    return 0;
}