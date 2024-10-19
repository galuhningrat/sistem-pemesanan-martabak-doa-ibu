#include <format>
#include <iostream>

int main()
{
    char ukuran{}, kotakSpesial{};
    std::string tambahan{};
    int harga{};
    std::cout << "\t\t\t\t=================================\n";
    std::cout << "\t\t\t\tSISTEM PEMESANAN MARTABAK DOA IBU\n";
    std::cout << "\t\t\t\t=================================\n";
    std::cout << "\nPilihan pesanan: \n";
    std::cout << "Martabak kecil (S) dengan harga Rp. 15.000\n";
    std::cout << "Martabak sedang (M) dengan harga Rp. 20.000\n";
    std::cout << "Martabak besar (L) dengan harga Rp. 25.000" << std::endl;
    std::cout << "Input pilihan pesanan Anda (S, M, atau, L)" << std::endl;
    std::cin >> ukuran;

    // menentukan harga berdasarkan pesanan yang dipilih
    switch (ukuran) {
        case 'S':
            case 's':
        harga = 15000;
        break;
        case 'M':
            case 'm':
        harga = 20000;
        break;
        case 'L':
            case 'l':
        harga = 25000;
        break;
        default:
            std::cout << "Pesanan yang Anda masukkan tidak valid!\n";
        return 1;
    }

    // menu tambahan
    std::cout << "Sekalian pisangnya kak? + Rp. 5.000 :), Mau yang ini? Input (P)\n";
    std::cout << "Atau kakak sukanya keju? + Rp. 4.000 :D Mau yang ini? Input (K)\n";
    std::cout << "Kakaknya suka dua-daunya yaaa? + Rp. 7.000 :D Mau yang Ini? input (PK)\n";
    std::cout << "Hmm.. engga deh. Input (N)\n";
    std::cout << "Input menu yang kakak mau di bawah sini yaa (P/K/PK/N)";
    std::cin >> tambahan;

    // tentukan harga dengan menu tambahan
    if (tambahan == "P" || tambahan == "p") {
        harga += 5000;
    } else if (tambahan == "K" || tambahan == "k") {
        harga += 4000;
    } else if (tambahan ==  "PK" || tambahan == "pk" || tambahan == "Pk" || tambahan == "pK") {
        harga += 7000;
    } else if (tambahan == "N" || tambahan == "n") {
        // nothing
    } else {
        std::cerr << "Pilihan menu yang Anda input tidak valid!\n";
        return 1;
    }

    // kotak spesial
    std::cout << "\nOh iya kak, kami juga menawarkan dengan kotak spesial + Rp. 1000 :) mau yang ini? (Y/N): ";
    std::cin >> kotakSpesial;

    // tambahan biaya kotak spesial
    if (kotakSpesial == 'Y' || kotakSpesial == 'y') {
        harga += 1000;
    }

    // output ringkasan pesanan using std::format (fitur c++20)
    std::cout << "\n=== Ringkasan Pesanan Martabak Doa Ibu ===\n";
    std::string ukuranStr = (ukuran == 'S' || ukuran == 's') ? "Kecil" :
                            (ukuran == 'M' || ukuran == 'm') ? "Sedang" : "Besar";

    std::string tambahanStr = (tambahan == "P" || tambahan == "p") ? "Pisang" :
                              (tambahan == "K" || tambahan == "k") ? "Keju" :
                              (tambahan == "PK" || tambahan == "pk" || tambahan == "pK") ? "Pisang dan Keju" : "Tidak ada tambahan";

   std::cout << std::format("Ukuran Martabak: {}\n", ukuranStr);
   std::cout << std::format("Tambahan: {}\n", tambahanStr);
   std::cout << std::format("Kotak Spesial: {}\n", (kotakSpesial == 'Y' || kotakSpesial == 'y') ? "Ya" : "Tidak");
   std::cout << std::format("Total Bayar: Rp. {}\n", harga);
    return 0;
}
