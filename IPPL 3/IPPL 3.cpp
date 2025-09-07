#include <iostream>
#include <vector>
#include <cassert>

/// <summary>
/// Status hasil pengujian/validasi.
/// </summary>
/// <remarks>
/// Gunakan <see cref="Status::Success"/> untuk menandai skenario lulus/valid,
/// dan <see cref="Status::Failure"/> untuk menandai skenario gagal/tidak valid.
/// </remarks>
enum class Status {Success, Failure};

/// <summary>
/// 1) Teori Himpunan: mendemonstrasikan pengujian kombinasi fitur sebagai
/// anggota himpunan (subset) dari {A, B, C}.
/// </summary>
/// <param name="featureA">True bila Feature A diaktifkan.</param>
/// <param name="featureB">True bila Feature B diaktifkan.</param>
/// <param name="featureC">True bila Feature C diaktifkan.</param>
/// <remarks>
/// Fungsi ini sekadar menuliskan fitur mana yang diuji untuk setiap kombinasi.
/// </remarks>
/// <example>
/// testFeatureCombination(true, false, true)  // Menguji A dan C
/// </example>
void testFeatureCombination(bool featureA, bool featureB, bool featureC) {
    if (featureA) std::cout << "Testing Feature A\n";
    if (featureB) std::cout << "Testing Feature B\n";
    if (featureC) std::cout << "Testing Feature C\n";
    std::cout << "------\n";
}

/// <summary>
/// 2) Pengujian Kelas Equivalence: memproses bilangan bulat dan
/// mengembalikan status berdasarkan kelas nilai (negatif, nol, positif).
/// </summary>
/// <param name="value">Bilangan bulat yang akan diuji.</param>
/// <returns>
/// <see cref="Status::Failure"/> jika <paramref name="value"/> &lt; 0;
/// selain itu <see cref="Status::Success"/>.
/// </returns>
/// <remarks>
/// Kelas equivalence yang diuji: Negatif, Nol, dan Positif.
/// </remarks>
Status processValue(int value) {
    if (value < 0) return Status::Failure;
    if (value == 0) return Status::Success;
    return Status::Success;
}

/// <summary>
/// Kumpulan uji untuk <see cref="processValue"/> yang mencakup setiap kelas equivalence.
/// </summary>
/// <remarks>Gunakan <c>assert</c> untuk memverifikasi perilaku yang diharapkan.</remarks>
void testProcessValue() {
    // Kelas equivalence Negatif, Nol, Positif
    assert(processValue(-5) == Status::Failure);
    assert(processValue(0) == Status::Success);
    assert(processValue(10) == Status::Success);
    std::cout << "Semua tes kelas equivalence lulus!\n";
}

/// <summary>
/// 3) Pengujian Keterjangkauan/Cakupan (Coverage):
/// menjalankan cabang-cabang kondisi berdasarkan tanda dan paritas bilangan.
/// </summary>
/// <param name="x">Bilangan bulat yang akan diuji.</param>
/// <remarks>
/// Memastikan setiap jalur (positif/ganjil/genap dan non-positif) tersentuh.
/// </remarks>
void process(int x) {
    if (x > 0) {
        std::cout << "Bilangan Positif\n";
        if (x % 2 == 0) {
            std::cout << "Bilangan Genap\n";
        }
        else {
            std::cout << "Bilangan Ganjil\n";
        }
    }
    else {
        std::cout << "Bilangan Non-Positif\n";
    }
}

/// <summary>
/// 4) Pengujian Batasan (Boundary Value Analysis):
/// memeriksa apakah nilai berada pada rentang tertutup [1, 100].
/// </summary>
/// <param name="value">Bilangan bulat yang diuji.</param>
/// <returns>
/// <see cref="Status::Success"/> bila 1 &lt;= value &lt;= 100; jika di luar, <see cref="Status::Failure"/>.
/// </returns>
Status checkRange(int value) {
    if (value < 1 || value > 100) return Status::Failure;
    return Status::Success;
}

/// <summary>
/// Kumpulan uji batas bawah/atas dan kasus di luar batas untuk <see cref="checkRange"/>.
/// </summary>
void testCheckRange() {
    // Batas bawah dan atas
    assert(checkRange(1) == Status::Success);
    assert(checkRange(100) == Status::Success);

    // Di luar batas
    assert(checkRange(0) == Status::Failure);
    assert(checkRange(101) == Status::Failure);
    
    std::cout << "Semua uji batas lulus!\n";
}

/// <summary>
/// 5) Pengujian Kombinatorial (Pairing dua parameter).
/// Valid bila:
/// - a di dalam [0..10], dan
/// - (b == true =&gt; a genap) atau (b == false =&gt; a ganjil).
/// </summary>
/// <param name="a">Bilangan bulat (diharapkan 0..10).</param>
/// <param name="b">
/// Boolean yang mengekspresikan aturan paritas:
/// true =&gt; a harus genap; false =&gt; a harus ganjil.
/// </param>
/// <returns>
/// <see cref="Status::Success"/> jika kombinasi memenuhi aturan; jika tidak, <see cref="Status::Failure"/>.
/// </returns>
Status evaluateCombination(int a, bool b) {
    if (a < 0 || a > 10) return Status::Failure;
    if (b && a % 2 == 0) return Status::Success;
    if (!b && a % 2 != 0) return Status::Success;
    return Status::Failure;
}

/// <summary>
/// Kumpulan uji untuk validasi kombinasi pada <see cref="evaluateCombination"/>.
/// </summary>
/// <remarks>
/// Mencakup beberapa pasangan representatif (positif/negatif kasus).
/// </remarks>
void testEvaluationCombination() {
    // Kombinasi yang diuji
    assert(evaluateCombination(0, true) == Status::Success);  // a = 0, b = true
    assert(evaluateCombination(1, false) == Status::Success); // a = 1, b = false
    assert(evaluateCombination(2, false) == Status::Failure); // a = 2, b = false
    assert(evaluateCombination(3, true) == Status::Failure);  // a = 3, b = true

    std::cout << "Semua tes kombinatorial lulus!\n";
}

/// <summary>
/// 6) Pengujian Pengurutan: memeriksa apakah vektor terurut naik non-menurun.
/// </summary>
/// <param name="arr">Vektor bilangan bulat.</param>
/// <returns>True jika non-menurun (arr[i] &gt;= arr[i-1] untuk semua i), selain itu false.</returns>
/// <remarks>
/// Kompleksitas waktu O(n); tidak memodifikasi input.
/// </remarks>
bool isSorted(const std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}

/// <summary>
/// Kumpulan uji untuk <see cref="isSorted"/> dengan contoh terurut dan tidak terurut.
/// </summary>
void testIsSorted() {
    std::vector<int> sortedArray = { 1,2,3,4,5 };
    std::vector<int> unsortedArray = {5, 3, 1};
    
    assert(isSorted(sortedArray) == true); // Array sudah terurut
    assert(isSorted(unsortedArray) == false); // Array tidak terurut
    
    std::cout << "Semua tes yang diuji lulus!\n";
}

/// <summary>
/// 7) Klasifikasi bilangan (ilustrasi Diagram Venn):
/// mengembalikan label berdasarkan tanda (positif/negatif) dan paritas (genap/ganjil).
/// </summary>
/// <param name="value">Bilangan bulat.</param>
/// <returns>
/// Salah satu dari: "Positif dan Genap", "Positif dan Ganjil",
/// "Negatif dan Genap", "Negatif dan Ganjil", atau "Klasifikasi Tidak Dikenal".
/// </returns>
/// <remarks>
/// Nilai 0 tidak termasuk positif/negatif, sehingga dikembalikan "Klasifikasi Tidak Dikenal".
/// </remarks>
std::string classifyNumber(int value) {
    if (value > 0 && value % 2 == 0) {
        return "Positif dan Genap";
    }
    else if (value > 0 && value % 2 != 0) {
        return "Positif dan Ganjil";
    }
    else if (value < 0 && value % 2 == 0) {
        return "Negatif dan Genap";
    }
    else if (value < 0 && value % 2 != 0) {
        return "Negatif dan Ganjil";
    }

    return "Klasifikasi Tidak Dikenal";
 }

/// <summary>
/// Kumpulan uji untuk <see cref="classifyNumber"/> yang mencakup semua label utama.
/// </summary>
void testClassifyNumber() {
    std::vector<int> testValues = { 2, 1, -2, -1, 0 };
    std::vector<std::string> expectedResults = {
        "Positif dan Genap",
        "Positif dan Ganjil",
        "Negatif dan Genap",
        "Negatif dan Ganjil",
        "Klasifikasi Tidak Dikenal",
    };
    for (size_t i = 0; i < testValues.size(); ++i) {
        assert(classifyNumber(testValues[i]) == expectedResults[i]);
    }
    std::cout << "Semua tes klasifikasi lulus!\n";
}

/// <summary>
/// 8) Menghitung faktorial n (n!) secara iteratif.
/// </summary>
/// <param name="n">Bilangan bulat n &gt;= 0.</param>
/// <returns>n! dalam bentuk int.</returns>
/// <exception cref="std::invalid_argument">
/// Dilempar bila <paramref name="n"/> &lt; 0.
/// </exception>
/// <remarks>
/// Kompleksitas waktu O(n). Untuk n besar dapat terjadi overflow pada <c>int</c>.
/// </remarks>
int factorial(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input negatif tidak diperbolehkan");
    }
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/// <summary>
/// Kumpulan uji untuk <see cref="factorial"/> termasuk kasus tepi (0!, 1!) dan exception.
/// </summary>
void testFactorial() {
    assert(factorial(0) == 1);  // 0! = 1
    assert(factorial(1) == 1);  // 1! = 1
    assert(factorial(2) == 2);  // 2! = 2
    assert(factorial(3) == 6);  // 3! = 6
    assert(factorial(4) == 24); // 4! = 24

    try {
        factorial(-1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        // Ignored, really
    }

    std::cout << "Semua uji faktorial lulus!\n";
}

/// <summary>
/// 9) Menghitung bilangan Fibonacci ke-n secara iteratif.
/// </summary>
/// <param name="n">Indeks n &gt;= 0.</param>
/// <returns>Nilai F(n) dengan definisi F(0)=0, F(1)=1.</returns>
/// <exception cref="std::invalid_argument">
/// Dilempar bila <paramref name="n"/> &lt; 0.
/// </exception>
/// <remarks>
/// Kompleksitas waktu O(n), ruang O(1).
/// </remarks>
int fibonacci(int n) {
    if (n < 0) {
        throw std::invalid_argument("Input negatif tidak diperbolehkan!");
    }
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/// <summary>
/// Kumpulan uji untuk <see cref="fibonacci"/> termasuk exception untuk input negatif.
/// </summary>
void testFibonacci() {
    assert(fibonacci(0) == 0);
    assert(fibonacci(1) == 1);
    assert(fibonacci(2) == 1);
    assert(fibonacci(3) == 2);
    assert(fibonacci(4) == 3);
    assert(fibonacci(5) == 5);

    try {
        fibonacci(-1);
        assert(false);
    }
    catch (const std::invalid_argument&) {
        // Ignored, really
    }

    std::cout << "Semua uji Fibonacci lulus!\n";
}

/// <summary>
/// 10) Mengecek apakah bilangan prima menggunakan pendekatan 6k+/-1.
/// </summary>
/// <param name="n">Bilangan bulat.</param>
/// <returns>True jika prima; selain itu false.</returns>
/// <remarks>
/// Mengeliminasi kelipatan 2 dan 3, lalu memeriksa faktor hingga sqrt(n) dengan langkah 6.
/// Kompleksitas ~O(sqrt(n).
/// </remarks>
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

/// <summary>
/// Kumpulan uji untuk <see cref="isPrime"/> dengan contoh kecil representatif.
/// </summary>
void testIsPrime() {
    assert(isPrime(2) == true);
    assert(isPrime(3) == true);
    assert(isPrime(4) == false);
    assert(isPrime(5) == true);
    assert(isPrime(10) == false);
    assert(isPrime(13) == true);

    std::cout << "Semua uji prima lulus!\n";
}

/// <summary>
/// Titik masuk program yang menjalankan seluruh demonstrasi dan suite pengujian.
/// </summary>
/// <returns>Kode keluar proses (0 bila berhasil).</returns>
/// <remarks>
/// Bagian ini mengeksekusi tiap modul uji (1..10) dan menuliskan hasilnya ke stdout.
/// </remarks>
int main()
{
    std::cout << "1. Teori Himpunan\n";

    std::vector<std::vector<bool>> featureCombinations = {
        {true, true, false},
        {true, false, true},
        {false, true, true},
        {true, true, true}
    };

    for (const auto& combination : featureCombinations) {
        testFeatureCombination(combination[0], combination[1], combination[2]);
    }

    std::cout << "=======================\n";
    std::cout << "2. Pengujian Kelas Equivalence\n";

    testProcessValue();

    std::cout << "=======================\n";
    std::cout << "3. Pengujian Keterjangkauan\n";

    // Menguji semua jalur
    process(10);
    process(7);
    process(-5);

    std::cout << "=======================\n";
    std::cout << "4. Pengujian Batasan\n";

    testCheckRange();

    std::cout << "=======================\n";
    std::cout << "5. Pengujian Kombinatorial\n";

    testEvaluationCombination();

    std::cout << "=======================\n";
    std::cout << "6. Pengujian Pengurutan\n";

    testIsSorted();

    std::cout << "=======================\n";
    std::cout << "7. Diagram Venn\n";

    testClassifyNumber();

    std::cout << "=======================\n";
    std::cout << "8. Faktorial\n";

    testFactorial();

    std::cout << "=======================\n";
    std::cout << "9. Fibonacci\n";

    testFibonacci();

    std::cout << "=======================\n";
    std::cout << "10. Bilangan Prima\n";

    testIsPrime();

    return 0;
}