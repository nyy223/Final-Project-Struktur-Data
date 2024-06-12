#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <limits>
#include <ctime>

using namespace std;

// Budget class
class Budget {
private:
    int nominal;
    string bulan;
    string kategoriBudget;

public:
    Budget() : nominal(0), bulan(""), kategoriBudget("") {} 

    Budget(int nominal, string bulan, string kategoriBudget)
        : nominal(nominal), bulan(bulan), kategoriBudget(kategoriBudget) {}

    void setBudget(int budget) {
        nominal = budget;
    }

    void deleteBudget() {
        nominal = 0;
    }

    void setNominal(int nominal) {
        this->nominal = nominal;
    }

    void setBulan(string bulan) {
        this->bulan = bulan;
    }

    void setKategoriBudget(string kategoriBudget) {
        this->kategoriBudget = kategoriBudget;
    }

    int getNominal() const {
        return nominal;
    }

    string getBulan() const {
        return bulan;
    }

    string getKategoriBudget() const {
        return kategoriBudget;
    }
};

// User class
class User {
private:
    string username;
    string password;
    string email;
    int saldo;

public:
    User(string username, string password, string email, int saldo)
        : username(username), password(password), email(email), saldo(saldo) {}

    void login() {
        cout << "User " << username << " logged in." << endl;
    }

    void logout() {
        cout << "User " << username << " logged out." << endl;
    }

    void registerUser() {
        cout << "User " << username << " registered." << endl;
    }

    void updateSaldo(int amount) {
        saldo += amount;
    }

    void setUsername(string username) {
        this->username = username;
    }

    void setPassword(string password) {
        this->password = password;
    }

    void setEmail(string email) {
        this->email = email;
    }

    void setSaldo(int saldo) {
        this->saldo = saldo;
    }

    string getUsername() const {
        return username;
    }

    string getPassword() const {
        return password;
    }

    string getEmail() const {
        return email;
    }

    int getSaldo() const {
        return saldo;
    }
};

// Transaksi class
// Transaksi class
class Transaksi {
private:
    string tanggal;  // Change to string for user-friendly date input
    int nominal;
    string tipe;
    string kategoriTransaksi;

public:
    Transaksi(string tanggal, int nominal, string tipe, string kategoriTransaksi)
        : tanggal(tanggal), nominal(nominal), tipe(tipe), kategoriTransaksi(kategoriTransaksi) {}

    void setTanggal(string tanggal) {
        this->tanggal = tanggal;
    }

    void setNominal(int nominal) {
        this->nominal = nominal;
    }

    void setTipe(string tipe) {
        this->tipe = tipe;
    }

    void setKategoriTransaksi(string kategoriTransaksi) {
        this->kategoriTransaksi = kategoriTransaksi;
    }

    string getTanggal() const {
        return tanggal;
    }

    int getNominal() const {
        return nominal;
    }

    string getTipe() const {
        return tipe;
    }

    string getKategoriTransaksi() const {
        return kategoriTransaksi;
    }
};

// Interface Laporan
class Laporan {
protected:
    string bulan;
    int nominal;
    string tipe;

public:
    Laporan(string bulan, string tipe) : bulan(bulan), nominal(0), tipe(tipe) {}

    virtual string tampilJenisLaporan() = 0;
    virtual void viewLaporan() = 0;
    virtual void createLaporan() = 0;

    void setBulan(string bulan) {
        this->bulan = bulan;
    }

    void setNominal(int nominal) {
        this->nominal = nominal;
    }

    void setTipe(string tipe) {
        this->tipe = tipe;
    }

    string getBulan() const {
        return bulan;
    }

    int getNominal() const {
        return nominal;
    }

    string getTipe() const {
        return tipe;
    }
};

// Pemasukan class
// Pemasukan class
class Pemasukan : public Laporan {
private:
    string sumberPemasukan;
    string tanggal;

public:
    Pemasukan(string bulan, int nominal, string sumberPemasukan, string tipe, string tanggal)
        : Laporan(bulan, tipe), sumberPemasukan(sumberPemasukan), tanggal(tanggal) {
        this->nominal = nominal;
    }

    string tampilJenisLaporan() override {
        return "Pemasukan";
    }

    void viewLaporan() override {
        cout << "Pemasukan - Bulan: " << bulan << ", Tanggal: " << tanggal << ", Nominal: " << nominal << ", Sumber: " << sumberPemasukan << ", Tipe: " << tipe << endl;
    }

    void createLaporan() override {
        // Implement create laporan logic
    }

    void setSumberPemasukan(string sumberPemasukan) {
        this->sumberPemasukan = sumberPemasukan;
    }

    string getSumberPemasukan() const {
        return sumberPemasukan;
    }

    string getTanggal() const {
        return tanggal;
    }
};

// Pengeluaran class
class Pengeluaran : public Laporan {
private:
    string alokasiPengeluaran;
    string tanggal;

public:
    Pengeluaran(string bulan, int nominal, string alokasiPengeluaran, string tipe, string tanggal)
        : Laporan(bulan, tipe), alokasiPengeluaran(alokasiPengeluaran), tanggal(tanggal) {
        this->nominal = nominal;
    }

    string tampilJenisLaporan() override {
        return "Pengeluaran";
    }

    void viewLaporan() override {
        cout << "Pengeluaran - Bulan: " << bulan << ", Tanggal: " << tanggal << ", Nominal: " << nominal << ", Alokasi: " << alokasiPengeluaran << ", Tipe: " << tipe << endl;
    }

    void createLaporan() override {
        // Implement create laporan logic
    }

    void setAlokasiPengeluaran(string alokasiPengeluaran) {
        this->alokasiPengeluaran = alokasiPengeluaran;
    }

    string getAlokasiPengeluaran() const {
        return alokasiPengeluaran;
    }

    string getTanggal() const {
        return tanggal;
    }
};

// AplikasiKeuangan class
class AplikasiKeuangan {
private:
    User user;
    vector<shared_ptr<Laporan>> laporanList;
    vector<Transaksi> transaksiList;
    map<string, int> bulanTotal;
    map<string, Budget> budgets;
    vector<string> kategoriTransaksi = {"makanan/minuman", "pakaian", "kebutuhan sehari-hari", "kendaraan", "lainnya"};

public:
    AplikasiKeuangan(User user) : user(user) {}

    void tambahPemasukan(string bulan, int nominal, string sumber, string tipe, string tanggal) {
        auto pemasukan = make_shared<Pemasukan>(bulan, nominal, sumber, tipe, tanggal);
        laporanList.push_back(pemasukan);
        bulanTotal[bulan] += nominal;
        user.updateSaldo(nominal);

        // Buat transaksi pemasukan
        Transaksi transaksi(tanggal, nominal, tipe, sumber);
        transaksiList.push_back(transaksi);
    }

    void tambahPengeluaran(string bulan, int nominal, string alokasi, string tipe, string tanggal) {
        auto pengeluaran = make_shared<Pengeluaran>(bulan, nominal, alokasi, tipe, tanggal);
        laporanList.push_back(pengeluaran);
        bulanTotal[bulan] -= nominal;
        user.updateSaldo(-nominal);

        // Buat transaksi pengeluaran
        Transaksi transaksi(tanggal, nominal, tipe, alokasi);
        transaksiList.push_back(transaksi);
    }

    void tampilkanLaporan() {
        bool adaPengeluaran = false;
        for (const auto& laporan : laporanList) {
            laporan->viewLaporan();
            if (laporan->tampilJenisLaporan() == "Pengeluaran") {
                adaPengeluaran = true;
            }
        }
        if (!adaPengeluaran) {
            cout << "Belum ada pengeluaran yang terjadi" << endl;
        }
    }

    void tampilkanSaldo() {
        cout << "Saldo saat ini: " << user.getSaldo() << endl;
    }

    void tampilkanLaporanBulanan(string bulan) {
        int totalPengeluaran = 0;
        bool adaPengeluaran = false;

        cout << "Laporan Bulan: " << bulan << endl;
        for (const auto& laporan : laporanList) {
            if (laporan->getBulan() == bulan) {
                laporan->viewLaporan();
                if (laporan->tampilJenisLaporan() == "Pengeluaran") {
                    totalPengeluaran += laporan->getNominal();
                    adaPengeluaran = true;
                }
            }
        }

        if (!adaPengeluaran) {
            cout << "Belum ada pengeluaran yang terjadi pada bulan " << bulan << endl;
        } else {
            cout << "Total Pengeluaran Bulan " << bulan << ": " << totalPengeluaran << endl;
        }

        cout << "Total: " << bulanTotal[bulan] << endl;
    }

    void setBudget(string bulan, string kategori, int nominal) {
        budgets[bulan + kategori] = Budget(nominal, bulan, kategori);
    }

    void tampilkanLaporanDenganBudget(string bulan) {
        map<string, int> pengeluaranBulanan;
        bool adaPengeluaran = false;

        for (const auto& laporan : laporanList) {
            if (laporan->getBulan() == bulan) {
                Pengeluaran* pengeluaran = dynamic_cast<Pengeluaran*>(laporan.get());
                if (pengeluaran) {
                    adaPengeluaran = true;
                    string key = pengeluaran->getBulan() + pengeluaran->getAlokasiPengeluaran();
                    pengeluaranBulanan[key] += pengeluaran->getNominal();
                }
            }
        }

        if (!adaPengeluaran) {
            cout << "Belum ada pengeluaran yang terjadi pada bulan " << bulan << endl;
            return;
        }

        for (const auto& pair : pengeluaranBulanan) {
            string key = pair.first;
            int totalPengeluaran = pair.second;

            if (budgets.find(key) != budgets.end()) {
                Budget budget = budgets[key];
                if (totalPengeluaran > budget.getNominal()) {
                    cout << "Besar pengeluaran pada kategori " << budget.getKategoriBudget() << ": " << totalPengeluaran << endl;
                    cout << "melebihi budget: " << budget.getNominal() << endl;
                } else {
                    cout << "Pengeluaran pada kategori " << budget.getKategoriBudget()
                         << " masih dalam batas budget: " << budget.getNominal() << endl;
                }
            } else {
                cout << "Tidak ada budget yang ditentukan untuk kategori " << key << "." << endl;
            }
        }
    }

    void tampilkanKategori() {
        cout << "Pilih kategori pengeluaran:\n";
        for (size_t i = 0; i < kategoriTransaksi.size(); ++i) {
            cout << i + 1 << ". " << kategoriTransaksi[i] << "\n";
        }
        cout << "Pilih opsi: ";
    }

    string pilihKategori() {
        int pilihan;
        tampilkanKategori();
        cin >> pilihan;

        while (pilihan < 1 || pilihan > kategoriTransaksi.size()) {
            cout << "Opsi tidak valid. Silakan pilih lagi.\n";
            tampilkanKategori();
            cin >> pilihan;
        }

        if (kategoriTransaksi[pilihan - 1] == "lainnya") {
            string kategoriBaru;
            cout << "Masukkan kategori pengeluaran baru: ";
            cin >> kategoriBaru;
            kategoriTransaksi.push_back(kategoriBaru);
            return kategoriBaru;
        }

        return kategoriTransaksi[pilihan - 1];
    }
};

// main function
// main function
int main() {
    string username, password, email;
    cout << "Selamat datang di Aplikasi Keuangan!" << endl;
    cout << "Silakan lakukan registrasi." << endl;
    cout << "Masukkan username: ";
    cin >> username;
    cout << "Masukkan password: ";
    cin >> password;
    cout << "Masukkan email: ";
    cin >> email;

    User user(username, password, email, 0);
    user.registerUser();
    user.login();

    AplikasiKeuangan app(user);

    int choice;
    do {
        cout << "\nMenu: \n";
        cout << "1. Tambah Pemasukan\n";
        cout << "2. Tambah Pengeluaran\n";
        cout << "3. Tampilkan Saldo\n";
        cout << "4. Tampilkan Laporan\n";
        cout << "5. Tampilkan Laporan Bulanan\n";
        cout << "6. Set Budget\n";
        cout << "7. Tampilkan Laporan dengan Budget\n";
        cout << "8. Logout dan Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        string bulan, sumber, alokasi, tipe, tanggal;
        int nominal;
        switch (choice) {
        case 1:
            cout << "Masukkan bulan pemasukan: ";
            cin >> bulan;
            cout << "Masukkan tanggal pemasukan (format YYYY-MM-DD): ";
            cin >> tanggal;
            cout << "Masukkan nominal pemasukan: ";
            while (!(cin >> nominal)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan nominal pemasukan (harus berupa angka): ";
            }
            cout << "Masukkan sumber pemasukan: ";
            cin >> sumber;
            cout << "Masukan tipe transaksi (cash/cashless): ";
            cin >> tipe;
            app.tambahPemasukan(bulan, nominal, sumber, tipe, tanggal);
            break;
        case 2:
            cout << "Masukkan bulan pengeluaran: ";
            cin >> bulan;
            cout << "Masukkan tanggal pengeluaran (format YYYY-MM-DD): ";
            cin >> tanggal;
            cout << "Masukkan nominal pengeluaran: ";
            while (!(cin >> nominal)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan nominal pengeluaran (harus berupa angka): ";
            }
            cout << "Masukan tipe transaksi (cash/cashless): ";
            cin >> tipe;
            alokasi = app.pilihKategori();
            app.tambahPengeluaran(bulan, nominal, alokasi, tipe, tanggal);
            break;
        case 3:
            app.tampilkanSaldo();
            break;
        case 4:
            app.tampilkanLaporan();
            break;
        case 5:
            cout << "Masukkan bulan laporan yang ingin ditampilkan: ";
            cin >> bulan;
            app.tampilkanLaporanBulanan(bulan);
            break;
        case 6:
            cout << "Masukkan bulan budget: ";
            cin >> bulan;
            sumber = app.pilihKategori();
            cout << "Masukkan nominal budget: ";
            while (!(cin >> nominal)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Masukkan nominal budget (harus berupa angka): ";
            }
            app.setBudget(bulan, sumber, nominal);
            break;
        case 7:
            cout << "Masukkan bulan laporan dengan budget yang ingin ditampilkan: ";
            cin >> bulan;
            app.tampilkanLaporanDenganBudget(bulan);
            break;
        case 8:
            user.logout();
            cout << "Terima kasih telah menggunakan aplikasi kami!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 8);

    return 0;
}
