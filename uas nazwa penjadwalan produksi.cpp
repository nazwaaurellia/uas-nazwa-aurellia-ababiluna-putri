#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct ProductionSchedule {
    std::string productName;
    int productionTime; // in hours
    int priority;       // lower value means higher priority
};

// Fungsi untuk mencetak jadwal produksi
void printSchedule(const std::vector<ProductionSchedule>& schedule) {
    std::cout << "\nJadwal Produksi:\n";
    std::cout << std::setw(15) << "Nama Produk"
              << std::setw(15) << "Waktu Produksi (jam)"
              << std::setw(10) << "Prioritas\n";
    std::cout << "--------------------------------------------------\n";
    for (const auto& item : schedule) {
        std::cout << std::setw(15) << item.productName
                  << std::setw(15) << item.productionTime
                  << std::setw(10) << item.priority << "\n";
    }
}

// Fungsi untuk mengatur jadwal berdasarkan prioritas
void sortScheduleByPriority(std::vector<ProductionSchedule>& schedule) {
    std::sort(schedule.begin(), schedule.end(), [](const ProductionSchedule& a, const ProductionSchedule& b) {
        return a.priority < b.priority;
    });
}

int main() {
    std::vector<ProductionSchedule> schedule;
    int numProducts;

    std::cout << "Masukkan jumlah produk yang akan dijadwalkan: ";
    std::cin >> numProducts;

    // Input data untuk setiap produk
    for (int i = 0; i < numProducts; ++i) {
        ProductionSchedule temp;
        std::cout << "\nMasukkan nama produk: ";
        std::cin >> temp.productName;
        std::cout << "Masukkan waktu produksi (jam): ";
        std::cin >> temp.productionTime;
        std::cout << "Masukkan prioritas (angka, lebih kecil lebih prioritas): ";
        std::cin >> temp.priority;
        schedule.push_back(temp);
    }

    // Sortir jadwal berdasarkan prioritas
    sortScheduleByPriority(schedule);

    // Cetak jadwal yang sudah diatur
    printSchedule(schedule);

    return 0;
}